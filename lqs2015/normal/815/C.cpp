#include<iostream>
#include<cstdio>
using namespace std;
long long dp[5555][5555][2],sz[5555],pa[5555],b,c[5555],d[5555],n,x,y,ans;
int main()
{
	scanf("%I64d%I64d",&n,&b);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&c[i],&d[i]);
		if (i>=2) scanf("%I64d",&pa[i]); 
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n;j++) 
		dp[i][j][0]=dp[i][j][1]=1e18;
	}
	for (int i=1;i<=n;i++)
	{
		dp[i][0][0]=0;
		dp[i][1][1]=c[i]-d[i];
		dp[i][1][0]=c[i];
	}
	for (int i=1;i<=n;i++) sz[i]=1;
	for (int i=n;i>1;i--)
	{
		y=i;x=pa[i];
		for (int j=sz[x];j>=0;j--)
		{
			for (int k=sz[y];k>=0;k--)
			{
				dp[x][j+k][0]=min(dp[x][j+k][0],dp[y][k][0]+dp[x][j][0]);
				dp[x][j+k][1]=min(dp[x][j+k][1],min(dp[y][k][0],dp[y][k][1])+dp[x][j][1]);
			}
		}
		sz[x]+=sz[y];
	}
	while(ans<=n && min(dp[1][ans][0],dp[1][ans][1])<=b) ans++;
	printf("%I64d\n",ans-1);
	return 0;
}