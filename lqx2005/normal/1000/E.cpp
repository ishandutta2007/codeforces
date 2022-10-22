#include <bits/stdc++.h>
using namespace std;
const int maxn=300000;
vector<int> g[maxn+5],e[maxn+5];
int n,m,dfn[maxn+5],low[maxn+5],Time;
int s[maxn+5],top,belong[maxn+5],maxdep,id,Begin,End;
void tarjan(int u,int fa)
{
	Time++;
	dfn[u]=low[u]=Time;
	s[++top]=u;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(v!=fa) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		while(s[top]!=u)
		{
			belong[s[top]]=u;
			top--;
		}
		belong[s[top]]=u;
		top--;
	}
	return;
}
void dfs(int u,int fa,int dep)
{
	if(dep>maxdep)
	{
		id=u;
		maxdep=dep;
	}
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	Time=0;
	tarjan(1,0);
	for(int u=1;u<=n;u++)
	{
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(belong[u]==belong[v]) continue;
			e[belong[u]].push_back(belong[v]);
		}
	}
	dfs(1,0,0);
	Begin=id;
	dfs(Begin,0,0);
	End=id;
//	cout<<Begin<<" "<<End<<endl;
	printf("%d\n",maxdep);
	return 0;
}