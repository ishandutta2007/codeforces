#include <iostream>
#include <algorithm>
using namespace std;
int abs(int x)
{
	return (x>0? x:-x);
}
int main()
{
	int n,a;
	cin >> n >> a;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	sort(arr,arr+n);
	if (n==1)
	cout << 0;
	else
	cout << min(arr[n-2]-arr[0]+min(abs(a-arr[0]),abs(a-arr[n-2])),arr[n-1]-arr[1]+min(abs(a-arr[1]),abs(a-arr[n-1])));
}