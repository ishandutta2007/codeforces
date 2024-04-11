#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	pair<long long,long long> arr[n];
	for (int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[i].first=min(2*a,b)-min(a,b);
		arr[i].second=min(a,b);
	}
	sort(arr,arr+n);
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		if (i>=n-k)
		ans+=(arr[i].first+arr[i].second);
		else
		ans+=arr[i].second;
	}
	cout << ans;
}