#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	long long n,i,arr[100000],e;
	cin >> n;
	if (n==1)
	{
		cout << "NO";
		return 0;
	}
	for (i=1;i*(i+1)/2<n;i++)
	{
		arr[i]=i*(i+1)/2;
		e=i;
	}
	for (i=1;i*(i+1)/2<n;i++)
	{
		if (binary_search(arr+1,arr+1+e,n-i*(i+1)/2))
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}