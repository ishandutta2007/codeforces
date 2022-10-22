#include<cstdio>
#include<cstring>
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
constexpr int N=2e5+5;
int n;
namespace BIT
{
	int c[N];
	void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]^=y;}
	int sum(int x)
	{
		int ans=0;
		for(;x;x-=x&-x)ans^=c[x];
		return ans;
	}
}
namespace seg
{
	struct data
	{
		int a[32];
		void init(int x){memset(a,0,sizeof a);if(x)a[31-__builtin_clz(x)]=x;}
		void join(const data &b)
		{
			for(int i=30;~--i;)if(b.a[i])
			{
				int x=b.a[i];
				for(int j=i;~j;--j)if(x>>j&1)
				{
					if(a[j])x^=a[j];
					else
					{
						a[j]=x;
						break;
					}
				}
			}
		}
	}s[(1<<19)+5];
#define lc (p<<1)
#define rc (p<<1|1)
	int n,d[N];
	void build(int p,int l,int r,int f(int))
	{
		if(r-l==1)return s[p].init(d[l]=f(l));
		int mid=(l+r)>>1;
		build(lc,l,mid,f);build(rc,mid,r,f);
		s[p]=s[lc];
		s[p].join(s[rc]);
	}
	void update(int p,int l,int r,int x,int v)
	{
		if(r-l==1)return s[p].init(d[l]^=v);
		int mid=(l+r)>>1;
		if(x<mid)update(lc,l,mid,x,v);
		else update(rc,mid,r,x,v);
		s[p]=s[lc];
		s[p].join(s[rc]);
	}
	void query(int p,int l,int r,int x,int y,data &dst)
	{
		if(x==l&&r==y)return dst.join(s[p]);
		int mid=(l+r)>>1;
		if(y<=mid)return query(lc,l,mid,x,y,dst);
		if(mid<=x)return query(rc,mid,r,x,y,dst);
		query(lc,l,mid,x,mid,dst);query(rc,mid,r,mid,y,dst);
	}
#undef lc
#undef rc
	void build(int f(int)){build(1,0,n,f);}
	void update(int x,int v){update(1,0,n,x,v);}
	void query(int x,int y,data &dst){query(1,0,n,x,y,dst);}
}
using BIT::add;using BIT::sum;
using seg::build;using seg::update;using seg::query;
int q,a[N];
int main()
{
	read(n,q);
	F(i,0,n)read(a[i]);
	if(n==1)
	{
		int t,l,r,k;
		while(q--)if(read(t)==1)read(l,r,k),a[0]^=k;else read(l,r),printf("%d\n",1+!!a[0]);
		return 0;
	}
	seg::n=n-1;
	build([](int x){return a[x]^a[x+1];});
	while(q--)
	{
		int t;read(t);
		if(t==1)
		{
			int l,r,k;read(l,r,k);--l;
			add(l,k);
			add(r,k);
			if(l)update(l-1,k);
			if(r!=n)update(r-1,k);
		}
		if(t==2)
		{
			int l,r;read(l,r);--l;
			int f=sum(l+1)^a[l];
			if(r-l==1)printf("%d\n",1+!!f);
			else
			{
				seg::data res;res.init(f);
				query(l,r-1,res);
				int ans=1;
				F(i,0,30)ans<<=!!res.a[i];
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}