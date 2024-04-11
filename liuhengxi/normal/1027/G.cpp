#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,n1,n2;
long long m,x,phim,pdm[N],dm[N],dphim[N],tmp[N],ans,powx[N];
long long phi(long long x)// x|m
{
	long long ans=x;
	F(i,0,n)if(x%pdm[i]==0)
	{
		while(x%pdm[i]==0)x/=pdm[i];
		ans-=ans/pdm[i];
	}
	return ans;
}
long long mul(long long a,long long b)
{
	long long c=0;
	while(b)
	{
		(c+=(b&0xffff)*a)%=m;
		b>>=16;(a<<=16)%=m;
	}
	return c;
}
long long pow(long long a,long long b)
{
	long long c=1;
	while(b)
	{
		if(b&1)c=mul(c,a);
		a=mul(a,a);b>>=1;
	}
	return c;
}
void getprimedivisor(long long m)
{
	for(int i=2;(long long)i*i<=m;++i)if(m%i==0)
	{
		while(m%i==0)m/=i;
		pdm[n++]=i;
	}
	if(m!=1)pdm[n++]=m;
}
int getdivisor(long long x,long long *d,long long *dd)
{
	int n=0;
	for(int i=1;(long long)i*i<=x;++i)if(x%i==0)d[n]=i,dd[n++]=x/i;
	for(int i=n-1;~i;--i)if(d[n-1]!=dd[i])d[n++]=dd[i];
	return n;
}
int main()
{
	read(m);read(x);
	getprimedivisor(m);
	n1=getdivisor(m,dm,tmp);
	phim=phi(m);
	n2=getdivisor(phim,dphim,tmp);
	F(j,0,n2)powx[j]=pow(x,dphim[j]);
	++ans;
	F(i,0,n1-1)
	{
		long long x=dm[i],f=phi(m/x),p=0;
		F(j,0,n2)if(mul(powx[j],x)==x)
		{
			p=dphim[j];
			break;
		}
		ans+=f/p;
	}
	printf("%lld\n",ans);
	return 0;
}