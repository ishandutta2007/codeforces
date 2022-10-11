#include <iostream>
using namespace std;
int main()
{
	int n,m,i;
	cin >> n >> m;
	int arr[m];
	for (i=0;i<m;i++)
	cin >> arr[i];
	long long ans=arr[0]-1;
	for (i=1;i<m;i++)
	{
		if (arr[i]>=arr[i-1])
		ans+=arr[i]-arr[i-1];
		else
		ans+=n-arr[i-1]+arr[i];
	}
	cout << ans;
}