#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=200010;
int n,a[MAXN];
double L,R,s[MAXN];
double calc(double x)
{
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i]-x;
	double Min=0,Max=0,res=0;
	for(int i=1;i<=n;i++)
	{
		res=max(res,fabs(s[i]-Min));
		res=max(res,fabs(s[i]-Max));
		Min=min(Min,s[i]);
		Max=max(Max,s[i]);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	L=-10000,R=10000;
	for(int T=1;T<=100;T++)
	{
		double l=L+(R-L)/3;
		double r=R-(R-L)/3;
		double ansl=calc(l);
		double ansr=calc(r);
		if(ansl>ansr) L=l;
		else R=r;
	}
	printf("%.010lf\n",calc(L));
	return 0;
}