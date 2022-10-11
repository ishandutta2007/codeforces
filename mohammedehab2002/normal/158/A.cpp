#include <iostream>
using namespace std;
int main()
{
	int n,k,i;
	cin >> n >> k;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=0;i<n;i++)
	{
		if (arr[i]==0 || arr[i]<arr[(k-1)])
		break;
	}
	cout << i;
}