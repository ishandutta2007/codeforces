#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using std::max;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line{int next,to,w;}e[2*N];
int n,q,hd[N],cnt,a[N],b[N],fa[N],dep[N],siz[N],hc[N],top[N];
long long s[N],f[N],g[N],h[N],c[N],ff[N];
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u)
{
	hc[u]=-1;s[u]=s[fa[u]]+a[u]-b[u];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa[u])continue;
		fa[v]=u;b[v]=e[i].w;
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(!~hc[u]||siz[v]>siz[hc[u]])hc[u]=v;
		f[u]+=max(0ll,f[v]+a[v]-2*b[v]);
	}
	++siz[u];
}
void dfs2(int u)
{
	long long sum=(ff[u]=f[u])+g[u]+a[u];
	h[u]=max(h[u],0ll);
	if(~hc[u])
	{
		int v=hc[u];top[v]=top[u];
		g[v]=max(0ll,sum-2*b[v]-max(0ll,h[v]=f[v]+a[v]-2*b[v]));
		dfs2(v);
	}
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa[u]||v==hc[u])continue;
		g[v]=max(0ll,sum-2*b[v]-max(0ll,h[v]=f[v]+a[v]-2*b[v]));
		dfs2(top[v]=v);
	}
}
void dfs3(int u)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa[u])continue;
		f[v]+=f[u];h[v]+=h[u];
		dfs3(v);
	}
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]])u=fa[top[u]];
		else v=fa[top[v]];
	}
	return dep[u]<dep[v]?u:v;
}
int main()
{
	read(n);read(q);
	F(i,0,n)read(a[i]);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v,w;read(u);read(v);read(w);
		adline(--u,--v,w);adline(v,u,w);
	}
	dfs1(0);dfs2(0);dfs3(0);
	while(q--)
	{
		int u,v,m;long long ans;read(u);read(v);--u,--v;
		m=lca(u,v);
		ans=s[u]+s[v]-2*s[m]+a[m];
		ans+=f[u]+f[v]-2*f[m]+g[m];
		ans-=h[u]+h[v]-2*h[m]-ff[m];
		printf("%lld\n",ans);
	}
	return 0;
}