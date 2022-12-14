#include<bits/stdc++.h>
using namespace std;
int n,a[222222],pop[22],cur;
long long ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<20;j++)
		{
			if (a[i]&(1<<j)) pop[j]++;
		}
	}
	for (int i=1;i<=n;i++)
	{
		cur=0;
		for (int j=0;j<20;j++)
		{
			if (pop[j])
			{
				cur|=(1<<j);
				pop[j]--;
			}
		}
		ans+=(1ll*cur*cur);
	}
	printf("%lld\n",ans);
	return 0;
}