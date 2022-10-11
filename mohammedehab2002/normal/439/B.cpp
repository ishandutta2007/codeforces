#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long ans=0;
	int n,x;
	cin >> n >> x;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	ans+=(long long)arr[i]*max((long long)x-i,1LL);
	cout << ans;
}