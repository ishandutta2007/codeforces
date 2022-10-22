#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=2e5+5,K=70,INF=0x3fffffff;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
int n,k,q;
struct point
{
	int c[6];
}a[N];
struct value
{
	int v[K];
	value()
	{
		F(i,0,1<<k)v[i]=-INF;
		F(i,1<<k,2<<k)v[i]=INF;
	}
	value(point a)
	{
		F(i,0,1<<k)
		{
			v[i]=0;
			F(j,0,k)v[i]+=(((i>>j&1)<<1)-1)*a.c[j];
			v[i|1<<k]=v[i];
		}
	}
	value operator+(value b)
	{
		value c;
		F(i,0,1<<k)c.v[i]=max(v[i],b.v[i]);
		F(i,1<<k,2<<k)c.v[i]=min(v[i],b.v[i]);
		return c;
	}
	int get()
	{
		int ans=0;
		F(i,0,1<<k)ans=max(ans,v[i]-v[i|1<<k]);
		return ans;
	}
}s[N<<2];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=value(a[l]),void();
	build(lc,l,mid);build(rc,mid,r);
	s[p]=s[lc]+s[rc];
}
void update(int p,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=value(a[l]),void();
	if(x<mid)update(lc,l,mid,x);else update(rc,mid,r,x);
	s[p]=s[lc]+s[rc];
}
value query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return value();
	if(x<=l&&r<=y)return s[p];
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
int main()
{
	read(n);read(k);
	F(i,0,n)F(j,0,k)read(a[i].c[j]);
	build(1,0,n);
	read(q);
	while(q--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int x;--read(x);
			F(i,0,k)read(a[x].c[i]);
			update(1,0,n,x);
		}
		if(opt==2)
		{
			int x,y;--read(x);read(y);
			printf("%d\n",query(1,0,n,x,y).get());
		}
	}
	return 0;
}