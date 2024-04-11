#include <iostream>
using namespace std;
int main()
{
	int n,i,s1=0,s2=0,ans=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		s1+=arr[i];
	}
	for (i=0;i<n-1;i++)
	{
		s2+=arr[i];
		s1-=arr[i];
		if (s1==s2)
		ans++;
	}
	cout << ans;
}