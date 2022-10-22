#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=1e5+5,LogN=19;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[N<<1];
int n,logn,q,a[N],hd[N],cnt,dfn[N],ind[N],siz[N],rt,f[N][LogN],dep[N];
long long sum[N<<2],tag[N<<2];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	siz[ind[dfn[u]=cnt++]=u]=1;
	dep[u]=dep[f[u][0]=fa]+1;
	F(i,0,logn)f[u][i+1]=f[f[u][i]][i];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);siz[u]+=siz[v];
	}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])u^=v^=u^=v;
	for(int i=0,k=dep[v]-dep[u];k;k>>=1,++i)if(k&1)v=f[v][i];
	for(int i=logn;~i;--i)if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	return u==v?u:f[u][0];
}
int rlca(int u,int v)
{
	int w,w1,w2;
	if(u==v)return u;if(u==rt||v==rt)return rt;
	if(dep[u]>dep[v])u^=v^=u^=v;
	if((w=lca(u,v))==u)
	{
		if(lca(u,rt)!=u)return u;
		return lca(v,rt);
	}
	if(lca(w,rt)!=w)return w;
	w1=lca(u,rt);
	w2=lca(v,rt);
	return dep[w1]>dep[w2]?w1:w2;
}
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return sum[p]=a[ind[l]],void();
	build(lc,l,mid);build(rc,mid,r);
	sum[p]=sum[lc]+sum[rc];
}
void pushdown(int p,int l,int r)
{
	long long mid=(l+r)>>1;
	sum[lc]+=tag[p]*(mid-l);
	sum[rc]+=tag[p]*(r-mid);
	tag[lc]+=tag[p];tag[rc]+=tag[p];
	tag[p]=0;
}
void update(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return tag[p]+=v,sum[p]+=(long long)(r-l)*v,void();
	pushdown(p,l,r);
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
	sum[p]=sum[lc]+sum[rc];
}
void update(int u,int x)
{
	int v=rt;
	if(u==rt)return update(0,0,n,0,n,x),void();
	if(lca(u,rt)!=u)return update(0,0,n,dfn[u],dfn[u]+siz[u],x),void();
	for(int i=0,k=dep[v]-dep[u]-1;k;k>>=1,++i)if(k&1)v=f[v][i];
	update(0,0,n,0,n,x);
	update(0,0,n,dfn[v],dfn[v]+siz[v],-x);
}
long long query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return sum[p];
	pushdown(p,l,r);
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
long long query(int u)
{
	int v=rt;
	if(u==rt)return query(0,0,n,0,n);
	if(lca(u,rt)!=u)return query(0,0,n,dfn[u],dfn[u]+siz[u]);
	for(int i=0,k=dep[v]-dep[u]-1;k;k>>=1,++i)if(k&1)v=f[v][i];
	return query(0,0,n,0,n)-query(0,0,n,dfn[v],dfn[v]+siz[v]);
}
int main()
{
	read(n);read(q);
	while((1<<logn)<n)++logn;
	F(i,0,n)read(a[i]);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	dfs(cnt=0,0);
	build(0,0,n);
	while(q--)
	{
		int op;
		read(op);
		if(op==1)
		{
			int u;read(u);rt=--u;
		}
		else if(op==2)
		{
			int u,v,w,x;read(u);read(v);read(x);w=rlca(--u,--v);
			update(w,x);
		}
		else if(op==3)
		{
			int u;read(u);--u;
			printf("%lld\n",query(u));
		}
	}
	return 0;
}