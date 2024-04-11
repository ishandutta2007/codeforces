#include<cstdio>
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
constexpr int N=1e5+5;
constexpr long long p42[12]={1,42,1764,74088,3111696,130691232,5489031744,230539333248,9682651996416,406671383849472,
17080198121677824,717368321110468608},h=1ll<<63;
long long nextp42(long long x){return *lower_bound(p42,p42+12,x);}
namespace seg
{
	struct data{long long val,tag,dis;bool issame;}s[(1<<18)+5];
#define lc (p<<1)
#define rc (p<<1|1)
#define val(x) s[x].val
#define tag(x) s[x].tag
#define dis(x) s[x].dis
#define issame(x) s[x].issame
	inline void add(int p,long long v){val(p)+=v;tag(p)+=v;dis(p)-=v;}
	inline void assign(int p,long long v){val(p)=v;tag(p)=v^h;dis(p)=nextp42(v)-v;}
	inline void assign(int p,long long v,long long d){val(p)=v;tag(p)=v^h;dis(p)=d;}
	inline void pushdown(int p)
	{
		if(tag(p)<0)assign(lc,tag(p)^h,dis(p)),assign(rc,tag(p)^h,dis(p));
		else add(lc,tag(p)),add(rc,tag(p));
		tag(p)=0;
	}
	inline void pushup(int p){dis(p)=min(dis(lc),dis(rc));val(p)=val(lc);issame(p)=issame(lc)&&issame(rc)&&val(lc)==val(rc);}
	void build(int p,int l,int r,int *a)
	{
		if(r-l==1)return issame(p)=true,assign(p,a[l]);
		int mid=(l+r)>>1;
		build(lc,l,mid,a);
		build(rc,mid,r,a);
		pushup(p);
	}
	void assign(int p,int l,int r,int x,int y,int v,long long d)
	{
		if(x==l&&r==y)return issame(p)=true,assign(p,v,d);
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)assign(lc,l,mid,x,y,v,d);
		else if(mid<=x)assign(rc,mid,r,x,y,v,d);
		else assign(lc,l,mid,x,mid,v,d),assign(rc,mid,r,mid,y,v,d);
		pushup(p);
	}
	void update(int p,int l,int r,int x,int y,int v)
	{
		if(r-l==1)return val(p)+=v,dis(p)=nextp42(val(p))-val(p),void();
		if(x==l&&r==y)
		{
			if(dis(p)>=v)return add(p,v);
			if(issame(p))return assign(p,val(p)+v);
			int mid=(l+r)>>1;
			pushdown(p);
			update(lc,l,mid,l,mid,v);
			update(rc,mid,r,mid,r,v);
			pushup(p);
			return;
		}
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)update(lc,l,mid,x,y,v);
		else if(mid<=x)update(rc,mid,r,x,y,v);
		else update(lc,l,mid,x,mid,v),update(rc,mid,r,mid,y,v);
		pushup(p);
	}
	long long query(int p,int l,int r,int x)
	{
		if(r-l==1)return val(p);
		int mid=(l+r)>>1;
		pushdown(p);
		if(x<mid)return query(lc,l,mid,x);
		else return query(rc,mid,r,x);
	}
#undef lc
#undef rc
#undef val
#undef tag
#undef dis
#undef issame
}
int n,q,a[N];
int main()
{
	read(n,q);
	F(i,0,n)read(a[i]);
	seg::build(1,0,n,a);
	while(q--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int i;read(i);--i;
			printf("%lld\n",seg::query(1,0,n,i));
		}
		if(opt==2)
		{
			int l,r,x;read(l,r,x);--l;
			seg::assign(1,0,n,l,r,x,nextp42(x)-x);
		}
		if(opt==3)
		{
			int l,r,x;read(l,r,x);--l;
			seg::update(1,0,n,l,r,x);
			while(seg::s[1].dis==0)seg::update(1,0,n,l,r,x);
		}
	}
	return 0;
}