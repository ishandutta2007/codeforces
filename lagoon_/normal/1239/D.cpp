#include<bits/stdc++.h>
using namespace std;
#define re register
int cnt,cntb;
vector<int>edge[1010000];
bool in[1010000],vis[1010000],ok;
int dfn[1010000],n;
int low[1010000],s[1010000],ta,vs[1001000];
void Tarjan(int u)
{
	if(ok)return;
	++cnt;
	dfn[u]=low[u]=cnt;
	vis[u]=1;
	s[++ta]=u;
	in[u]=1;
	for(int i=0;i<edge[u].size();++i)
	{
		int v=edge[u][i];
		if(!vis[v])
		{
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(ok)return;
	if(dfn[u]==low[u])
	{
		int x,xx=0;
		do
		{
			x=s[ta];ta--;
			in[x]=0;
			vs[x]=1;xx++;
		}while(x!=u);
		if(xx!=n)
		{
			puts("Yes");
			printf("%d %d\n",xx,n-xx);
			for(re int i=1;i<=n;i++)if(vs[i])printf("%d ",i);puts("");
			for(re int i=1;i<=n;i++)if(!vs[i])printf("%d ",i);puts("");
			ok=1;
		}
	}
}
int main()
{
	re int t;
	scanf("%d",&t);
	for(;t--;)
	{
		ta=cnt=ok=0;
		re int m;
		scanf("%d%d",&n,&m);
		for(re int i=1;i<=n;i++)edge[i].clear(),vs[i]=vis[i]=dfn[i]=low[i]=in[i]=s[i]=0;
		for(re int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(u!=v);
			edge[u].push_back(v);
		}
		for(re int i=1;i<=n;i++)if(!vis[i])Tarjan(i);
		if(!ok)puts("No");
	}
	return 0;
}