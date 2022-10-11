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
	int a=count(arr,arr+n,1);
	if ((n==1 && a==1) || (n!=1 && a==n-1))
	cout << "YES";
	else
	cout << "NO";
}