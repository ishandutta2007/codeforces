#include <iostream>
using namespace std;
int main()
{
	long long n,h,k,i,ans=0;
	cin >> n >> h >> k;
	long long arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=0;i<n;i++)
	{
		ans+=arr[i]/k;
		arr[i]%=k;
		if (i==n-1)
		{
			if (arr[i])
			ans++;
			break;
		}
		if (h-arr[i]<arr[i+1])
		ans++;
		else
		arr[i+1]+=arr[i];
	}
	cout << ans;
}