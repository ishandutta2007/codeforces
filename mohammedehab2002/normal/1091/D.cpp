#include <iostream>
using namespace std;
#define mod 998244353
long long fact[1000005],inv[1000005];
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	fact[0]=1;
	for (int i=1;i<=n;i++)
	fact[i]=(i*fact[i-1])%mod;
	inv[n]=pow_log(fact[n],mod-2);
	for (int i=n-1;i>0;i--)
	inv[i]=(inv[i+1]*(i+1))%mod;
	long long ans=fact[n];
	for (int i=1;i<n-1;i++)
	{
		ans=(ans+fact[n])%mod;
		ans=(ans-((fact[n]*inv[n-i])%mod)+mod)%mod;
	}
	printf("%I64d",ans);
}