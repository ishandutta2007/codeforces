#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int m,d[N],n,p,a[N],q[N],qf,qr;
long long s[N],f[N],g[N],y[N];
inline long long w(int v,int u){return f[v]+(u-v)*(long long)a[u-1]-(s[u]-s[v]);}
inline bool cmp(int a,int b,int c){return (y[b]-y[a])/(double)(b-a)>(y[c]-y[b])/(double)(c-b);}
int main()
{
	read(m);read(n);read(p);
	F(i,1,m)read(d[i]),d[i]+=d[i-1];
	F(i,0,n)
	{
		int h,t;read(h);read(t);--h;
		a[i]=t-d[h];
	}
	sort(a,a+n);
	F(i,0,n)s[i+1]=s[i]+a[i];
	F(i,1,n+1)f[i]=LLINF;
	while(p--)
	{
		g[0]=qf=qr=0;q[qr++]=0;
		F(i,1,n+1)
		{
			while(qf+1<qr&&w(q[qf],i)>w(q[qf+1],i))++qf;
			g[i]=w(q[qf],i);y[i]=f[i]+s[i];
			while(qf+1<qr&&cmp(q[qr-2],q[qr-1],i))--qr;
			q[qr++]=i;
		}
		F(i,0,n+1)f[i]=g[i];
	}
	printf("%lld\n",f[n]);
	return 0;
}