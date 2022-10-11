#include <iostream>
using namespace std;
long long a[200005],b[200005],arr[200005],ans[200005],cnt[35],sum;
int main()
{
	long long n;
	scanf("%I64d",&n);
	for (int i=0;i<n;i++)
	scanf("%I64d",&a[i]);
	for (int i=0;i<n;i++)
	{
		scanf("%I64d",&b[i]);
		arr[i]=a[i]+b[i];
		sum+=arr[i];
	}
	for (int i=0;i<n;i++)
	{
		if ((arr[i]*2*n-sum)%(2*n*n))
		{
			printf("-1");
			return 0;
		}
		ans[i]=(arr[i]*2*n-sum)/(2*n*n);
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<35;x++)
		cnt[x]+=(bool)(ans[i]&(1LL<<x));
	}
	for (int i=0;i<n;i++)
	{
		long long ai=0,bi=0;
		for (int x=0;x<35;x++)
		{
			if (!(ans[i]&(1LL<<x)))
			bi+=cnt[x]*(1LL<<x);
			else
			{
				ai+=cnt[x]*(1LL<<x);
				bi+=n*(1LL<<x);
			}
		}
		if (ai!=a[i] || bi!=b[i])
		{
			printf("-1");
			return 0;
		}
	}
	for (int i=0;i<n;i++)
	printf("%I64d ",ans[i]);
}