#include <iostream>
#include <algorithm>
int abs(int x)
{
	return (x>0)? x:x*-1;
}
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	cout << abs(arr[1]-arr[0]) << " " << abs(arr[n-1]-arr[0]) << endl;
	for (i=1;i<n-1;i++)
	cout << min(abs(arr[i]-arr[i-1]),abs(arr[i]-arr[i+1])) << " " << max(abs(arr[i]-arr[0]),abs(arr[i]-arr[n-1])) << endl;
	cout << abs(arr[n-1]-arr[n-2]) << " " << abs(arr[n-1]-arr[0]);
}