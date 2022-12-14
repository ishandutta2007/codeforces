#include<bits/stdc++.h>
using namespace std;
long long ans1,ans2;
int n,a[333333];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (i&1)
		{
			ans1+=(a[i]/2);
			ans2+=((a[i]+1)/2);
		}
		else
		{
			ans1+=((a[i]+1)/2);
			ans2+=(a[i]/2);
		}
	}
	printf("%lld\n",min(ans1,ans2));
	return 0;
}