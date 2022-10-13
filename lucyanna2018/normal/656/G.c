#include<stdio.h>
int A[99],F,I,T,j,r,kitten;
int main(){
	char s[99];
	for(scanf("%d%d%d",&F,&I,&T);F--;){scanf("%s",s);for(j=0;j<I;j++)if(s[j]=='Y')A[j]++;}
	for(j=0;j<I;j++)if(A[j]>=T)r++;
	printf("%d\n",r);
	return 0;
}