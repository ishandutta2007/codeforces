#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=1e9+7;
long long n,k,dp[1111][1111][2][2],jc[2222],injc[2222],res[1111];
long long C(long long n,long long k)
{
	if (n<k) return 0;
	return (jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
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
int main()
{
	scanf("%I64d%I64d",&n,&k);
	jc[0]=injc[0]=1;
	for (long long i=1;i<=1000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		injc[i]=injc[i-1]*binpow(i,mod-2)%mod;
	}
	dp[0][0][0][0]=1;
	for (long long i=1;i<=n;i++)
	{
		for (long long j=0;j<=i;j++)
		{
			for (long long k=0;k<=1;k++)
			{
				for (long long h=0;h<=1;h++)
				{
					if (!h) dp[i][j][k][h]=(dp[i-1][j][0][k]+dp[i-1][j][1][k])%mod;
					if (j)
					{
						if (h) dp[i][j][k][h]=(dp[i][j][k][h]+dp[i-1][j-1][0][k]+dp[i-1][j-1][1][k])%mod;
						if (i-1 && !h) dp[i][j][k][h]=(dp[i][j][k][h]+dp[i-1][j-1][0][k])%mod;
					}
				}
			} 
		}
	}
	for (long long i=0;i<=n;i++)
	{
		res[i]=(dp[n][i][0][0]+dp[n][i][1][0])*jc[n-i]%mod;
	}
	for (long long i=n;i>=0;i--)
	{
		for (long long j=i+1;j<=n;j++)
		{
			res[i]=(res[i]-res[j]*C(j,i))%mod;
		}
	}
	printf("%I64d\n",(res[k]+mod)%mod);
	return 0;
}