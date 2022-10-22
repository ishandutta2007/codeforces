#include<cstdio>
#include<cmath>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("0"),0;
using namespace std;
const int N=2e5+5,lim=1000000,M=(1<<15)+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,mc,md,k,f[M];
long long x,y,z,a[N],c[N],d[N],p[20],ans;
long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}
int main()
{
	int full;
	read(n);read(x);read(y);
	if(y%x)fail;
	z=y/x;
	F(i,0,n)read(a[i]);
	F(i,0,n)if(a[i]%x==0)c[mc++]=a[i]/x;
	F(i,0,n)if(y%a[i]==0)d[md++]=y/a[i];
	for(int i=2;i<lim&&z!=1;++i)if(z%i==0)
	{
		p[k++]=i;
		while(z%i==0)z/=i;
	}
	if(z!=1)
	{
		long long pp=sqrt(z)+0.5;
		if(pp*pp==z)p[k++]=pp;
		for(int i=0;i<mc&&z!=1;++i)
		{
			long long tmp=gcd(c[i],z);
			if(tmp!=1&&tmp!=z)p[k++]=tmp,p[k++]=z/tmp,z=1;
		}
		for(int i=0;i<md&&z!=1;++i)
		{
			long long tmp=gcd(d[i],z);
			if(tmp!=1&&tmp!=z)p[k++]=tmp,p[k++]=z/tmp,z=1;
		}
		if(z!=1)p[k++]=z;
	}
	F(i,0,mc)
	{
		int t=0;
		F(j,0,k)if(c[i]%p[j]==0)t^=1<<j;
		++f[t];
	}
	full=(1<<k)-1;
	F(i,0,md)
	{
		int t=full;
		F(j,0,k)if(d[i]%p[j]==0)t^=1<<j;
		for(int j=t;j;j=(j-1)&t)ans+=f[j];
		ans+=f[0];
	}
	printf("%lld\n",ans);
	return 0;
}