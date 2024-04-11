#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,s,i,sum=0;
	cin >> n >> s;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	for (i=n-1;sum<s;i--)
	sum+=arr[i];
	cout << n-i-1;
}