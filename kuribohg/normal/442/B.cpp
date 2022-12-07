#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n;
double a[1010],ans1,ans2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	sort(a+1,a+n+1);
	ans1=a[n],ans2=1-a[n];
	for(int i=n-1;i>=1;i--)
	{
		if(ans2*a[i]+ans1*(1-a[i])>ans1) ans1=ans2*a[i]+ans1*(1-a[i]),ans2*=(1-a[i]);
		else break;
	}
	printf("%.012lf\n",ans1);
	return 0;
}