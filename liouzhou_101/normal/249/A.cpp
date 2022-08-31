#include<cstdio>
#include<cmath>
#include<iostream>
#include<iomanip>

using namespace std;

long double yw,r;

bool check(long double x1,long double y1,long double x2,long double y2,long double py)
{
	long double A=y1-y2;
	long double B=x2-x1;
	long double C=-x1*A-y1*B;
	long double d=B*py+C;
	if (d<0) d=-d;
	if (d/sqrt(A*A+B*B)>r)
	{
		cout<<setprecision(20)<<fixed<<(-B*yw-C)/A-1e-9*5<<endl;
		return true;
	}
	return false;
}

int main()
{
	long double y1,y2,xb,yb;
	cin>>y1>>y2>>yw>>xb>>yb>>r;
	yw-=r;
	yb=2*yw-yb;
	if (!check(xb,yb,0,y1+r,y2))
		puts("-1");
	return 0;
}