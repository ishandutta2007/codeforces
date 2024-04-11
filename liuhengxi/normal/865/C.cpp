#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=55,M=5105;
const double eps=1e-14;
const double DBINF=1.0/0.0;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x*10)+(c^48);
	if(neg)x=-x;
}
int n,r,a[N],b[N];
double p[N],f[N][M];
double dp(double ans)
{
	F(i,0,n+1)F(j,0,r+101)f[i][j]=ans;
	F(j,0,r+1)f[n][j]=0.0;
	for(int i=n-1;~i;--i)F(j,0,r+1)f[i][j]=min(ans,(f[i+1][j+a[i]]+a[i])*p[i]+(f[i+1][j+b[i]]+b[i])*(1-p[i]));
	return f[0][0];
}
inline double dif(double a,double b){return (a-b)/max(1.0,b);}
double solve()
{
	double l=0,r=1e9,mid;
	while(dif(r,l)>eps)
	{
		mid=(l+r)/2.0;
		if(dif(mid,dp(mid))<eps)l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	read(n);read(r);
	F(i,0,n)read(a[i]),read(b[i]),read(p[i]),p[i]/=100;
	printf("%.12lf\n",solve());
	return 0;
}