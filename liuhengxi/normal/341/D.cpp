#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5;
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
struct BIT2D
{
	int n;long long a[N][N];
	void add(int x,int y,long long z){for(++x,++y;x<=n;x+=x&-x)for(int u=y;u<=n;u+=u&-u)a[x][u]^=z;}
	long long sum(int x,int y)
	{
		long long z=0;
		for(;x;x-=x&-x)for(int u=y;u;u-=u&-u)z^=a[x][u];
		return z;
	}
}a[4];
#define odd(x) (-(x&1ll))
int n,m;
void add(int x,int y,long long z)
{
	a[0].add(x,y,z);
	a[1].add(x,y,z&odd(x));
	a[2].add(x,y,z&odd(y));
	a[3].add(x,y,z&odd(x)&odd(y));
}
long long sum(int x,int y)
{
	long long z=0;
	z^=a[3].sum(x,y);
	z^=odd(x)&(a[2].sum(x,y)^a[2].sum(n,y));
	z^=odd(y)&(a[1].sum(x,y)^a[1].sum(x,n));
	z^=odd(x)&odd(y)&(a[0].sum(x,y)^a[0].sum(n,y)^a[0].sum(x,n)^a[0].sum(n,n));
	return z;
}
int main()
{
	read(n,m);
	a[0].n=a[1].n=a[2].n=a[3].n=++n;
	while(m--)
	{
		int opt,x0,y0,x1,y1;long long w;read(opt);read(x0,y0,x1,y1);--x0,--y0;
		if(opt==1){w=0;w^=sum(x0,y0);w^=sum(x0,y1);w^=sum(x1,y0);w^=sum(x1,y1);printf("%lld\n",w);}
		if(opt==2){read(w);add(x0,y0,w);add(x0,y1,w);add(x1,y0,w);add(x1,y1,w);}
	}
	return 0;
}