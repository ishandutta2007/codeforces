#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=1e9+7;
long long n,m,k,dp[111][11111],jc[111],injc[111],c[111][111];
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
long long C(long long n,long long k)
{
	return (jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	dp[0][0]=1;
	jc[0]=injc[0]=1;
	for (long long i=1;i<=100;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		injc[i]=injc[i-1]*binpow(i,mod-2)%mod;
	}
	for (long long i=0;i<=n;i++)
	{
		for (long long j=1;j<=n;j++)
		c[i][j]=binpow(C(n,i),(m-j)/n+1);
	}
	for (long long i=1;i<=n;i++)
	{
		for (long long j=0;j<=k;j++)
		{
			for (long long h=0;h<=n;h++)
			{
				if (j>=h) dp[i][j]=(dp[i][j]+dp[i-1][j-h]*c[h][i])%mod;
			}
		}
	}
	printf("%I64d\n",dp[n][k]);
	return 0;
}