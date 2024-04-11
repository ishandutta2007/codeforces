#include <iostream>
using namespace std;
int main()
{
	int n,i,even,ans=0;
	long long total=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		total+=arr[i];
	}
	even=total%2;
	for (i=0;i<n;i++)
	{
		if (arr[i]%2==even)
		ans++;
	}
	cout << ans;
}