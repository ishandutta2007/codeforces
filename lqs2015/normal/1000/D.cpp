#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=998244353;
long long c[2222][2222],n,a[1111],dp[1111];
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	c[0][0]=1;
	for (long long i=1;i<=n;i++)
	{
		c[i][0]=1;
		for (long long j=1;j<=i;j++)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	dp[0]=1;
	for (long long i=1;i<=n;i++)
	{
		dp[i]=1;
		for (long long j=i-1;j>=1;j--)
		{
			if (a[j]>0 && i-j+1>=a[j]+1)dp[i]=(dp[i]+dp[j-1]*c[i-j][a[j]])%mod;
		}
	}
	dp[n]--;
	if (dp[n]<0) dp[n]+=mod;
	printf("%I64d\n",dp[n]);
	return 0;
}