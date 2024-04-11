#include<bits/stdc++.h>
using namespace std;
int test,n,m,a[3333],b[3333],c[3333],x,y,sub[3333],ans;
pair<int,long long> dp[3333][3333];
pair<int,long long> f[3333];
vector<int> g[3333];
void dfs(int i,int fa)
{
	sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to];
	}
	int cur=0;
	for (int j=0;j<=sub[i];j++) f[j]=make_pair(-1e9,-1e18);
	f[0]=make_pair(0,0);dp[i][0]=make_pair(0,0);
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		for (int k=0;k<=sub[to]+cur;k++) dp[i][k]=make_pair(-1e9,-1e18);
		for (int k=0;k<=sub[to];k++)
		{
			for (int h=0;h<=cur;h++)
			{
				dp[i][k+h]=max(dp[i][k+h],make_pair(f[h].first+dp[to][k].first,f[h].second+dp[to][k].second));
			}
		}
		cur+=sub[to];
		for (int k=0;k<=cur;k++) f[k]=dp[i][k];
	}
	for (int j=0;j<=cur;j++) dp[i][j].second+=c[i];
	for (int j=cur;j>=0;j--) 
	{
		if (dp[i][j].second>0) 
		{
			dp[i][j+1]=max(dp[i][j+1],make_pair(dp[i][j].first+1,0ll));
			if (j+1==m && i==1) ans=max(ans,dp[i][j].first+1);
		}
		else 
		{
			dp[i][j+1]=max(dp[i][j+1],make_pair(dp[i][j].first,0ll));
			if (j+1==m && i==1) ans=max(ans,dp[i][j].first);
		}
	}
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		for (int i=1;i<=n;i++) c[i]=b[i]-a[i];
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<=n;j++)
			{
				dp[i][j]=make_pair(-1e9,-1e18);
			}
		}
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		memset(sub,0,sizeof(sub));
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}