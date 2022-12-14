#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,m,a,b,x,y,beg[222222],en[222222],cnt,dfn[222222],low[222222],sub[222222],pa[222222],sma,smb;
vector<int> g[222222],ng[222222];
void dfs(int i,int fa)
{
	dfn[i]=++cnt;beg[i]=low[i]=dfn[i];sub[i]=1;pa[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (!dfn[to])
		{
			ng[i].push_back(to);
			dfs(to,i);
			sub[i]+=sub[to];
			low[i]=min(low[i],low[to]);
		}
		else 
		{
			low[i]=min(low[i],dfn[to]);
		}
	}
	en[i]=cnt;
}
void dft(int i,bool f)
{
	if (i!=b && f) 
	{
		smb++;
	}
	for (int j=0;j<ng[i].size();j++)
	{
		int to=ng[i][j];
		if (low[to]<dfn[b]) dft(to,0);
		else dft(to,f);
	}
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for (int i=1;i<=n;i++) 
		{
			g[i].clear();
			ng[i].clear();
		}
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for (int i=1;i<=n;i++)
		{
			beg[i]=en[i]=sub[i]=dfn[i]=low[i]=pa[i]=0;
		}
		cnt=0;
		dfs(a,0);
		sma=smb=0;
		for (int i=0;i<ng[a].size();i++)
		{
			int to=ng[a][i];
			if (beg[to]<=beg[b] && beg[b]<=en[to]) continue;
			sma+=sub[to];
		}
		dft(b,1);
		printf("%lld\n",1ll*sma*smb);
	}
	return Accepted;
}