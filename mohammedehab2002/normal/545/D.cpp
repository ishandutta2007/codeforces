#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,time=0,ans=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	for (i=0;i<n;i++)
	{
		if (arr[i]>=time)
		{
			ans++;
			time+=arr[i];
		}
	}
	cout << ans;
}