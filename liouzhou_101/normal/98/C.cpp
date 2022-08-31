#include<cstdio>
#include<cmath>
#include<iostream>
#include<iomanip>

using namespace std;

const long double ZERO=1e-12;

long double a,b,l;

long double calc(long double p)
{
	long double x=cos(p),y=sin(p);
	return a*x+b*y-l*x*y;
}

int main()
{
	cin>>a>>b>>l;
	cout<<setprecision(10)<<fixed;
	if (a>b) swap(a,b);
	if (b>=l)
	{
		cout<<min(l,a)<<endl;
		return 0;
	}
	long double L=0,R=(long double)3.1415926535897932384626*0.5;
	while (R-L>ZERO)
	{
		long double d=(R-L)/3;
		long double x=L+d,y=R-d;
		long double fx=calc(x),fy=calc(y);
		if (fx<fy)
			R=y;
		else
			L=x;
	}
	long double w=min(l,calc((L+R)*0.5));
	if (w<=0)
		puts("My poor head =(");
	else
		cout<<w<<endl;
	return 0;
}