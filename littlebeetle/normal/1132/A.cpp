#include<cstdio>
int a,b,c,d;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==d&&(!c||(a>0)))
		printf("1");
	else
		printf("0");
}