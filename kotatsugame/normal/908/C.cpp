#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int n;double r,x[1010],y[1010];
double f(int i,int j)
{
	double bit=x[i]-x[j];
	if(bit<0)bit=-bit;
	double nowy=sqrtl(4*r*r-bit*bit);
	return nowy+y[j];
}
main()
{
	cin>>n>>r;
	for(int i=0;i<n;i++)cin>>x[i];
	y[0]=r;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			double bit=x[i]-x[j];
			if(bit<0)bit=-bit;
			if(bit>2*r)continue;
			double nowy=f(i,j);
			if(y[i]<nowy)y[i]=nowy;
		}
		if(y[i]<=0)y[i]=r;
	}
	for(int i=0;i<n;i++)
	{
		cout<<fixed<<setprecision(9)<<y[i];
		cout<<(i==n-1?"\n":" ");
	}
}