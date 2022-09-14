#define _USE_MATH_DEFINES
#include<cstdio>
#include<cmath>
using namespace std;
int N,H;
int x[2<<17],y[2<<17];
long long cross(int i,int j)
{
	long long xi=x[i]-x[N-1];
	long long yi=y[i]-y[N-1]-H;
	long long xj=x[j]-x[N-1];
	long long yj=y[j]-y[N-1]-H;
	return xi*yj-xj*yi;
}
main()
{
	scanf("%d%d",&N,&H);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	int mn=N-1;
	double ans=0;
	for(int i=N-2;i>=0;i--)
	{
		long long t=cross(mn,i);
		if(t==0)
		{
			if(mn==i+1)
			{
				ans+=hypot(x[i]-x[i+1],y[i]-y[i+1]);
			}
			mn=i;
		}
		else if(t<0)
		{
			double theta=atan2(y[N-1]+H-y[mn],x[N-1]-x[mn])-atan2(y[N-1]+H-y[i],x[N-1]-x[i]);
			double l=hypot(y[N-1]+H-y[i],x[N-1]-x[i]);
			double alpha=atan2(y[N-1]+H-y[i],x[N-1]-x[i])-atan2(y[i+1]-y[i],x[i+1]-x[i]);
			ans+=l*sin(theta)/sin(theta+alpha);
			mn=i;
		}
	}
	printf("%.16lf\n",ans);
}