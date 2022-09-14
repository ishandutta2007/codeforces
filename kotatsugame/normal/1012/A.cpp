#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[200020];
main()
{
	scanf("%d",&n);
	for(int i=0;i<2*n;i++)scanf("%d",a+i);
	sort(a,a+2*n);
	long long A,B,ans=1e18;
	for(int i=0;i<n;i++)
	{
		A=a[n+i-1]-a[0];
		B=a[2*n-1]-a[n-i];
		ans=min(ans,A*B);
		A=a[n+i-1]-a[i];
		B=a[2*n-1]-a[0];
		ans=min(ans,A*B);
	}
	printf("%lld\n",ans);
}