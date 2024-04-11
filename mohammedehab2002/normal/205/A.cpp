#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	int arr[n],copy[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		copy[i]=arr[i];
	}
	sort (arr,arr+n);
	if (arr[0]==arr[1])
	cout << "Still Rozdil";
	else
	{
		for (i=0;i<n;i++)
		{
			if (copy[i]==arr[0])
			cout << i+1;
		}
	}
}