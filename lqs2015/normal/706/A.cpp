#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double a,b,n,x,y,v,mn;
const double eps=1e-9;
double ABS(double x)
{
	if (x+eps<0.00) return 0.00-x;
	return x;
}
int main()
{
	mn=1e18;
	scanf("%lf%lf%lf",&a,&b,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&x,&y,&v);
		double xx=sqrt(pow(ABS(a-x),2)+pow(ABS(b-y),2))/v;
		mn=min(mn,xx);
	}
	printf("%.8lf\n",mn);
	return 0;
}