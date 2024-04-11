#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,x,ans=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	for (i=0;i<n;i++)
	{
		for (x=0;x<n;x++)
		{
			if (arr[i]==arr[x] && i!=x)
			{
				ans++;
				arr[x]++;
			}
		}
	}
	cout << ans;
}