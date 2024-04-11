#include <iostream>
using namespace std;
int main()
{
	long long n,k,ans,i;
	cin >> n >> k;
	long long arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	for (i=0;i<=n;i++)
	{
		if (k<=(i+2)*(i+1)/2)
		break;
	}
	cout << arr[k-i*(i+1)/2-1];
}