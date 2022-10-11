#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
double f(double x)
{
	double mx=0,mn=0,cur=0,ret=0;
	for (int i=1;i<=n;i++)
	{
		cur+=a[i]-x;
		ret=max(ret,abs(cur-mn));
		ret=max(ret,abs(cur-mx));
		mn=min(mn,cur);
		mx=max(mx,cur);
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	double st=-1e4,en=1e4;
	for (int i=0;i<100;i++)
	{
		double l=(en-st)/3;
		if (f(st+l)>f(en-l))
		st+=l;
		else
		en-=l;
	}
	printf("%.9lf",f(st));
}