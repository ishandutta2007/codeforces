#include<cstdio>
#include<algorithm>
#include<vector>
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
constexpr int N=5e5+5;
namespace segtree
{
	#define lc (p<<1)
	#define rc (p<<1|1)
	int len[N<<2],max[N<<2],min[N<<2],tag[N<<2];
	long long sum[N<<2];
	void build(int p,int l,int r)
	{
		int mid=(l+r)>>1;
		len[p]=r-l;
		if(r-l==1)return;
		build(lc,l,mid);build(rc,mid,r);
	}
	inline void update(int p,int v)
	{
		max[p]=min[p]=tag[p]=v;
		sum[p]=v*(long long)len[p];
	}
	inline void pushdown(int p)
	{
		if(!tag[p])return;
		update(lc,tag[p]);
		update(rc,tag[p]);
		tag[p]=0;
	}
	void update(int p,int l,int r,int x,int v)
	{
		if(min[p]>=v||x<=l)return;
		if(max[p]<=v&&r<=x)return update(p,v);
		int mid=(l+r)>>1;
		pushdown(p);
		update(lc,l,mid,x,v);
		update(rc,mid,r,x,v);
		sum[p]=sum[lc]+sum[rc];
		min[p]=std::min(min[lc],min[rc]);
		max[p]=std::max(max[lc],max[rc]);
	}
	long long query(){return sum[1];}
	#undef lc
	#undef rc
}
int n,p,q,r,a[N],b[N],c[N];
long long ans;
vector<int> id[N];
int main()
{
	read(n,p,q,r);
	F(i,0,n)read(a[i],b[i],c[i]),id[a[i]].emplace_back(i);
	segtree::build(1,0,q);
	F(i,0,n)segtree::update(1,0,q,b[i],c[i]);
	for(int i=p;i;--i)
	{
		for(int j:id[i])segtree::update(1,0,q,b[j],r),segtree::update(1,0,q,q,c[j]);
		ans+=(long long)q*r-segtree::query();
	}
	printf("%lld\n",ans);
	return 0;
}