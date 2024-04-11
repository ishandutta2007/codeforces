#include<stdio.h>
int a[16]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};
int c(int x){
	if(x==0)return 0;
	return c(x/16) + a[x%16];
}
int main(){
	int x;
	scanf("%d",&x);
	if(x==0)printf("1\n");else
		printf("%d\n",c(x));
	return 0;
}