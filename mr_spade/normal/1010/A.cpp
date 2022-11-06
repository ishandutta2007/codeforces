#include<cstdio>
const double eps=1e-8;
const int N=2005;
int n;
double m;
double a[N],b[N];
inline bool check(double x)
{
	register int i;
	if((x-=x/a[1])<m)
		return false;
	for(i=2;i<=n;i++)
	{
		if((x-=x/b[i])<m)
			return false;
		if((x-=x/a[i])<m)
			return false;
	}
	if((x-=x/b[1])<m)
		return false;
	return true;
}
signed main()
{
	register int i;
	scanf("%d%lf",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%lf",&b[i]);
	check(22);
	double l=0,r=1e12,mid;
	while(r-l>eps)
	{
		mid=(l+r)/2;
		if(check(mid+m))
			r=mid;
		else
			l=mid;
	}
	if(l<1e9)
		printf("%.8lf\n",l);
	else
		puts("-1");
	return 0;
}