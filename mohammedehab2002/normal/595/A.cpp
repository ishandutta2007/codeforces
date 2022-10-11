#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,ans=0;
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		int arr[2*m],a[m];
		for (int i=0;i<2*m;i++)
		{
			cin >> arr[i];
			if (i%2)
			a[i/2]=arr[i]|arr[i-1];
		}
		ans+=count(a,a+m,1);
	}
	cout << ans;
}