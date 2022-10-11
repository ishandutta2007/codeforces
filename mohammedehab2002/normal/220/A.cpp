#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,ans=0;
	cin >> n;
	int arr[n],copy[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		copy[i]=arr[i];
	}
	sort (arr,arr+n);
	for (i=0;i<n;i++)
	{
		if (copy[i]!=arr[i])
		ans++;
	}
	if (ans<=2)
	cout << "YES";
	else
	cout << "NO";
}