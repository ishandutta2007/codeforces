#include<cstdio>
#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		long double R,r,k;
		cin>>R>>r>>k;
		long double x0=(R+r)/(4*R*r);
		long double r0=(R-r)/(4*R*r);
		long double y0=k*r0*2;
		cout<<setprecision(10)<<fixed<<r0/(x0*x0+y0*y0-r0*r0)<<endl;
	}
	return 0;
}