#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i,x,j,maxi=0,c;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=0;i<n;i++)
	{
		for (x=i;x<n;x++)
		{
			c=arr[i];
			for (j=i+1;j<=x;j++)
			c^=arr[j];
			if (c>maxi)
			maxi=c;
		}
	}
	cout << maxi;
}