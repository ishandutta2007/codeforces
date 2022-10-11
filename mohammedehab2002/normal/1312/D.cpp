#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MX 200000
long long fact[MX+5],inv[MX+5];
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
	int n,m;
	scanf("%d%d",&n,&m);
	fact[0]=1;
	for (int i=1;i<=MX;i++)
	fact[i]=(fact[i-1]*i)%mod;
	inv[MX]=pow_log(fact[MX],mod-2);
	for (int i=MX-1;i>=0;i--)
	inv[i]=(inv[i+1]*(i+1))%mod;
	printf("%I64d",fact[m]*inv[n-1]%mod*inv[m-n+1]%mod*pow_log(2,n-2)%mod*(n-2)%mod*inv[2]%mod);
}