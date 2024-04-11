#include <iostream>
using namespace std;
int a[100005],b[100005],n,k;
bool check(long long x)
{
	long long need=0;
	for (int i=0;i<n;i++)
	{
		need+=max(a[i]*x-b[i],0LL);
		if (need>k)
		return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
	scanf("%d",&b[i]);
	long long st=0,en=2e9+5;
	while (st!=en)
	{
		long long mid=(st+en+1)/2;
		if (check(mid))
		st=mid;
		else
		en=mid-1;
	}
	printf("%d",st);
}