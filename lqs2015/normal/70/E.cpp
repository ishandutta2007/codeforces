#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> g[222];
int n,k,d[222],x,y,dis[222][222],dp[222][222],gg[222],beg[222],en[222],ct,mn,ans[222];
void dfs(int i,int rt,int fa,int dep)
{
	dis[rt][i]=d[dep];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,rt,i,dep+1);
	}
}
void dfss(int i,int fa)
{
	beg[i]=++ct;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfss(to,i);
	}
	en[i]=ct;
	mn=1e9;
	for (int j=1;j<=n;j++)
	{
		dp[i][j]=k+dis[i][j];
		for (int h=0;h<g[i].size();h++)
		{
			int to=g[i][h];
			if (to==fa) continue;
			dp[i][j]+=min(dp[to][j]-k,dp[to][gg[to]]);
		}
		if (beg[j] && beg[j]>=beg[i] && beg[j]<=en[i])
		{
			if (dp[i][j]<mn)
			{
				mn=dp[i][j];
				gg[i]=j;
			}
		}
	}
}
void dft(int i,int fa,int bestu)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (dp[to][gg[to]]>dp[to][bestu]-k) 
		{
			ans[to]=bestu;
			dft(to,i,bestu);
		}
		else
		{
			ans[to]=gg[to];
			dft(to,i,gg[to]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++) scanf("%d",&d[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	for (int i=1;i<=n;i++)
	{
		dfs(i,i,0,0);
	}
	dfss(1,0);
	printf("%d\n",dp[1][gg[1]]);
	dft(1,0,gg[1]);
	ans[1]=gg[1];
	for (int j=1;j<=n;j++) printf("%d ",ans[j]);
	return 0;
}