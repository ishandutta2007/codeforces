#include<cstdio>
#include<cmath>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5;
const double eps=1e-9;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,s,a[N],b[N],pre[N],ans[N],len;
double dis[N];
double dist(int u,int v,double r=0.0)
{
	return sqrt(abs(a[v]-a[u]-s))-r*b[v];
}
bool check(double r)
{
	F(i,1,n)pre[i]=0,dis[i]=dist(0,i,r);
	F(i,2,n)F(j,1,i)if(dis[j]+dist(j,i,r)<dis[i])
	{
		dis[i]=dis[j]+dist(j,i,r);
		pre[i]=j;
	}
	return dis[n-1]<=0.0;
}
double solve()
{
	double l=0.0,r=dist(0,n-1)/b[n-1],mid;
	while(r-l>eps)
	{
		mid=(l+r)/2.0;
		if(check(mid))r=mid;
		else l=mid;
	}
	return l;
}
int main()
{
	read(n);read(s);
	F(i,1,++n)read(a[i]),read(b[i]);
	check(solve());
	for(int j=n-1;j;j=pre[j])ans[len++]=j;
	while(len--)printf("%d ",ans[len]);
	printf("\n");
	return 0;
}