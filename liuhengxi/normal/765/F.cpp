// LUOGU_RID: 90648504
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
constexpr int N=1e5+5,M=1e6+5,INF=0x3fffffff;
namespace BIT
{
	struct BITb
	{
		int n,c[N];
		void build(int n_){F(i,1,(n=n_)+1)c[i]=INF;}
		void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]=min(c[x],y);}
		int sum(int x)
		{
			int ans=INF;
			for(;x;x-=x&-x)ans=min(ans,c[x]);
			return ans;
		}
	}b;
}
using BIT::b;
namespace seg
{
	template<typename T,T e(),T f(T,T),int N,T d()=e>struct segtree
	{
#define lc (p<<1)
#define rc (p<<1|1)
	private:
		int n;T seg[(1<<(33-__builtin_clz(N)))+5];
		void build(int p,int l,int r)
		{
			int mid=(l+r)>>1;
			if(r-l==1)return seg[p]=d(),void();
			build(lc,l,mid);build(rc,mid,r);
			seg[p]=f(seg[lc],seg[rc]);
		}
		void build(int p,int l,int r,T (*const &dd)(int))
		{
			int mid=(l+r)>>1;
			if(r-l==1)return seg[p]=dd(l),void();
			build(lc,l,mid,dd);build(rc,mid,r,dd);
			seg[p]=f(seg[lc],seg[rc]);
		}
		void update(int p,int l,int r,const int &x,const T &v)
		{
			int mid=(l+r)>>1;
			if(r-l==1)return seg[p]=v,void();
			if(x<mid)update(lc,l,mid,x,v);
			else update(rc,mid,r,x,v);
			seg[p]=f(seg[lc],seg[rc]);
		}
		T get(int p,int l,int r,const int &x)
		{
			int mid=(l+r)>>1;
			if(r-l==1)return seg[p];
			if(x<mid)return get(lc,l,mid,x);
			else return get(rc,mid,r,x);
		}
		T query(int p,int l,int r,const int &x,const int &y)
		{
			int mid=(l+r)>>1;
			if(x==l&&r==y)return seg[p];
			if(y<=mid)return query(lc,l,mid,x,y);
			if(mid<=x)return query(rc,mid,r,x,y);
			return f(query(lc,l,mid,x,mid),query(rc,mid,r,mid,y));
		}
	public:
		void build(int n_){build(1,0,n=n_);}
		void build(int n_,T dd(int)){build(1,0,n=n_,dd);}
		void update(int x,T v){update(1,0,n,x,v);}
		T get(int x){return get(1,0,n,x);}
		T query(int x,int y){return x<y?query(1,0,n,x,y):e();}
#undef lc
#undef rc
	}; 
	int e(){return INF;}
	int f(int x,int y){return min(x,y);}
	segtree<int,e,f,N> s;
}
using seg::s;
int n,a[N],v[N],m,ans[M];
vector<pair<int,int>> qy[N];
int main()
{
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
#endif
#endif
	F(i,0,read(n))v[i]=read(a[i]);
	sort(v,v+n);
	F(i,0,read(m))
	{
		int l,r;read(l,r);--l;
		qy[l].emplace_back(r,i);
	}
	s.build(n);
	b.build(n);
	for(int i=n;~--i;)
	{
		int d=(int)(lower_bound(v,v+n,a[i])-v);
		for(int rr=v[n-1]+1;rr>a[i];)
		{
			int k=s.query(d,(int)(lower_bound(v,v+n,rr)-v));
			if(k>=n)break;
			b.add(k,a[k]-a[i]);
			rr=(a[i]+a[k]+1)>>1;
		}
		for(int ll=v[0];ll<=a[i];)
		{
			int k=s.query((int)(lower_bound(v,v+n,ll)-v),d+1);
			if(k>=n)break;
			b.add(k,a[i]-a[k]);
			ll=(a[i]+a[k]+2)>>1;
		}
		s.update(d,i);
		for(auto p:qy[i])ans[p.second]=b.sum(p.first);
	}
	F(i,0,m)printf("%d\n",ans[i]);
	return 0;
}