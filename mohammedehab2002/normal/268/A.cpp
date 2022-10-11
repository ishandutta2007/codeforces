#include <iostream>
using namespace std;
int main()
{
	int n,i,x,ans=0;
	cin >> n;
	int arr[n][2];
	for (i=0;i<n;i++)
	cin >> arr[i][0] >> arr[i][1];
	for (i=0;i<n;i++)
	{
		for (x=0;x<n;x++)
		{
			if (arr[i][0]==arr[x][1])
			ans++;
		}
	}
	cout << ans;
}