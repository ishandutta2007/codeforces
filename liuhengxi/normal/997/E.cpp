#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1.2e5+5,INF=0x3fffffff;
namespace block
{
	int b,val[N],tag[N],min[N],cnt[N];
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			F(i,u*b,u*b+b)val[i]+=tag[u];
			tag[u]=0;
		}
	}
	inline void update(int u)
	{
		min[u]=INF;
		F(i,u*b,u*b+b)
		{
			if(val[i]<min[u])min[u]=val[i],cnt[u]=0;
			cnt[u]+=val[i]==min[u];
		}
	}
	void add(int l,int r,int w)
	{
		if(r/b-l/b<2)
		{
			pushdown(l/b);
			if(r/b!=l/b)pushdown(r/b);
			F(i,l,r)val[i]+=w;
			update(l/b);
			if(r/b!=l/b)update(r/b);
			return;
		}
		if(l%b)
		{
			int u=l/b;
			pushdown(u);
			F(i,l,u*b+b)val[i]+=w;
			update(u);
			l=u*b+b;
		}
		if(r%b)
		{
			int u=r/b;
			pushdown(u);
			F(i,u*b,r)val[i]+=w;
			update(u);
			r=u*b;
		}
		F(i,l/b,r/b)min[i]+=w,tag[i]+=w;
	}
	int sum(int u){return (min[u]==1)*cnt[u];}
	int sum(int l,int r)
	{
		pushdown(l/b);
		int ans=0;
		F(i,l,r)ans+=val[i]==1;
		return ans;
	}
}
namespace segtree
{
	#define lc (p<<1)
	#define rc (p<<1|1)
	constexpr int N=(1<<18)+5;
	int min[N],cnt[N],tag[N];
	inline void pushdown(int p){min[lc]+=tag[p];tag[lc]+=tag[p];min[rc]+=tag[p];tag[rc]+=tag[p];tag[p]=0;}
	void build(int p,int l,int r)
	{
		cnt[p]=r-l;
		if(r-l==1)return;
		int mid=(l+r)>>1;
		build(lc,l,mid);build(rc,mid,r);
	}
	void update(int p,int l,int r,int x,int y,int v)
	{
		if(x==l&&r==y)return tag[p]+=v,min[p]+=v,void();
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)update(lc,l,mid,x,y,v);
		else if(mid<=x)update(rc,mid,r,x,y,v);
		else update(lc,l,mid,x,mid,v),update(rc,mid,r,mid,y,v);
		min[p]=std::min(min[lc],min[rc]);
		cnt[p]=(min[lc]==min[p])*cnt[lc]+(min[rc]==min[p])*cnt[rc];
	}
	int query(int p,int l,int r,int x,int y)
	{
		if(x==l&&r==y)return (min[p]==1)*cnt[p];
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)return query(lc,l,mid,x,y);
		if(mid<=x)return query(rc,mid,r,x,y);
		return query(lc,l,mid,x,mid)+query(rc,mid,r,mid,y);
	}
	#undef lc
	#undef rc
}
using block::b;
using block::add;
using block::sum;
using segtree::build;
using segtree::update;
using segtree::query;
int n,p[N],ip[N],q,l[N],r[N];
vector<int> lq[N],rq[N];
long long ans[N],pre[N];
int main()
{
	read(n);
	F(i,0,n)ip[--read(p[i])]=i;
	b=(int)sqrt(n/log2(max(n,2)));
	b=min(max(b,1),n);
	F(i,0,(n+b-1)/b+1)block::cnt[i]=b;
	F(i,0,read(q))read(l[i],r[i]),lq[--l[i]].emplace_back(i),rq[r[i]/b].emplace_back(i);
	for(int i=n;~--i;)
	{
		add(i,n,1);
		if(p[i]>0&&ip[p[i]-1]>i)add(ip[p[i]-1],n,-1);
		if(p[i]<n-1&&ip[p[i]+1]>i)add(ip[p[i]+1],n,-1);
		int tmp=sum(i,i/b*b+b);
		pre[i/b+1]+=tmp;
		F(j,i/b+1,n/b)
		{
			tmp+=sum(j);
			pre[j+1]+=tmp;
		}
		for(int x:lq[i])ans[x]=pre[r[x]/b];
	}
	build(1,0,n);
	F(i,0,n)
	{
		update(1,0,n,0,i+1,1);
		if(p[i]>0&&ip[p[i]-1]<i)update(1,0,n,0,ip[p[i]-1]+1,-1);
		if(p[i]<n-1&&ip[p[i]+1]<i)update(1,0,n,0,ip[p[i]+1]+1,-1);
		for(int x:rq[i/b])if(l[x]<=i&&i<r[x])ans[x]+=query(1,0,n,l[x],i+1);
	}
	F(i,0,q)printf("%lld\n",ans[i]);
	return 0;
}