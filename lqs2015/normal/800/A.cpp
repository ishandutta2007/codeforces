#include<bits/stdc++.h>
using namespace std;
int n;
double p,a[111111],b[111111],l,r,mid;
bool check(double mid)
{
	double res=0.00,cur;
	for (int i=1;i<=n;i++)
	{
		cur=a[i]*mid-b[i];
		if (cur>0.00) res+=cur;
	}
	return (mid>=res/p);
}
int main()
{
	scanf("%d%lf",&n,&p);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i],&b[i]);
	}
	l=0;r=1e12;
	for (int i=1;i<=200;i++)
	{
		mid=(l+r)/2.00;
		if (check(mid)) l=mid;
		else r=mid;
	}
	if (l>1e11) printf("-1\n");
	else printf("%.9lf\n",l);
	return 0;
}