#include<cstdio>
#include<iostream>

using namespace std;

const long double ZERO=1e-12;

long double t1,t2,xa,ya,xb,yb,xc,yc,d1,d2;

long double getabs(long double x)
{
	return (x>=0)?x:-x;
}

long double sqrt(long double x)
{
	if (x<=0) return 0;
	long double t=x;
	for (int i=1;i<=2000;++i)
	{
		t-=(t*t-x)/2/t;
		if (getabs(t*t-x)<=ZERO) break;
	}
	return t;
}

long double getdis(long double x1,long double y1,long double x2,long double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool in_circle(long double px,long double py,long double x,long double y,long double r)
{
	return getdis(px,py,x,y)<=r+ZERO;
}

bool check(long double xa,long double ya,long double ra,long double xb,long double yb,long double rb,long double xc,long double yc,long double rc)
{
	if (ZERO+ra+rb<getdis(xa,ya,xb,yb)) return false;
	if (ZERO+ra+rc<getdis(xa,ya,xc,yc)) return false;
	if (ZERO+rb+rc<getdis(xb,yb,xc,yc)) return false;
	if (ra<rb)
	{
		swap(xa,xb);
		swap(ya,yb);
		swap(ra,rb);
	}
	if (getdis(xa,ya,xb,yb)<=ra-rb)
		return true;
	if (ra>rb)
	{
		swap(xa,xb);
		swap(ya,yb);
		swap(ra,rb);
	}
	if (xa==xb)
	{
		long double py=(ra*ra-rb*rb+yb*yb-ya*ya)/(yb-ya)/2;
		long double x1=xa+sqrt(ra*ra-(py-ya)*(py-ya)),x2=xa-sqrt(ra*ra-(py-ya)*(py-ya));
		return in_circle(x1,py,xc,yc,rc)||in_circle(x2,py,xc,yc,rc);
	}
	long double a=2*(xb-xa),b=2*(yb-ya),c=ra*ra-rb*rb+xb*xb+yb*yb-xa*xa-ya*ya;
	long double A=a*a+b*b,B=-2*(b*(c-a*xa)+a*a*ya),C=(c-a*xa)*(c-a*xa)+a*a*ya*ya-a*a*ra*ra;
	long double s=sqrt(B*B-4*A*C+ZERO);
	long double y1=(-B+s)/2/A,y2=(-B-s)/2/A;
	long double x1=(-b*y1+c)/a,x2=(-b*y2+c)/a;
	return in_circle(x1,y1,xc,yc,rc)||in_circle(x2,y2,xc,yc,rc);
}

bool check(long double x)
{
	if (check(xa,ya,x,xb,yb,d1+t1-x,xc,yc,d2+t2-x)) return true;
	if (check(xa,ya,x,xc,yc,d2+t2-x,xb,yb,d1+t1-x)) return true;
	if (check(xb,yb,d1+t1-x,xc,yc,d2+t2-x,xa,ya,x)) return true;
	return false;
}

int main()
{
	cin>>t1>>t2>>xa>>ya>>xc>>yc>>xb>>yb;
	d1=getdis(xa,ya,xb,yb);
	d2=getdis(xa,ya,xc,yc);
	if (d1+getdis(xb,yb,xc,yc)<=d2+t2+ZERO)
	{
		printf("%.10lf\n",(double)min(d1+getdis(xb,yb,xc,yc)+t1,d2+t2));
		return 0;
	}
	long double L=0,R=min(d1+t1,d2+t2),ans=0;
	while (R-L>ZERO)
	{
		long double x=(L+R)*0.5;
		if (check(x))
		{
			ans=x;
			L=x;
		}
		else
			R=x;
	}
	printf("%.10lf\n",(double)ans);
	return 0;
}