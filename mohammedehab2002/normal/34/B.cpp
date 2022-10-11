#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,i,ans=0;
	cin >> n >> m;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	for (i=0;i<m;i++)
	{
		if (arr[i]<0)
		ans-=arr[i];
		else
		break;
	}
	cout << ans;
}