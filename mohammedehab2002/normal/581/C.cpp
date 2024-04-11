#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,k,i,ans=0;
    cin >> n >> k;
    pair <int,int> arr[n];
    for (i=0;i<n;i++)
    {
    	cin >> arr[i].second;
    	arr[i].first=10-arr[i].second%10;
    	ans+=arr[i].second/10;
	}
	sort (arr,arr+n);
	again:int test=0;
	for (i=0;i<n && k-arr[i].first>=0;i++)
	{
		if (arr[i].second!=100)
		{
			k-=arr[i].first;
			arr[i].second+=arr[i].first;
			arr[i].first=10;
			ans++;
		}
		else
		test++;
	}
	if (k-10>=0 && test!=n)
	goto again;
	cout << ans;
}