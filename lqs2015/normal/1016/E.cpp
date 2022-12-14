#include<iostream>
#include<cstdio>
using namespace std;
const double eps=1e-9;
double l[222222],r[222222],y0,xl,xr,x,y,x1,x2,k,b,sum[222222],cur,ll,rr;
int n,q,pl,pr;
int main()
{
	scanf("%lf%lf%lf",&y0,&xl,&xr);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&l[i],&r[i]);
	}
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+r[i]-l[i];
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lf%lf",&x,&y);
		if (x-xl>-eps && x-xl<eps)
		{
			x1=x;
		}
		else
		{
			k=(y-y0)/(x-xl);
			x1=x-y/k;
		}
		if (x-xr>-eps && x-xr<eps)
		{
			x2=x;
		}
		else
		{
			k=(y-y0)/(x-xr);
			x2=x-y/k;
		}
		cur=0.00;
		pl=lower_bound(l+1,l+n+1,x1)-l;
		pr=lower_bound(l+1,l+n+1,x2)-l-1;
		if (pl-1==pr)
		{
			if (r[pl-1]<x2) rr=r[pl-1];
			else rr=x2;
			if (l[pl-1]>x1) ll=l[pl-1];
			else ll=x1;
			if (ll>rr) cur=0.00;
			else cur=rr-ll;
		}
		else
		{
			if (pl>1 && r[pl-1]>x1) cur+=(r[pl-1]-x1);
			if (r[pr]>x2)
			{
				cur+=(x2-l[pr]);
				pr--;
			}
			if (pl<=pr) cur+=(sum[pr]-sum[pl-1]);
		}
		cur=cur/y*(y-y0);
		printf("%.9lf\n",cur);
	}
	return 0;
}