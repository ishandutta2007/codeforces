#include <iostream>
#include <algorithm>
using namespace std;
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	long long ans=0;
	int n,i;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	for (i=0;i<n;i++)
	ans+=abs(arr[i]-i-1);
	cout << ans;
}