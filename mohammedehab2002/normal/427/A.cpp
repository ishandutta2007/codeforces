#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,test=0,ans=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=0;i<n;i++)
	{
		if (arr[i]!=-1)
		test+=arr[i];
		else
		{
			if (test>0)
			test--;
			else
			ans++;
		}
	}
	cout << ans;
}