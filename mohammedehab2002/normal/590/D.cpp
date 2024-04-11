#include <bits/stdc++.h>
using namespace std;
int dp[155][22505];
int a[155],c[155];
int main()
{
	int n,k,s,ans=1e9;
	scanf("%d%d%d",&n,&k,&s);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]),c[i]=a[i];
	sort(c+1,c+n+1);
	if (s>=k*(n-k))
	{
		int ans=0;
		for (int i=1;i<=k;i++)
		ans+=c[i];
		printf("%d",ans);
		return 0;
	}
	for (int i=0;i<=k;i++)
	{
		for (int j=0;j<=s;j++)
		dp[i][j]=1e9;
	}
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=min(i,k);j>0;j--)
		{
			for (int l=i-j;l<=s;l++)
			dp[j][l]=min(dp[j][l],dp[j-1][l-(i-j)]+a[i]);
		}
	}
	for (int i=0;i<=s;i++)
	ans=min(ans,dp[k][i]);
	printf("%d",ans);
}