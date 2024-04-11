#include <iostream>
using namespace std;
int main()
{
	int n,i,maxi,mini,ans=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	maxi=arr[0];
	mini=arr[0];
	for (i=1;i<n;i++)
	{
		if (arr[i]>maxi)
		{
			ans++;
			maxi=arr[i];
		}
		if (arr[i]<mini)
		{
			ans++;
			mini=arr[i];
		}
	}
	cout << ans;
}