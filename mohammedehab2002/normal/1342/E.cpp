#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
long long fact[200005],inv[200005];
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
long long nck(int n,int k)
{
	return (fact[n]*inv[k])%mod*inv[n-k]%mod;
}
int main()
{
	int n;
	long long k;
	scanf("%d%I64d",&n,&k);
	if (k>=n)
	{
		printf("0");
		return 0;
	}
	fact[0]=1;
	for (int i=1;i<=n;i++)
	fact[i]=(i*fact[i-1])%mod;
	inv[n]=pow_log(fact[n],mod-2);
	for (int i=n-1;i>=0;i--)
	inv[i]=((i+1)*inv[i+1])%mod;
	long long ans=0;
	for (int i=0;i<=n-k;i++)
	{
		long long tmp=nck(n-k,i)*pow_log(n-k-i,n)%mod;
		if (i%2)
		ans=(ans-tmp+mod)%mod;
		else
		ans=(ans+tmp)%mod;
	}
	ans=(ans*nck(n,k))%mod;
	if (k)
	ans=(ans*2)%mod;
	printf("%I64d",ans);
}