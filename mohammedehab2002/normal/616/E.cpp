#include <iostream>
using namespace std;
#define mod 1000000007
long long go(long long x)
{
	if (x%2)
	return ((x%mod)*(((x+1)/2)%mod))%mod;
	return (((x/2)%mod)*((x+1)%mod))%mod;
}
int main()
{
	long long n,m;
	scanf("%I64d%I64d",&n,&m);
	long long ans=0,t=n%mod;
	if (n<m)
	ans=(((m-n)%mod)*t)%mod,m=n;
	ans=(ans+(m%mod)*t)%mod;
	for (long long i=1;i<=m;i++)
	{
		long long x=n/(n/i);
		x=min(x,m);
		ans-=(((go(x)-go(i-1)+mod)%mod)*((n/i)%mod))%mod;
		ans=(ans+mod)%mod;
		i=x;
	}
	printf("%I64d",ans);
}