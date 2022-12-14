#include<bits/stdc++.h>
using namespace std;
int n,a[222222],test;
long long ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<n;i++) ans+=max(0,a[i]-a[i+1]);
		printf("%lld\n",ans);
	}
	return 0;
}