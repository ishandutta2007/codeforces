#include<iostream>
#include<cstdio>
using namespace std;
double n,x[66666],v[66666],l,r,u,d,cu,cd;
int main()
{
	scanf("%lf",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf",&x[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lf",&v[i]);
	}
	l=0;r=1e17;
	while(l<=r)
	{
		long long m=(l+r)/2;
		double mid=m,mm=mid/100000000.00;
		u=x[1]+v[1]*mm;d=x[1]-v[1]*mm;
		for (int i=2;i<=n;i++)
		{
			cu=x[i]+v[i]*mm;cd=x[i]-v[i]*mm;
			u=min(u,cu);
			d=max(d,cd);
		}
		if (d>u) l=mid+1.00;
		else r=mid-1.00;
	}
	printf("%.8lf",l/100000000.00);
	return 0;
}