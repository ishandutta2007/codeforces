#include <iostream>
#include <string.h>
using namespace std;
int arr[500005],r,n;
long long cum[500005];
bool check(long long m,long long k)
{
	memset(cum,0,sizeof(cum));
	for (int i=0;i<n;i++)
	{
		cum[max(i-r,0)]+=arr[i];
		cum[min(i+r,n-1)+1]-=arr[i];
	}
	for (int i=0;i<n;i++)
	{
		if (i)
		cum[i]+=cum[i-1];
		if (cum[i]<m)
		{
			cum[min(n-1,i+2*r)+1]-=m-cum[i];
			k-=m-cum[i];
			cum[i]=m;
		}
		if (k<0)
		return 0;
	}
	return 1;
}
int main()
{
	long long k;
	scanf("%d%d%I64d",&n,&r,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	long long st=0,en=2e18;
	while (st!=en)
	{
		long long mid=(st+en+1)/2;
		if (check(mid,k))
		st=mid;
		else
		en=mid-1;
	}
	printf("%I64d",st);
}