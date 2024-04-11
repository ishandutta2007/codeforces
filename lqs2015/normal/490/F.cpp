#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[6666][6666],n,a[6666],x,y,ans;
vector<int> g[6666];
pair<int,int> f[6666];
void dfs(int x,int y,int i,int fa)
{
	if (a[x]>a[i]) dp[x][y]=max(dp[x][y],dp[i][(int)g[i].size()]+1);
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (a[x]>a[i]) dp[x][y]=max(dp[x][y],dp[i][j]+1);
		dfs(x,y,to,i);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	for (int i=1;i<=n;i++) f[i]=make_pair(a[i],i);
	sort(f+1,f+n+1);
	for (int i=1;i<=n;i++)
	{
		x=f[i].second;
		dp[x][(int)g[x].size()]=1;
		for (int j=0;j<g[x].size();j++)
		{
			int to=g[x][j];
			dfs(x,j,to,x);
			ans=max(ans,dp[x][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}