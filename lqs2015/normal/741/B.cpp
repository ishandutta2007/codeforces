#include<bits/stdc++.h>
using namespace std;
int n,m,w,b[1111],we[1111],x,y,sb,sw;
int dp[1111],ddp[1111];
bool used[1111];
vector<int> g[1111];
vector<pair<int,int> > v;
void dfs(int i)
{
	sb+=b[i];sw+=we[i];
	v.push_back(make_pair(b[i],we[i]));
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (!used[to]) dfs(to);
	} 
}
int main()
{
	scanf("%d%d%d",&n,&m,&w);
	for (int i=1;i<=n;i++) scanf("%d",&we[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	for (int i=1;i<=n;i++)
	{
		if (!used[i])
		{
			v.clear();sb=sw=0;
			dfs(i);
			v.push_back(make_pair(sb,sw)); 
			for (int j=0;j<=w;j++) ddp[j]=dp[j];
			for (int j=0;j<v.size();j++)
			{
				int x=v[j].first,y=v[j].second;
				for (int k=y;k<=w;k++)
				{
					dp[k]=max(dp[k],ddp[k-y]+x);
				}
			}
		}
	}
	printf("%d\n",dp[w]);
	return 0;
}