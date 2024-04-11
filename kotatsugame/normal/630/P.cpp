#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double PI=acos(-1.0);
main()
{
	int n;
	double r;
	cin>>n>>r;
	int k=(n-3)/2;
	cout<<fixed<<setprecision(16)<<n*r*r*sin(PI/n)/cos(PI*k/n)*cos(PI*(k+1)/n)<<endl;
}