#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long mod=998244353;
long long n,k,dp[555][555],ddp[555][555],a[555],ans,K;
int main()
{
	cin>>n>>K;
	ddp[1][1]=2;
	for (long long i=2;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
		for (long long j=1;j<=n;j++)
		{
			for (long long k=1;k<=n;k++)
			{
				long long x=max(j,k+1);
				dp[x][k+1]+=ddp[j][k];
				if (dp[x][k+1]>=mod) dp[x][k+1]-=mod;
				dp[j][1]+=ddp[j][k];
				if (dp[j][1]>=mod) dp[j][1]-=mod;
			}
		}
		for (long long j=1;j<=n;j++)
		{
			for (long long k=1;k<=n;k++)
			{
				ddp[j][k]=dp[j][k];
			}
		}
	}
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<=n;j++)
		{
			a[i]=(a[i]+dp[i][j])%mod;
		}
	}
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<=n;j++)
		{
			if (i*j<K) ans=(ans+a[i]*a[j])%mod;
		}
	}
	cout<<ans*((mod+1)/2)%mod<<endl;
	return 0;
}