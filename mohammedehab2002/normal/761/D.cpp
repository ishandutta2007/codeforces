#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,l,r;
	cin >> n >> l >> r;
	pair<int,int> arr[n];
	int a[n];
	for (int i=0;i<n;i++)
	cin >> a[i];
	for (int i=0;i<n;i++)
	{
		cin >> arr[i].first;
		arr[i].second=i;
	}
	sort(arr,arr+n);
	reverse(arr,arr+n);
	int c[n],b[n];
	b[arr[0].second]=r;
	c[arr[0].second]=r-a[arr[0].second];
	for (int i=1;i<n;i++)
	{
		c[arr[i].second]=c[arr[i-1].second]-1;
		b[arr[i].second]=a[arr[i].second]+c[arr[i].second];
		if (b[arr[i].second]>r)
		{
			int m=b[arr[i].second]-r;
			c[arr[i].second]-=m;
			b[arr[i].second]-=m;
		}
	}
	for (int i=0;i<n;i++)
	{
		if (b[i]<l)
		{
			cout << "-1";
			return 0;
		}
	}
	for (int i=0;i<n;i++)
	cout << b[i] << ' ';
}