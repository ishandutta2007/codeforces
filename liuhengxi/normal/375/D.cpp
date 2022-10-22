#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=5e6+5;
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
}e[2*N];
int n,m,c[N],v[N],hd[N],cnt,dfn[N],ind,kk,ans[N],rt1[N],rt2[N],tot;
int val[M],lc[M],rc[M];
struct query
{
	int u,k,id;
	bool operator<(query b)const{return dfn[u]<dfn[b.u];}
}q[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u,int fa)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs1(v,u);
	}
	dfn[u]=ind++;
}
int merge2(int p,int q)
{
	if(!p||!q)return p^q;
	val[p]+=val[q];
	lc[p]=merge2(lc[p],lc[q]);
	rc[p]=merge2(rc[p],rc[q]);
	return p;
}
int update(int p,int l,int r,int x,int v)
{
	int mid=l+((r-l+2)>>2);
	if(!p)p=++tot;
	if(r-l!=1)
	{
		if(x<mid)lc[p]=update(lc[p],l,mid,x,v);
		else rc[p]=update(rc[p],mid,r,x,v);
	}
	val[p]+=v;
	return p;
}
int merge1(int p,int q,int &r)
{
	if(!p||!q)return p^q;
	if(!lc[p]&&!rc[p])
	{
		r=update(r,0,n,val[p]+val[q],1),
		r=update(r,0,n,val[p],-1),r=update(r,0,n,val[q],-1);
		val[p]+=val[q];
	}
	else
	{
		lc[p]=merge1(lc[p],lc[q],r);
		rc[p]=merge1(rc[p],rc[q],r);
	}
	return p;
}
int query(int p,int l,int r,int x,int y)
{
	int mid=l+((r-l+2)>>2);
	if(y<=l||r<=x||!p)return 0;
	if(x<=l&&r<=y)return val[p];
	return query(lc[p],l,mid,x,y)+query(rc[p],mid,r,x,y);
}
void dfs(int u,int fa)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		rt2[u]=merge2(rt2[u],rt2[v]);
		rt1[u]=merge1(rt1[u],rt1[v],rt2[u]);
	}
	rt2[u]=update(rt2[u],0,n,1,1);
	rt1[u]=merge1(rt1[u],update(0,0,n,c[u],1),rt2[u]);
	while(kk<m&&q[kk].u==u)
	{
		ans[q[kk].id]=query(rt2[u],0,n,q[kk].k,n);
		++kk;
	}
}
int main()
{
	read(n);read(m);
	F(i,0,n)read(c[i]),v[i]=c[i];
	sort(v,v+n);
	F(i,0,n)c[i]=lower_bound(v,v+n,c[i])-v;
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);--u,--v;
		adline(u,v);adline(v,u);
	}
	++n;
	F(i,0,m)read(q[i].u),read(q[i].k),--q[i].u,q[i].id=i;
	dfs1(0,0);
	sort(q,q+m);
	dfs(0,0);
	F(i,0,m)printf("%d\n",ans[i]);
	return 0;
}