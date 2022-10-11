#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,a;
	long long arr[100010];
	cin >> n;
	for (i=0;i<=100010;i++)
	arr[i]=0;
	for (i=0;i<n;i++)
	{
		cin >> a;
		arr[a]+=a;
	}
	for (i=100000;i>=0;i--)
	arr[i]=max(arr[i]+arr[i+2],arr[i+1]);
	cout << arr[0];
}