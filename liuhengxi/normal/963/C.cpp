#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("0"),0
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,aa[N],bb[N],carda,cardb;
long long a[N],b[N],c[N],cnta[N],cntb[N],a1[N],b1[N],ans=1;
int disc(long long x,long long *a)
{
	int l=0,r=n,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(x<a[mid])r=mid;
		else l=mid;
	}
	return l;
}
long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}
int main()
{
	long long g=0;
	read(n);
	F(i,0,n)read(a[i]),read(b[i]),read(c[i]);
	F(i,0,n)a1[i]=a[i],b1[i]=b[i];
	sort(a1,a1+n);sort(b1,b1+n);
	F(i,0,n)if(i==0||a1[i]!=a1[i-1])++carda;
	F(i,0,n)if(i==0||b1[i]!=b1[i-1])++cardb;
	if(carda*cardb!=n)fail;
	F(i,0,n)aa[i]=disc(a[i],a1);
	F(i,0,n)bb[i]=disc(b[i],b1);
	F(i,0,n)cnta[aa[i]]+=c[i],cntb[bb[i]]+=c[i];
	F(i,0,n)g=gcd(cnta[i],g);
	F(i,0,n)cnta[i]/=g;
	g=0;
	F(i,0,n)g=gcd(cntb[i],g);
	F(i,0,n)cntb[i]/=g;
	g=0;
	F(i,0,n)
	{
		long long t=cnta[aa[i]]*cntb[bb[i]];
		if(c[i]%t)fail;
		if(i==0)g=c[i]/t;
		else if(c[i]/t!=g)fail;
	}
	for(long long i=2;g!=1&&i*i<=g;++i)
	{
		int t=0;
		for(;g%i==0;++t)g/=i;
		ans*=(t+1);
	}
	if(g!=1)ans*=2;
	printf("%lld\n",ans);
	return 0;
}