#include <iostream>
using namespace std;
int main()
{
	int n,m,i,ans=0,test=0;
	cin >> n >> m;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	i=0;
	while (i<n)
	{
		while (test+arr[i]<=m)
		{
			test+=arr[i];
			i++;
		}
		ans++;
		test=0;
	}
	cout << ans;
}