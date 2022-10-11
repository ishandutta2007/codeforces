#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long test=0,res=0,ans=0;
	int n,i;
	cin >> n;
	int arr[n],a[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		test+=arr[i];
	}
	if (test%3)
	{
		cout << 0;
		return 0;
	}
	for (i=0;i<n;i++)
	a[i]=0;
	test/=3;
	for (i=n-1;i>=0;i--)
	{
		res+=arr[i];
		if (res==test)
		a[i]=1;
	}
	for (i=n-2;i>=0;i--)
	a[i]+=a[i+1];
	res=0;
	for (i=0;i<n-2;i++)
	{
		res+=arr[i];
		if (res==test)
		ans+=a[i+2];
	}
	cout << ans;
}