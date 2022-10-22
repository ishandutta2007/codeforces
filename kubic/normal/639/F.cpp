#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define LIM 1000005
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define set(a,vl) memset(a,vl,sizeof(a))
char *P1,*P2,buf[LIM];
int n,m,c,nw,a1[N],a2[N],z1[N],z[N],vs[N],lg[N*2];bool ans;
int rt[N],dfn[N],dep[N],ps[20][N*2];vector<int> e1[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
int f(int x) {x=(x+nw)%n;if(!x) x=n;return x;}
struct Edge {int u,v;}z2[N];
struct Graph
{
	int cntE,dfn[N],low[N],st[N],col[N];vector<Edge> e[N];
	void addE(int u,int v)
	{if(u!=v) e[u].pb((Edge) {cntE++,v}),e[v].pb((Edge) {cntE++,u});}
	void Tarjan(int u,int f)
	{
		dfn[u]=low[u]=++dfn[0];st[++st[0]]=u;
		for(int i=0,v,id;i<e[u].size();++i)
		{
			v=e[u][i].v;id=e[u][i].u;if((id^1)==f) continue;
			if(!dfn[v]) Tarjan(v,id),low[u]=min(low[u],low[v]);
			else if(!col[v]) low[u]=min(low[u],dfn[v]);
		}
		if(dfn[u]==low[u])
		{col[u]=++col[0];while(st[st[0]]!=u) col[st[st[0]--]]=col[0];--st[0];}
	}
}G[2];
bool cmp(int x,int y) {return dfn[x]<dfn[y];}
void ins(int x,int u)
{
	if(vs[u]==x) return;vs[u]=x;z[++z[0]]=u;
	G[1].dfn[u]=G[1].low[u]=G[1].col[u]=0;G[1].e[u].clear();
}
void dfs(int u,int f,int x)
{
	rt[u]=x;ps[0][dfn[u]=++dfn[0]]=u;dep[u]=dep[f]+1;
	for(int i=0,v;i<e1[u].size();++i)
	{v=e1[u][i];if(!dfn[v]) dfs(v,u,x),ps[0][++dfn[0]]=u;}
}
int LCA(int u,int v)
{
	int l=dfn[u],r=dfn[v],t,u1,v1;if(l>r) swap(l,r);t=lg[r-l+1];
	u1=ps[t][l];v1=ps[t][r-(1<<t)+1];return dep[u1]<dep[v1]?u1:v1;
}
bool slv(int x)
{
	int tmp;z[0]=G[1].cntE=G[1].dfn[0]=G[1].st[0]=G[1].col[0]=0;
	for(int i=1;i<=a1[x];++i) ins(x,z1[i]);
	for(int i=1;i<=a2[x];++i) ins(x,z2[i].u),ins(x,z2[i].v),G[1].addE(z2[i].u,z2[i].v);
	sort(z+1,z+z[0]+1,cmp);tmp=z[0];
	for(int i=1;i<tmp;++i) if(rt[z[i]]==rt[z[i+1]]) ins(x,LCA(z[i],z[i+1]));
	sort(z+1,z+z[0]+1,cmp);
	for(int i=1;i<z[0];++i) if(rt[z[i]]==rt[z[i+1]]) G[1].addE(LCA(z[i],z[i+1]),z[i+1]);
	for(int i=1;i<=z[0];++i) if(!G[1].dfn[z[i]]) G[1].Tarjan(z[i],-1);
	for(int i=1;i<a1[x];++i) if(G[1].col[z1[i]]!=G[1].col[z1[i+1]]) return 0;
	return 1;
}
int main()
{
	n=rd();m=rd();c=rd();for(int i=2;i<=n*2;++i) lg[i]=lg[i/2]+1;
	G[0].cntE=0;set(G[0].dfn,0);set(G[0].low,0);set(G[0].st,0);set(G[0].col,0);
	for(int i=1;i<=n;++i) G[0].e[i].clear();
	for(int i=1,u,v;i<=m;++i) u=rd(),v=rd(),G[0].addE(u,v);
	for(int i=1;i<=n;++i) if(!G[0].dfn[i]) G[0].Tarjan(i,-1);
	for(int i=1,v;i<=n;++i) for(int j=0;j<G[0].e[i].size();++j)
		v=G[0].col[G[0].e[i][j].v],e1[G[0].col[i]].pb(v),e1[v].pb(G[0].col[i]);
	for(int i=1;i<=G[0].col[0];++i) if(!dfn[i]) dfs(i,0,i);
	for(int i=1,u,v;i<=19;++i) for(int j=1;j+(1<<i)-1<=dfn[0];++j)
		u=ps[i-1][j],v=ps[i-1][j+(1<<i-1)],ps[i][j]=dep[u]<dep[v]?u:v;
	for(int i=1;i<=c;++i)
	{
		bool res;a1[i]=rd();a2[i]=rd();
		for(int j=1;j<=a1[i];++j) z1[j]=G[0].col[f(rd())];
		for(int j=1;j<=a2[i];++j) z2[j].u=G[0].col[f(rd())],z2[j].v=G[0].col[f(rd())];
		res=slv(i);puts(res?"YES":"NO");nw=(nw+res*i)%n;
	}return 0;
}