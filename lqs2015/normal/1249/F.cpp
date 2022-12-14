#include<bits/stdc++.h>
using namespace std;
int n,k,a[222],x,y,dp[222][222],arr[222],ans;
vector<int> g[222];
void dfs(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		for (int h=0;h<=k+1;h++) arr[h]=dp[i][h];
		for (int h=0;h<=k+1;h++)
		{
			for (int p=0;p<=k+1;p++)
			{
				if (h+p+1>k) dp[i][min(h,p+1)]=max(dp[i][min(h,p+1)],arr[h]+dp[to][p]);
			}
		}
	}
	dp[i][0]=dp[i][k+1]+a[i];
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=k;j++)
		{
			dp[i][j]=-1e9;
		}
		dp[i][k+1]=0;
	}
	dfs(1,0);
	for (int i=0;i<=k+1;i++) ans=max(ans,dp[1][i]);
	printf("%d\n",ans);
	return 0;
}