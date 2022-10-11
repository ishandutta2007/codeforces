#include <bits/stdc++.h>
using namespace std;
double a[20],dp[(1<<20)],ans[20];
int main()
{
	int n,k,nz=0;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%lf",&a[i]);
		nz+=(a[i]>1e-9);
	}
	if (nz<k)
	{
		for (int i=0;i<n;i++)
		printf("%d ",(a[i]>1e-9));
		return 0;
	}
	dp[0]=1;
	for (int i=1;i<(1<<n);i++)
	{
		double p=1;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j))
			p-=a[j];
		}
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j))
			{
				p+=a[j];
				if (p>1e-9)
				dp[i]+=a[j]/p*dp[i^(1<<j)];
				p-=a[j];
			}
		}
		if (__builtin_popcount(i)==k)
		{
			for (int j=0;j<n;j++)
			{
				if (i&(1<<j))
				ans[j]+=dp[i];
			}
		}
	}
	for (int i=0;i<n;i++)
	printf("%.9lf ",ans[i]);
}