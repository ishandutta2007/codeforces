#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=20,M=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m;unsigned long long c[1<<N],d[1<<N],ans=-1;
char s[N][M];
void fwt(unsigned long long *a,int n,int m/*m = log n*/)
{
	F(k,0,m)
	{
		unsigned half=1<<k,size=2<<k,i;
		unsigned long long *u,*v,tmp;
		for(int j=0;j<n;j+=size)
			for(i=0,u=a+j,v=a+j+half;i<half;++i,++u,++v)
			{
				tmp=*v;
				*v=*u-*v;
				*u+=tmp;
			}
	}
}
void ifwt(unsigned long long *a,int n,int m/*m = log n*/)
{
	F(k,0,m)
	{
		unsigned half=1<<k,size=2<<k,i;
		unsigned long long *u,*v,tmp;
		for(int j=0;j<n;j+=size)
			for(i=0,u=a+j,v=a+j+half;i<half;++i,++u,++v)
			{
				tmp=*v;
				*v=*u-*v;
				*u+=tmp;
			}
	}
}
int main()
{
	read(n);read(m);
	F(i,0,n)scanf("%s",s[i]);
	F(i,0,m)
	{
		int mask=0;
		F(j,0,n)mask|=(s[j][i]^48)<<j;
		++c[mask];
	}
	F(i,0,1<<n)d[i]=__builtin_popcount(i),d[i]=min(d[i],n-d[i]);
	fwt(c,1<<n,n);
	fwt(d,1<<n,n);
	F(i,0,1<<n)c[i]*=d[i];
	ifwt(c,1<<n,n);
	F(i,0,1<<n)ans=min(ans,c[i]>>=n);
	printf("%llu\n",ans);
	return 0;
}