#include <iostream>
using namespace std;
int main()
{
	int n,i,x;
	cin >> n;
	int arr[n][n];
	for (i=0;i<n;i++)
	{
		arr[i][0]=1;
		arr[i][1]=i+1;
		arr[0][i]=1;
		arr[1][i]=i+1;
	}
	for (i=2;i<n;i++)
	{
		for (x=2;x<n;x++)
		arr[i][x]=arr[i-1][x]+arr[i][x-1];
	}
	cout << arr[n-1][n-1];
}