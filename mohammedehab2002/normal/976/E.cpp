#include <iostream>
#include <algorithm>
using namespace std;
pair<int,pair<int,int> > arr[200005];
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for (int i=0;i<n;i++)
	{
		int h,d;
		scanf("%d%d",&h,&d);
		arr[i]={h-d,{h,d}};
	}
	sort(arr,arr+n);
	reverse(arr,arr+n);
	long long sum=0,ans=0;
	for (int i=0;i<min(n,b);i++)
	sum+=max(arr[i].first,0);
	for (int i=0;i<n;i++)
	{
		if (i<b)
		sum-=max(arr[i].first,0);
		if (b)
		ans=max(ans,sum+arr[i].second.first*(1LL<<a)-arr[i].second.second);
		if (i<b-1)
		sum+=max(arr[i].first,0);
	}
	for (int i=0;i<n;i++)
	ans+=arr[i].second.second;
	printf("%I64d",ans);
}