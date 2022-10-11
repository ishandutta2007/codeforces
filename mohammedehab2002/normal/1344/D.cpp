#include <bits/stdc++.h>
using namespace std;
int n,a[100005],ans[100005];
bool check(long long d,long long k)
{
	for (int i=0;i<n;i++)
	{
		int st=0,en=a[i];
		while (st!=en)
		{
			int mid=(st+en+1)/2;
			if (a[i]-3LL*mid*mid+3LL*mid-1>d)
			st=mid;
			else
			en=mid-1;
		}
		ans[i]=st;
		k-=st;
	}
	if (k<=0)
	return 1;
	for (int i=0;i<n && k;i++)
	{
		if (ans[i]<a[i] && a[i]-3LL*(ans[i]+1)*(ans[i]+1)+3LL*(ans[i]+1)-1==d)
		{
			ans[i]++;
			k--;
		}
	}
	return !k;
}
int main()
{
	long long k;
	scanf("%d%lld",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	long long st=-4e18,en=4e18;
	while (st!=en)
	{
		long long mid=st+(en-st+1)/2;
		if (check(mid,k))
		st=mid;
		else
		en=mid-1;
	}
	check(st,k);
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]);
}