#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,LogN=20;
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
}e[N];
struct route
{
	int next,to;
}r[2*N];
struct query
{
	int next,id;
}qq[N];
int n,logn,m,hd[N],cnt,a[N],b[N],c[N],dep[N],fa[N][LogN],up[N][LogN];
int rcnt,rhd[N],q,uu[N],vv[N],ans[N],qhd[N],qcnt,dfn[N],ind,siz[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void adroute(int u,int v)
{
	r[rcnt].to=v;
	r[rcnt].next=rhd[u];
	rhd[u]=rcnt++;
}
void adquery(int u,int id)
{
	qq[qcnt].id=id;
	qq[qcnt].next=qhd[u];
	qhd[u]=qcnt++;
}
void dfs(int u)
{
	F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dep[v]=dep[u]+1;
		fa[v][0]=u;
		dfs(v);
	}
}
int jump(int u,int h)
{
	for(int i=0;h;++i,h>>=1)if(h&1)u=fa[u][i];
	return u;
}
int lca(int u,int v)
{
	int dif=dep[u]-dep[v];
	if(dif<0)u^=v^=u^=v,dif=-dif;
	u=jump(u,dif);
	for(int i=logn;~i;--i)if(fa[u][i]!=fa[v][i])
		u=fa[u][i],v=fa[v][i];
	return u==v?u:fa[u][0];
}
void dfs1(int u)
{
	dfn[u]=ind++;
	siz[u]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs1(v);
		siz[u]+=siz[v];
		if(dep[up[u][0]]>dep[up[v][0]])up[u][0]=up[v][0];
	}
}
//seg
int lc[4*N*LogN],rc[4*N*LogN],ncnt=1;
int build(int l,int r,int x)
{
	int p=ncnt++,mid=(l+r)>>1;
	if(r-l==1)return p;
	if(x<mid)lc[p]=build(l,mid,x);
	else rc[p]=build(mid,r,x);
	return p;
}
int merge(int p,int q)
{
	int r;
	if(!p)return q;
	if(!q)return p;
	r=ncnt++;
	lc[r]=merge(lc[p],lc[q]);
	rc[r]=merge(rc[p],rc[q]);
	return r;
}
int query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(!p)return 0;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return 1;
	return query(lc[p],l,mid,x,y)||query(rc[p],mid,r,x,y);
}
//\seg
int dfs2(int u)
{
	int rt=0;
	for(int i=rhd[u];~i;i=r[i].next)rt=merge(rt,build(0,n,dfn[r[i].to]));
	for(int i=hd[u];~i;i=e[i].next)rt=merge(rt,dfs2(e[i].to));
	for(int i=qhd[u];~i;i=qq[i].next)
	{
		int id=qq[i].id;
		if(query(rt,0,n,dfn[vv[id]],dfn[vv[id]]+siz[vv[id]]))--ans[id];
	}
	return rt;
}
int main()
{
	read(n);
	while((1<<logn)<n)++logn;
	F(i,0,n)qhd[i]=rhd[i]=hd[i]=-1;
	F(i,1,n)
	{
		int p;read(p);
		adline(--p,i);
	}
	read(m);
	F(i,0,m)
	{
		read(a[i]);read(b[i]);
		adroute(--a[i],--b[i]);adroute(b[i],a[i]);
	}
	dfs(0);
	F(i,0,n)F(j,0,logn+1)up[i][j]=i;
	F(i,0,m)
	{
		c[i]=lca(a[i],b[i]);
		if(dep[up[a[i]][0]]>dep[c[i]])up[a[i]][0]=c[i];
		if(dep[up[b[i]][0]]>dep[c[i]])up[b[i]][0]=c[i];
	}
	dfs1(0);
	F(i,0,n)F(j,0,logn)up[i][j+1]=up[up[i][j]][j];
	read(q);
	F(k,0,q)
	{
		int u,v,w;read(u);read(v);--u,--v;
		if(up[u][logn]!=up[v][logn])ans[k]=-1;
		else
		{
			w=lca(u,v);
			uu[k]=u,vv[k]=v;
			for(int i=logn;~i;--i)if(dep[up[u][i]]>dep[w])
			{
				ans[k]+=1<<i;
				u=up[u][i];
			}
			if(dep[up[u][0]]>dep[w]||(vv[k]==w&&dep[u]>dep[w]))
			{
				ans[k]+=1;
				u=up[u][0];
				if(dep[u]<dep[w])u=w;
			}
			for(int i=logn;~i;--i)if(dep[up[v][i]]>dep[w])
			{
				ans[k]+=1<<i;
				v=up[v][i];
			}
			if(dep[up[v][0]]>dep[w]||(uu[k]==w&&dep[v]>dep[w]))
			{
				ans[k]+=1;
				v=up[v][0];
				if(dep[v]<dep[w])v=w;
			}
			uu[k]=u,vv[k]=v;
			if(u!=v)ans[k]+=2;
		}
	}
	F(k,0,q)if(~ans[k]&&uu[k]!=vv[k])adquery(uu[k],k);
	dfs2(0);
	F(k,0,q)printf("%d\n",ans[k]);
	return 0;
}