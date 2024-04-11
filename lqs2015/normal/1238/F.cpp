#include<bits/stdc++.h>
using namespace std;
int q,n,x,y,dp[333333],mx1,mx2,ans,cur;
vector<int> g[333333];
void dfs(int i,int fa)
{
	int cnt=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		++cnt;dfs(to,i);
	}
	mx1=mx2=1;dp[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dp[i]=max(dp[i],dp[to]+cnt);
		if (dp[to]>mx1)
		{
			mx2=mx1;
			mx1=dp[to];
		}
		else if (dp[to]>mx2) mx2=dp[to];
	}
	cur=mx1+mx2-1+cnt;
	if (fa) cur++;
	ans=max(ans,cur);
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}