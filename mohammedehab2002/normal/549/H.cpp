#include <iostream>
using namespace std;
double a,b,c,d;
pair<double,double> ret;
bool go(double x)
{
	ret.first=min(ret.first,x);
	ret.second=max(ret.second,x);
}
pair<double,double> get(double f,double s,double m)
{
	ret={4e18,-4e18};
	go((f+m)*(s+m));
	go((f-m)*(s+m));
	go((f+m)*(s-m));
	go((f-m)*(s-m));
	return ret;
}
bool check(double mid)
{
	auto p1=get(a,d,mid),p2=get(b,c,mid);
	return (p1.first-p2.second<=0 && p1.second-p2.first>=0);
}
int main()
{
	cin >> a >> b >> c >> d;
	double st=0,en=1e9;
	for (int i=0;i<100;i++)
	{
		double mid=(st+en)/2;
		if (check(mid))
		en=mid;
		else
		st=mid;
	}
	printf("%.9lf",st);
}