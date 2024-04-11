#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	sort(arr,arr+n);
	int q;
	cin >> q;
	for (int i=0;i<q;i++)
	{
		int a;
		cin >> a;
		cout << upper_bound(arr,arr+n,a)-arr << endl;
	}
}