#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double a,b,c;
main()
{
	cin>>a>>b>>c;
	double d=sqrt(b*b-4*a*c);
	double x,y;
	if(b>0)x=(-b-d)/2/a;
	else x=(-b+d)/2/a;
	y=-b/a-x;
	if(x<y)
	{
		double t=x;
		x=y;
		y=t;
	}
	cout<<fixed<<setprecision(16)<<x<<endl<<y<<endl;
}