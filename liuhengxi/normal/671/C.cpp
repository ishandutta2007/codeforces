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
constexpr int N=2e5+5,INF=0x3fffffff;
namespace seg
{
	#define lc (p<<1)
	#define rc (p<<1|1)
	constexpr int N=(1<<19)+5;
	struct data
	{
		int tag,max,cnt,semax;
		long long sum;
		data &operator=(int b)
		{
			max=b;cnt=1;semax=-INF;sum=b;
			return *this;
		}
	}s[N];
	int n;
	void update(data a,data b,data &c)
	{
		c.max=max(a.max,b.max);
		c.semax=max(a.semax,b.semax);
		if(a.max!=b.max)c.semax=max(c.semax,min(a.max,b.max));
		c.cnt=a.cnt*(a.max==c.max)+b.cnt*(b.max==c.max);
		c.sum=a.sum+b.sum;
	}
	data &operator*=(data &a,int b)
	{
		if(b<a.max)a.sum-=(long long)(a.max-b)*a.cnt,a.max=b,a.tag=min(a.tag,b);
		return a;
	}
	void pushdown(int p)
	{
		s[lc]*=s[p].tag;
		s[rc]*=s[p].tag;
		s[p].tag=INF;
	}
	void build(int p,int l,int r)
	{
		int mid=(l+r)>>1;
		s[p].tag=INF;
		if(r-l==1)return s[p]=l+1,void();
		build(lc,l,mid);build(rc,mid,r);
		update(s[lc],s[rc],s[p]);
	}
	void update(int p,int l,int r,int x,int y,int v)
	{
		if(x==l&&r==y&&v>s[p].semax)return s[p]*=v,void();
		if(r-l==1)return s[p]=min(s[p].max,v),void();
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)update(lc,l,mid,x,y,v);
		else if(mid<=x)update(rc,mid,r,x,y,v);
		else update(lc,l,mid,x,mid,v),update(rc,mid,r,mid,y,v);
		update(s[lc],s[rc],s[p]);
	}
	void build(int n_){build(1,0,n=n_);}
	void update(int x,int y,int v){if(x<y)update(1,0,n,x,y,v);}
	long long query(){return s[1].sum;}
	#undef lc
	#undef rc
}
using seg::build;
using seg::update;
using seg::query;
int n,m,a[N];
long long ans;
vector<int> pos[N],factor[N];
int main()
{
	read(n);
	F(i,0,n)read(a[i]),m=max(m,a[i]+1);
	F(i,1,m)for(int j=i;j<m;j+=i)factor[j].emplace_back(i);
	F(i,0,n)for(int x:factor[a[i]])pos[x].emplace_back(i);
	build(n);
	for(int i=m;--i;)
	{
		int l=(int)pos[i].size();
		if(l==2)
		{
			update(0,pos[i][0],0);
			update(pos[i][0]+1,pos[i][1],pos[i][0]+1);
			update(pos[i][1],n,pos[i][1]+1);
		}
		else if(l>=3)
		{
			update(0,pos[i][l-2],0);
			update(pos[i][0]+1,pos[i][l-1],pos[i][0]+1);
			update(pos[i][1],n,pos[i][1]+1);
		}
		ans+=(n*(n+1ll)>>1)-query();
	}
	printf("%lld\n",ans);
	return 0;
}