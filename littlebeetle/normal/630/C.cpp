#include<cstdio>
int n,i;
long long s,p;
int main(){
	scanf("%d",&n);
	for(i=1,p=2;i<=n;i++,p*=2)
		s+=p;
	printf("%lld",s);
}