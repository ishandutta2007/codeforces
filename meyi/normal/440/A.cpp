#include<cstdio>
int a;
long long n;
main(){
	scanf("%lld",&n);
	n=n*(n+1)*0.5;
	while(~scanf("%d",&a))n-=a;
	printf("%lld\n",n);
}