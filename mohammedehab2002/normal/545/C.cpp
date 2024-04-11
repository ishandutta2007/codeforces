#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin >> n;
	pair <ll,ll> arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i].first >> arr[i].second;
	int ans=min(2,n);
	ll pos=arr[0].first;
	for (int i=1;i<n-1;i++)
	{
		if (arr[i].first-arr[i].second>pos)
		{
			ans++;
			pos=arr[i].first;
		}
		else if (arr[i].first+arr[i].second<arr[i+1].first)
		{
			ans++;
			pos=arr[i].first+arr[i].second;
		}
		else
		pos=arr[i].first;
	}
	cout << ans;
}