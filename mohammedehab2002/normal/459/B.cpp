#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n,i,first,last;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	cout << arr[n-1]-arr[0] << " ";
	i=0;
	while (arr[i]==arr[0])
	i++;
	first=i;
	i=n-1;
	while (arr[i]==arr[n-1])
	i--;
	last=n-i-1;
	if (arr[0]==arr[n-1])
	cout << n*(n-1)/2;
	else
	cout << (long long)(first*last);
}