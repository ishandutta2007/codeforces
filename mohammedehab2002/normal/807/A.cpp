#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n][2];
	for (int i=0;i<n;i++)
	{
		cin >> arr[i][0] >> arr[i][1];
		if (arr[i][0]!=arr[i][1])
		{
			cout << "rated";
			return 0;
		}
	}
	for (int i=1;i<n;i++)
	{
		if (arr[i][0]>arr[i-1][0])
		{
			cout << "unrated";
			return 0;
		}
	}
	cout << "maybe";
}