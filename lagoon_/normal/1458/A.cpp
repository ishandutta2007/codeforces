#include<bits/stdc++.h>
#define re register
long long gcd(re long long a,re long long b){return b?gcd(b,a%b):a;}
long long a[200100],b[200100],as[200100];
int main()
{
	re int n,m;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	re long long g=0;
	for(re int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(re int i=2;i<=n;i++)g=gcd(g,a[i]-a[1]);
	for(re int i=1;i<=m;i++)
	{
		printf("%lld ",gcd(a[1]+b[i],g));
	}
}