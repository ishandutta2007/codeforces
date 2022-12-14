#include<iostream>
#include<cstdio>
using namespace std;
double eps=1e-9;
int n,u,a[111111],p[111111],h,k[111111];
double ans,cur;
int main()
{
	scanf("%d%d",&n,&u);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) p[i]=a[i+1]-a[i];
	for (int i=1;i<n;i++)
	{
		h=lower_bound(a+1,a+n+1,a[i]+u)-a;
		if (h>n || a[h]-a[i]>u) h--;
		if (h<=i+1) k[i]=-1;
		else k[i]=a[h]-a[i];
	}
	ans=-1.00;
	for (int i=1;i<n;i++)
	{
		if (k[i]!=-1) 
		{
			cur=1.00-(double)p[i]/(double)k[i];
			if (ans<cur) ans=cur;
		}
	}
	if (ans>-1.00-eps && ans<-1.00+eps) printf("-1\n");
	else printf("%.9lf\n",ans);
	return 0;
}