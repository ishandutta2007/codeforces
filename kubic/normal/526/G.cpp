#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,lf,all,ans,tmp[N];
struct Edge {int v,w;};vector<Edge> e[N];
bool cmp(int x,int y) {return tmp[x]>tmp[y];}
struct Tree
{
	int rt,dep[N],mx[N],lng[N],tg[N],s1[N],ord[N],fa[N][17],s[N][17];
	void dfs1(int u,int f)
	{
		for(int i=0,v,w;i<e[u].size();++i)
		{
			v=e[u][i].v;w=e[u][i].w;if(v==f) continue;
			dep[v]=dep[u]+w;dfs1(v,u);
		}
	}
	void dfs2(int u,int f)
	{
		for(int i=0,v,w;i<e[u].size();++i)
		{
			v=e[u][i].v;w=e[u][i].w;if(v==f) continue;fa[v][0]=u;s[v][0]=w;
			for(int j=1;j<=16;++j)
			{
				fa[v][j]=fa[fa[v][j-1]][j-1];
				s[v][j]=s[v][j-1]+s[fa[v][j-1]][j-1];
			}dfs2(v,u);if(mx[v]+w>mx[u]) mx[u]=mx[v]+w,lng[u]=v;
		}
		for(int i=0,v,w;i<e[u].size();++i)
		{
			v=e[u][i].v;w=e[u][i].w;
			if(v!=f && v!=lng[u]) tmp[v]=mx[v]+w,ord[++ord[0]]=v;
		}
	}
	void init()
	{
		dfs1(rt,0);for(int i=1;i<=n;++i) if(dep[i]>dep[rt]) rt=i;dfs2(rt,0);
		tmp[rt]=mx[rt];ord[++ord[0]]=rt;sort(ord+1,ord+ord[0]+1,cmp);
		for(int i=1;i<=ord[0];++i) s1[i]=s1[i-1]+mx[ord[i]]+s[ord[i]][0];
		for(int i=1;i<=ord[0];++i) for(int j=ord[i];j;j=lng[j]) tg[j]=i;
	}
	int slv1(int u,int x)
	{
		int t=mx[u];
		for(int i=16;i>=0;--i) if(tg[fa[u][i]]>=x) t+=s[u][i],u=fa[u][i];
		return s1[x-1]+t+s[u][0]; 
	}
	int slv2(int u,int x)
	{
		int t=mx[u];
		for(int i=16;i>=0;--i) if(tg[fa[u][i]]>x) t+=s[u][i],u=fa[u][i];
		return s1[x]-mx[fa[u][0]]+t+s[u][0];
	}
	int slv(int u,int x)
	{
		if(x*2>=lf) return all;x=x*2-1;
		if(tg[u]<=x) return s1[x];return max(slv1(u,x),slv2(u,x)); 
	}
}TR[2];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v,w;i<n;++i)
	{
		scanf("%d %d %d",&u,&v,&w);all+=w;
		e[u].push_back((Edge) {v,w});e[v].push_back((Edge) {u,w});
	}for(int i=1;i<=n;++i) lf+=(e[i].size()==1);
	TR[0].rt=1;TR[0].init();TR[1].rt=TR[0].rt;TR[1].init();
	for(int i=1,u,x;i<=m;++i)
	{
		scanf("%d %d",&u,&x);u=(u+ans-1)%n+1;x=(x+ans-1)%n+1;
		ans=max(TR[0].slv(u,x),TR[1].slv(u,x));printf("%d\n",ans);
	}return 0;
}