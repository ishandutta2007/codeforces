#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	double h=0,t=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		h+=arr[i];
	}
	h/=2;
	sort (arr,arr+n);
	i=n-1;
	while (t<=h)
	{
		t+=arr[i];
		i--;
	}
	cout << n-i-1;
}