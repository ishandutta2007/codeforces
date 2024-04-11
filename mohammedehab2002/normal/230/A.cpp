#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,s;
	cin >> s >> n;
	pair <int,int> arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i].first >> arr[i].second;
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		if (s>arr[i].first)
		s+=arr[i].second;
		else
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}