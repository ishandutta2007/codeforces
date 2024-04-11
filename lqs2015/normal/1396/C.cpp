#include<bits/stdc++.h>
using namespace std;
int n,r1,r2,r3,d,p[1111111];
long long a[1111111],b[1111111],dp[1111111][3];
int main()
{
	scanf("%d%d%d%d%d",&n,&r1,&r2,&r3,&d);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
	{
		a[i]=1ll*p[i]*r1+r3;
		b[i]=min(min(1ll*p[i]*r1+r3,(long long)r2+r1),1ll*(p[i]+1)*r1+r1);
	} 
	for (int i=0;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=1e18;
	dp[0][2]=0;
	for (int i=0;i<n;i++)
	{
		if (i==n-1)
		{
			dp[i+1][1]=min(dp[i+1][1],dp[i][0]+2*d+b[i+1]);
			dp[i+1][0]=min(dp[i+1][0],dp[i][1]+2*d+b[i+1]);
			dp[i+1][2]=min(dp[i+1][2],dp[i][0]+d+a[i+1]);
			dp[i+1][2]=min(dp[i+1][2],dp[i][1]+d+a[i+1]);
			dp[i+1][2]=min(dp[i+1][2],dp[i][2]+d+a[i+1]);
		}
		else
		{
			dp[i+1][1]=min(dp[i+1][1],dp[i][0]+2*d+b[i+1]);
			dp[i+1][0]=min(dp[i+1][0],dp[i][1]+2*d+b[i+1]);
			dp[i+1][1]=min(dp[i+1][1],dp[i][2]+2*d+b[i+1]);
			dp[i+1][2]=min(dp[i+1][2],dp[i][0]+d+a[i+1]);
			dp[i+1][2]=min(dp[i+1][2],dp[i][1]+2*d+a[i+1]);
			dp[i+1][2]=min(dp[i+1][2],dp[i][2]+d+a[i+1]);
		}
	}
	printf("%lld\n",min(min(dp[n][0]-d,dp[n][1]),dp[n][2]-d));
	return 0;
}