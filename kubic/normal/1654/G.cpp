#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define pb push_back
const int INF=1e9;
int n,G,a[N],b[N],q[N],sz[N],st[N],ans[N];
bool vs[N],tg[N];vector<int> e[N];
int w1[N],mn1[N],z1[N],w2[N],mn2[N],z2[N],dep[N],s1[N],s2[N];
void bfs()
{
	q[0]=2;q[1]=1;for(int i=1;i<=n;++i) b[i]=INF;
	for(int i=1;i<=n;++i) if(a[i]) q[++q[1]]=i,b[i]=0;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(auto v:e[u]) if(b[v]==INF) b[v]=b[u]+1,q[++q[1]]=v;
	}
}
void dfs1(int u,int f,int x)
{
	int mx=0;sz[u]=1;
	for(auto v:e[u]) if(v!=f && !vs[v])
		dfs1(v,u,x),sz[u]+=sz[v],mx=max(mx,sz[v]);
	mx=max(mx,x-sz[u]);if(mx<=x/2) G=u;
}
void dfs2(int u,int f)
{
	st[++st[0]]=u;if(tg[u]) z1[u]=max(z1[u],0),z2[u]=0;
	if(!b[u] && mn2[u]>=-n)
	{int t=-mn2[u];s1[t]=min(s1[t],z2[u]);s2[t]=min(s2[t],dep[u]);}
	for(auto v:e[u]) if(v!=f && !vs[v])
	{
		if(b[u]<b[v])
			w1[v]=w1[u]+1,mn1[v]=min(mn1[u]+1,0),w2[v]=mn2[v]=-INF;
		else if(b[u]>b[v])
			w1[v]=mn1[v]=-INF,w2[v]=w2[u]+1,mn2[v]=min(mn2[u],w2[v]);
		else
		{
			w1[v]=w1[u]-1;mn1[v]=mn1[u]-1;
			w2[v]=w2[u]-1;mn2[v]=min(mn2[u],w2[v]);
		}z1[v]=z1[u]+1;z2[v]=z2[u]+1;dep[v]=dep[u]+1;dfs2(v,u);
	}
}
void slv(int u,int x)
{
	dfs1(u,0,x);u=G;dfs1(u,0,x);vs[u]=1;
	z1[u]=-INF;z2[u]=INF;for(int i=0;i<=x;++i) s1[i]=s2[i]=INF;
	st[0]=w1[u]=mn1[u]=w2[u]=mn2[u]=dep[u]=0;dfs2(u,0);
	for(int i=1;i<=x;++i)
		s1[i]=min(s1[i],s1[i-1]),s2[i]=min(s2[i],s2[i-1]);
	for(int i=1,t;i<=x;++i) if(mn1[st[i]]>=0)
		t=st[i],ans[t]=min(ans[t],min(s1[w1[t]],dep[t]+s2[w1[t]]-z1[t]));
	for(auto v:e[u]) if(!vs[v]) slv(v,sz[v]);
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);bfs();
	for(int i=1;i<=n;++i) for(auto j:e[i]) if(b[i]==b[j]) tg[i]=1;
	for(int i=1;i<=n;++i) ans[i]=b[i];slv(1,n);
	for(int i=1;i<=n;++i) printf("%d ",b[i]*2-ans[i]);return 0;
}