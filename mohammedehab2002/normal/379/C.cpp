#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,x,ans=0;
	cin >> n;
	int arr[n];
	pair <int,int> p[n];
	for (i=0;i<n;i++)
	{
		cin >> p[i].first;
		p[i].second=i;
	}
	sort (p,p+n);
	for (i=0;i<n;i++)
	{
		if (p[i].first>ans)
		arr[p[i].second]=ans=p[i].first;
		else
		{
			ans++;
			arr[p[i].second]=ans;
		}
	}
	for (i=0;i<n;i++)
	cout << arr[i] << ' ';
}