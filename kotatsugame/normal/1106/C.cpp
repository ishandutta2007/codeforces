#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[300000];
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	long long ans=0;
	for(int i=0;i<n/2;i++)
	{
		long long s=a[i]+a[n-1-i];
		ans+=s*s;
	}
	printf("%lld\n",ans);
}