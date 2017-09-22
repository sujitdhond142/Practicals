#include<stdio.h>
#include<string.h>

struct mot
{
	char name[5];
	char binr[5]; 
}a[16], c[10];

struct pot
{
	char name[5];
	char binr[4];
}b[8], d[8];

struct st{
	char name[5];
	int val;
	char type;
}e[15];
int main()
{ 
	FILE *fp;
	char tan[5],tab[5],tbn[5],tbb[5];
	char ch1[5],ch2[5],ch3[5],ch4[5];
	fp=fopen("1.asm","r");		//this is the asm file which we have to convert to machine lang
	int i,j,flag=0;
	//Entering data in Machine Op-code Table
        strcpy(a[0].name,"LOAD");
	strcpy(a[0].binr,"0000");
	strcpy(a[1].name,"ADDb");
	strcpy(a[1].binr,"0001"); 
        strcpy(a[2].name,"MOVb");
	strcpy(a[2].binr,"0010");
        strcpy(a[3].name,"SUBb");
	strcpy(a[3].binr,"0011");
        strcpy(a[4].name,"JNCb");
	strcpy(a[4].binr,"0100");
	strcpy(a[5].name,"JNZb");
	strcpy(a[5].binr,"0101");
        strcpy(a[6].name,"CMPb");
	strcpy(a[6].binr,"0110");
        strcpy(a[7].name,"INCR");
	strcpy(a[7].binr,"0111");
        strcpy(a[8].name,"DECR");
        strcpy(a[8].binr,"1000");
	strcpy(a[9].name,"HIGH");
	strcpy(a[9].binr,"1001");
        strcpy(a[10].name,"LOWb");
	strcpy(a[10].binr,"1010");
        strcpy(a[11].name,"LESS");
	strcpy(a[11].binr,"1011");
        strcpy(a[12].name,"MORE");
	strcpy(a[12].binr,"1100");
        strcpy(a[13].name,"DECA");
	strcpy(a[13].binr,"1101");
        strcpy(a[14].name,"HEXA");
	strcpy(a[14].binr,"1110");
	strcpy(a[15].name,"MINb");
	strcpy(a[15].binr,"1111");

	//Entering data in Pseudo Op-code Table
	strcpy(b[0].name,"STRT");
	strcpy(b[0].binr,"000");
        strcpy(b[1].name,"USNG");
        strcpy(b[1].binr,"001");
        strcpy(b[2].name,"DCbb");
        strcpy(b[2].binr,"010");
        strcpy(b[3].name,"DSbb");
        strcpy(b[3].binr,"011");
        strcpy(b[4].name,"SSTO");
        strcpy(b[4].binr,"100");
        strcpy(b[5].name,"MSTO");
        strcpy(b[5].binr,"101");
        strcpy(b[6].name,"DATA");
        strcpy(b[6].binr,"110");
        strcpy(b[7].name,"ENDb");
        strcpy(b[7].binr,"111");

	printf("\tMachine Op-code Table");
	for(i=0; i<16; i++)
	{
		printf("\n  %s	-  %s",a[i].name,a[i].binr);
	}
	printf("\n\tPseudo Op-code Table");
	for(i=0; i<8; i++)
	{
		printf("\n  %s	-  %s",b[i].name,b[i].binr);
	}

	//Here we read data from file and store it in symbol table accordingly
	i=0;
	flag=0;
	while(fscanf(fp,"%s%s%s%s",ch1,ch2,ch3,ch4)!=EOF)
	{
//		printf("\n%s\t%s\t%s\t%s",ch1,ch2,ch3,ch4);
		if(strcmp(ch1,"**")!=0){
			strcpy(e[i].name,ch1);
			if((strcmp(ch2,"DCbb")==0)||(strcmp(ch2,"EQUb")==0)){
				printf("1");
				e[i].val=atoi(ch3);
				printf("2");
				e[i].type='A';
			}else{
				printf("3");
				e[i].val=flag;
				printf("4");
				e[i].type='R';
				printf("5");
			}
		i++;
		}
		flag+=4;
	}
	printf("\n\tSymbol Table");
	for(j=0;j<i;j++){
		printf("\n%s\t%d\t%c",e[j].name,e[j].val,e[j].type);
	}
	fclose(fp);
	return 0;

}
