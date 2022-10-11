#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	if (n==k)
	{
		cout << -1;
		return 0;
	}
	int arr[n+1];
	for (int i=n;i>n-k;i--)
	arr[i]=i;
	arr[1]=n-k;
	for (int i=2;i<=n-k;i++)
	arr[i]=i-1;
	for (int i=1;i<=n;i++)
	cout << arr[i] << ' ';
}