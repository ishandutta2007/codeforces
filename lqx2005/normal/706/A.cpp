#include<bits/stdc++.h>
using namespace std;
const double inf=1000000000;
double a,b;
int n;
double x,y,v;
double dis(double x,double y)
{
	return sqrt(x*x+y*y);
}
int main()
{
	scanf("%lf%lf",&a,&b);
	scanf("%d",&n);
	double ans=inf;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&x,&y,&v);
		double d=dis(x-a,y-b)/v;
		ans=min(ans,d);
	}
	printf("%.10lf\n",ans);
	return 0;
}