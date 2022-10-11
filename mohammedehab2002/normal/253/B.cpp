#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	int n,i,x=0,maxi=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	sort (arr,arr+n);
	for (i=0;i<n;i++)
	{
		while (x<n && arr[x]<=2*arr[i])
		x++;
		maxi=max(maxi,x-i);
	}
	cout << n-maxi;
}