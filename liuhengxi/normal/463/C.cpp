#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N][N],x0,y0,x1,y1;
long long b[2*N],c[2*N],d0=-1,d1=-1;
int main()
{
	read(n);
	F(i,0,n)F(j,0,n)read(a[i][j]);
	F(i,0,n)F(j,0,n)
	{
		b[i+j]+=a[i][j];
		c[i-j+n]+=a[i][j];
	}
	F(i,0,n)F(j,0,n)
	{
		int g=(i^j)&1;
		long long now=b[i+j]+c[i-j+n]-a[i][j];
		if(g==0)
		{
			if(now>d0)d0=now,x0=i,y0=j;
		}
		else
		{
			if(now>d1)d1=now,x1=i,y1=j;
		}
	}
	printf("%lld\n",d0+d1);
	printf("%d %d %d %d\n",x0+1,y0+1,x1+1,y1+1);
	return 0;
}