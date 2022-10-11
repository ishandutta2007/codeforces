#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	int arr[n];
	if (n%2)
	{
		cout << -1;
		return 0;
	}
	for (i=0;i<n;i++)
	arr[i]=i+1;
	for (i=0;i<n-1;i+=2)
	swap(arr[i],arr[i+1]);
	for (i=0;i<n;i++)
	cout << arr[i] << " ";
}