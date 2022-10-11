#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,d,i,x,ans=0;
	cin >> n >> d;
	int arr[n];
	for (i=0;i<n;i++)
	cin  >> arr[i];
	sort (arr,arr+n);
	for (i=0;i<n-1;i++)
	{
		for (x=i+1;x<n;x++)
		{
			if (arr[x]-arr[i]<=d && i!=x)
			ans+=2;
		}
	}
	cout << ans;
}