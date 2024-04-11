#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e7+5,M=2.5e5+5;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],l[N],r[N],sta[N],top;
long long c[N],f[N],g[N];
namespace input
{
	int n,m,q,p[M],a[M],c[M];
	void main()
	{
		read(n);read(m);
		::n=m;
		F(i,0,n)
		{
			int k;read(k);
			p[i+1]=p[i]+k;
			F(j,p[i],p[i+1])read(a[j]);
			F(j,p[i],p[i+1])read(c[j]);
		}
		read(q);
		for(int i=0;q--;)
		{
			int id,mul;read(id);--id;read(mul);
			F(j,p[id],p[id+1])::a[i]=a[j],::c[i]=c[j]*(long long)mul,++i;
		}
	}
}
inline void getlr()
{
	l[0]=0;
	sta[top++]=0;
	F(i,1,n)
	{
		l[i]=i-a[i]+1;
		if(l[i]<0)l[i]=0;
		while(top&&l[sta[top-1]]>=l[i])--top;
		while(top&&sta[top-1]>=l[i])l[i]=l[sta[--top]];
		sta[top++]=i;
	}
	top=0;
	r[n-1]=n-1;
	sta[top++]=n-1;
	for(int i=n-2;~i;--i)
	{
		r[i]=i+a[i]-1;
		if(r[i]>=n)r[i]=n-1;
		while(top&&r[sta[top-1]]<=r[i])--top;
		while(top&&sta[top-1]<=r[i])r[i]=r[sta[--top]];
		sta[top++]=i;
	}
}
inline void dp()
{
	f[0]=0;g[0]=c[0];
	top=0;
	sta[top++]=0;
	F(i,1,n+1)
	{
		while(top&&r[sta[top-1]]<i)--top;
		f[i]=min(min(f[l[i-1]]+c[i-1],g[i-1]),top?g[sta[top-1]]:LLINF);
		g[i]=min(f[i]+c[i],top?g[sta[top-1]]:LLINF);
		sta[top++]=i;
	}
}
int main()
{
	input::main();
	getlr();
	dp();
	printf("%lld\n",f[n]);
	return 0;
}