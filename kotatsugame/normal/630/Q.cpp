#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double a,b,c;
main()
{
	cin>>a>>b>>c;
	double v1=sqrt(2)/12*a*a*a;
	double v2=sqrt(2)/6*b*b*b;
	double s3=c*c/4*sqrt(25+10*sqrt(5));
	double h=0.5257311121191458*c;
	double v3=s3*h/3;
	cout<<fixed<<setprecision(16)<<v1+v2+v3<<endl;
}