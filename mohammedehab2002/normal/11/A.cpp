#include <iostream>
using namespace std;
int main()
{
	long long n,d,i,ans=0;
	cin >> n >> d;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=0;i<n-1;i++)
	{
		if (arr[i+1]<=arr[i])
		{
			ans+=(arr[i]-arr[i+1])/d;
			arr[i+1]+=((arr[i]-arr[i+1])/d)*d;
			if (arr[i+1]<=arr[i])
			{
				arr[i+1]+=d;
				ans++;
			}
		}
	}
	cout << ans;
}