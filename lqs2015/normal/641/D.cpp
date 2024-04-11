#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-9;
double mx[111111],mn[111111],x[111111],y[111111],n,xx,yy,p,q;
double a,b,c,del,xp,yp;
int main()
{
	scanf("%lf",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&mx[i]);
	for (int i=1;i<=n;i++) scanf("%lf",&mn[i]);
	xx=yy=0.00;
	for (int i=1;i<=n;i++)
	{
		p=mx[i]+mn[i];
		q=mx[i];
		a=1.00;b=yy-xx-p;c=-yy*p+q;
		del=b*b-4*a*c;
		if (del<eps) del=0.00;
		xp=(-b+sqrt(del))/(2*a);
		yp=p-xp;
		if ((1-yy-xp)*yp+(1-xx-yp)*xp+xp*yp-mn[i]>eps) swap(xp,yp);
		if (xp<0) xp=-xp;
		if (yp<0) yp=-yp;
		x[i]=xp;y[i]=yp;
		yy+=x[i];
		xx+=y[i];
	}
	for (int i=1;i<=n;i++)
	printf("%.8lf ",x[i]);
	printf("\n");
	for (int i=1;i<=n;i++)
	printf("%.8lf ",y[i]);
	printf("\n");
	return 0;
}