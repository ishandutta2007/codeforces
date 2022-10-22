#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,m;
long long a[N][N],f[N][N];
long long dp(long long k)
{
	F(i,0,n)F(j,0,m)
	{
		long long d=a[i][j]-i-j-k;
		f[i][j]=LLINF;
		if(d>=0)
		{
			if(i+j!=0)
			{
				if(i&&f[i-1][j]<f[i][j])f[i][j]=f[i-1][j];
				if(j&&f[i][j-1]<f[i][j])f[i][j]=f[i][j-1];
				if(f[i][j]!=LLINF)f[i][j]+=d;
			}
			else f[i][j]=d;
		}
	}
	return f[n-1][m-1];
}
int main()
{
	read(t);
	while(t--)
	{
		long long ans=LLINF;
		read(n);read(m);
		F(i,0,n)F(j,0,m)read(a[i][j]);
		F(i,0,n)F(j,0,m)
		{
			long long tmp=dp(a[i][j]-i-j);
			ans=ans<tmp?ans:tmp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}