#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n,x[100005],y[100005];
bool sign(int t)
{
	return (t>0);
}
bool check(long double r)
{
	vector<pair<long double,long double> > v;
	for (int i=0;i<n;i++)
	{
		long double t=(2.0*r-y[i])*y[i];
		if (t<0)
		return 0;
		long double l=sqrt(t);
		v.push_back({-l+x[i],l+x[i]});
	}
	long double mn=1e18,mx=-1e18;
	for (auto p:v)
	{
		mn=min(mn,p.second);
		mx=max(mx,p.first);
	}
	return (mx<=mn);
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if (sign(y[i])!=sign(y[0]))
		{
			printf("-1");
			return 0;
		}
	}
	for (int i=0;i<n;i++)
	y[i]=abs(y[i]);
	long double st=0.0,en=1e14;
	for (int _=0;_<100;_++)
	{
		long double mid=(st+en)/2;
		if (check(mid))
		en=mid;
		else
		st=mid;
	}
	printf("%.9Lf",st);
}