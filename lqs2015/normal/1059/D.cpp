#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,cnt;
bool f1,f2;
long double x[111111],y[111111],l,r,mid,rad,curl,curr;
const long double eps=1e-11;
bool check(long double R)
{
	curl=-1e18;curr=1e18;
	for (int i=1;i<=n;i++)
	{
		rad=2.00*y[i]*R-y[i]*y[i];
		if (rad<eps) return 0;
		rad=sqrt(rad);
		curl=max(curl,x[i]-rad);
		curr=min(curr,x[i]+rad);
	}
	return (curl<=curr-eps);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%Lf%Lf",&x[i],&y[i]);
		if (y[i]<0) f1=1;
		else f2=1;
	}
	if (f1 && f2) 
	{
		printf("-1\n");
		return 0;
	}
	l=0;r=100000000000000.00;
	while(r-l>1e-7)
	{
		mid=(l+r)/2.00;
		cnt++;
		if (cnt>200) break;
		if (check(mid) || check(-mid)) r=mid;
		else l=mid;
	}
	printf("%.7Lf\n",l);
	return 0;
}