#include<cstdio>
main(){
	int m,n;
	scanf("%d",&n),m=n&1;
	printf("I hate");
	while(--n)printf((n&1)==m?" that I hate":" that I love");
	printf(" it");
}