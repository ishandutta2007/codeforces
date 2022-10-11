#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	if (n==1)
	{
		if (arr[0]==15)
		cout << "DOWN";
		else if (arr[0]==0)
		cout << "UP";
		else
		cout << -1;
		return 0;
	}
	if (arr[n-1]>arr[n-2])
	{
		if (arr[n-1]==15)
		cout << "DOWN";
		else 
		cout << "UP";
	}
	else
	{
		if (arr[n-1]==0)
		cout << "UP";
		else
		cout << "DOWN";
	}
}