#include<iostream>
#include<cstdio>
using namespace std;
const double eps=1e-9;
double l,r,mid,wt,a[1111],b[1111],cur;
int n,m,cnt;
bool check(double mid)
{
	cur=mid;
	cur-=(wt+cur)/a[1];
	if (cur<0.00) return 0;
	for (int i=2;i<=n;i++)
	{
		cur-=(wt+cur)/b[i];
		if (cur<0.00) return 0;
		cur-=(wt+cur)/a[i];
		if (cur<0.00) return 0;
	}
	cur-=(wt+cur)/b[1];
	if (cur<0.00) return 0;
	return 1;
}
int main()
{
	//freopen("cin.txt","r",stdin);
	scanf("%d%d",&n,&m);
	wt=(double)m;
	for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lf",&b[i]);
	l=0.00;r=1000000010.00;
	while(r-l>eps)
	{
		cnt++;
		if (cnt>1000)
		{
			printf("%.9lf\n",l);
			return 0;
		}
		mid=(l+r)/2.00;
		if (check(mid)) r=mid;
		else l=mid;
	}
	if (l>1000000001.00) printf("-1\n");
	else printf("%.9lf\n",l);
	return 0;
}