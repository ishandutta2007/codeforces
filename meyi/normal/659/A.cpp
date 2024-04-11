#include<cstdio>
int a,b,n;
main(){
	scanf("%d%d%d",&n,&a,&b);
	printf("%d",((a+b)%n+n-1)%n+1);
}