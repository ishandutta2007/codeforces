#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;long long dp[2][10010],c,a[10100],b[10100],INF;
int main()
{
	scanf("%d%lld",&n,&c);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	memset(dp,127/3,sizeof(dp));INF=dp[0][0];dp[0][0]=0;
	long long ans=1ll<<60;
	for(int i=1;i<=n;i++)
	{
		int ok=i&1;
		for(int j=0;j<=i;j++)
		{
			dp[ok][j]=INF;
			if(j!=0)dp[ok][j]=min(dp[ok][j],dp[ok^1][j-1]+b[i]);
			dp[ok][j]=min(dp[ok][j],dp[ok^1][j]+a[i]+c*j);
			if(i==n)ans=min(ans,dp[ok][j]);
		}
	}
	printf("%lld",ans);return 0;
}
//DP dp[i][j]ijSiST