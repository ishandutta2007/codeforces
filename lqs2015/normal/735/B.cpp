#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
double a[111111],sum,ans,f,s;
int n,n1,n2;
int main()
{
	scanf("%d%d%d",&n,&n1,&n2);
	f=min(n1,n2);
	s=max(n1,n2);
	for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (int i=1;i<=f;i++)
	{
		sum+=a[i];
	}
	ans=ans+sum/f;
	sum=0.00;
	for (int i=f+1;i<=f+s;i++)
	{
		sum+=a[i];
	}
	ans=ans+sum/s;
	printf("%.6lf\n",ans);
	return 0;
}