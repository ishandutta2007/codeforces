#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=5e5+5;
const long long LLINF=0x3fffffffffffffffll;
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
	int next,to,dis;
}e[N];
struct qy
{
	int v,l,r,id;
	bool operator<(qy b)const{return v<b.v;}
}a[N];
int n,q,p[N],w[N],hd[N],cnt,siz[N],kk;
long long dep[N],val[N<<2],tag[N<<2],ans[N];
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dep[v]=dep[u]+e[i].dis;
		dfs(v);
		siz[u]+=siz[v];
	}
	if(~hd[u])dep[u]=LLINF;
	++siz[u];
}
inline void pushdown(int p)
{
	val[lc]+=tag[p];val[rc]+=tag[p];
	tag[lc]+=tag[p];tag[rc]+=tag[p];
	tag[p]=0;
}
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return val[p]=dep[l],void();
	build(lc,l,mid);build(rc,mid,r);
	val[p]=min(val[lc],val[rc]);
}
void update(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return val[p]+=v,tag[p]+=v,void();
	pushdown(p);
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
	val[p]=min(val[lc],val[rc]);
}
long long query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return LLINF;
	if(x<=l&&r<=y)return val[p];
	pushdown(p);
	return min(query(lc,l,mid,x,y),query(rc,mid,r,x,y));
}
void dfs2(int u)
{
	while(kk<q&&a[kk].v==u)ans[a[kk].id]=query(0,0,n,a[kk].l,a[kk].r),++kk;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		update(0,0,n,v,v+siz[v],-e[i].dis);
		update(0,0,n,0,v,e[i].dis);
		update(0,0,n,v+siz[v],n,e[i].dis);
		dfs2(v);
		update(0,0,n,v,v+siz[v],e[i].dis);
		update(0,0,n,0,v,-e[i].dis);
		update(0,0,n,v+siz[v],n,-e[i].dis);
	}
}
int main()
{
	read(n);read(q);
	F(i,0,n)hd[i]=-1;
	F(i,1,n)read(p[i]),read(w[i]);
	for(int i=n-1;i;--i)adline(--p[i],i,w[i]);
	F(i,0,q)read(a[i].v),--a[i].v,read(a[i].l),--a[i].l,read(a[i].r),a[i].id=i;
	dfs(0);
	build(0,0,n);
	sort(a,a+q);
	dfs2(0);
	F(i,0,q)printf("%lld\n",ans[i]);
	return 0;
}