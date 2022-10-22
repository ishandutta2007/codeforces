#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=1e5+5,LogN=19;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
long long max(long long a,long long b){return a>b?a:b;}
struct node
{
	long long a,b,c;
	node(long long x=-LLINF,long long y=-LLINF,long long z=-LLINF)
	{
		a=x;b=y;c=z;
	}
	node operator+(node y)const
	{
		return node(max(a,y.a),max(b,y.b),max(max(c,y.c),max(a+y.b,b+y.a)));
	}
}f[8*N];
int n,m,d[N],h[N];
long long p[2*N],a[2*N],b[2*N];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1){f[p]=node(a[l],b[l]);return;}
	build(lc,l,mid);build(rc,mid,r);
	f[p]=f[lc]+f[rc];
}
node query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return node();
	if(x<=l&&r<=y)return f[p];
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
long long query(int x,int y)
{
	node ans=query(0,0,2*n,x,y);
	return ans.c;
}
int main()
{
	read(n);read(m);
	F(i,0,n)read(d[i]);
	F(i,0,n)read(h[i]);
	F(i,0,2*n-1)p[i+1]=p[i]+d[i%n];
	F(i,0,2*n)
	{
		a[i]=p[i]+2*h[i%n];
		b[i]=-p[i]+2*h[i%n];
	}
	build(0,0,2*n);
	while(m--)
	{
		int u,v;
		read(u);read(v);--u;
		u^=v^=u^=v;
		if(v<u)v+=n;
		printf("%lld\n",query(u,v));
	}
	return 0;
}