#include<cstdio>
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
constexpr int N=1e5+5;
int m;long long b[N];
namespace segtree
{
	#define lc (p<<1)
	#define rc (p<<1|1)
	const int &n=::m;
	constexpr const long long *arr=b;
	struct data{long long cnt,max,sum,wsum;};
	struct tag{long long add;};
	data operator+(data a,data b){return {a.cnt+b.cnt,b.max,a.sum+b.sum,a.wsum+b.wsum+a.sum*b.cnt};}
	data operator*(tag a,data b){return {b.cnt,a.add+b.max,a.add*b.cnt+b.sum,a.add*(b.cnt*(b.cnt+1)>>1)+b.wsum};}
	tag operator+(tag a,tag b){return {a.add+b.add};}
	data a[(1<<18)+5];
	tag b[(1<<18)+5];
	void build(int p,int l,int r)
	{
		if(r-l==1)
		{
			a[p]=data({1,arr[l],arr[l],arr[l]});
			return;
		}
		int mid=(l+r)>>1;
		build(lc,l,mid);build(rc,mid,r);
		a[p]=a[lc]+a[rc];
	}
	inline void update(int p,const tag &v){a[p]=v*a[p],b[p]=v+b[p];}
	inline void pushdown(const int &p)
	{
		update(lc,b[p]);update(rc,b[p]);
		b[p].add=0;
	}
	void update(int p,int l,int r,int x,int y,const tag &v)
	{
		if(x==l&&r==y)return update(p,v);
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)update(lc,l,mid,x,y,v);
		else if(mid<=x)update(rc,mid,r,x,y,v);
		else update(lc,l,mid,x,mid,v),update(rc,mid,r,mid,y,v);
		a[p]=a[lc]+a[rc];
	}
	data query(int p,int l,int r,int x,int y)
	{
		if(x==l&&r==y)return a[p];
		int mid=(l+r)>>1;
		if(y<=mid)return query(lc,l,mid,x,y);
		if(mid<=x)return query(rc,mid,r,x,y);
		return query(lc,l,mid,x,mid)+query(rc,mid,r,mid,y);
	}
	int lower_bound(int p,int l,int r,const long long &v)
	{
		if(r-l==1)return l+(a[p].sum<v);
		int mid=(l+r)>>1;
		pushdown(p);
		if(a[lc].max<v)return lower_bound(rc,mid,r,v);
		return lower_bound(lc,l,mid,v);
	}
	void build(){build(1,0,n);}
	void update(int x,int y,tag v){if(x<y)update(1,0,n,x,y,v);}
	data query(int x,int y){return x<y?query(1,0,n,x,y):data({0,0,0,0});}
	int lower_bound(long long v){return lower_bound(1,0,n,v);}
	#undef lc
	#undef rc
}
using segtree::data;
int n,q;
long long a[N],a0,b0;
int main()
{
	read(n,m,q);
	F(i,0,n)read(a[i]);
	F(i,0,m)read(b[i]);
	a0=a[0];b0=b[0];
	for(int i=n;--i;)a[i]-=a[i-1];
	for(int i=m;--i;)b[i]-=b[i-1];
	F(i,0,n-1)a[i]=a[i+1];
	F(i,0,m-1)b[i]=b[i+1];
	--n,--m;
	segtree::build();
	while(q--)
	{
		int type,k,d;read(type,k,d);
		if(type==1)
		{
			k=n-k;
			if(k<0)a0+=d,k=0;
			F(i,k,n)a[i]+=d;
		}
		if(type==2)
		{
			k=m-k;
			if(k<0)b0+=d,k=0;
			segtree::update(k,m,{d});
		}
		data res={0,0,0,0};
		int last=0,now=0;
		F(i,0,n)
		{
			now=segtree::lower_bound(a[i]);
			res=res+segtree::query(last,now);
			res=res+data({1,a[i],a[i],a[i]});
			last=now;
		}
		res=res+segtree::query(last,m);
		printf("%lld\n",(n+m+1)*(a0+b0)+res.wsum);
	}
	return 0;
}