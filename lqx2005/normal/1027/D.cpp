#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=200000;
const int inf=100000000000000;
int n;
int cost[maxn+5],to[maxn+5];
vector<int> g[maxn+5];
int s[maxn+5],top,dfn[maxn+5],low[maxn+5],vi[maxn+5],Time;
int belong[maxn+5],sz[maxn+5],mcost[maxn+5];
void add(int u,int v)
{
	g[u].push_back(v);
	return;
}
void tarjan(int u)
{
	Time++;
	dfn[u]=low[u]=Time;
	s[++top]=u;
	vi[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(!dfn[v]) 
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vi[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u])
	{
		while(s[top]!=u)
		{
			vi[s[top]]=0;
			sz[u]++;
			belong[s[top]]=u;
			top--;
		}
		vi[s[top]]=0;
		sz[u]++;
		belong[s[top]]=u;
		top--;
	}
	return;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&cost[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&to[i]);
		add(i,to[i]);
	}
	for(int i=1;i<=n;i++) mcost[i]=inf;
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int u=1;u<=n;u++)
	{
		if(sz[belong[u]]<=1) continue;
		mcost[belong[u]]=min(mcost[belong[u]],cost[u]);
	}
	int sum=0;
	for(int u=1;u<=n;u++)
	{
		if(sz[u]<=1) continue;
		sum+=mcost[u];
	}
	for(int i=1;i<=n;i++) if(to[i]==i) sum+=cost[i];
	printf("%lld\n",sum);
	return 0;
}