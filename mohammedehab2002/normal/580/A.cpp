#include <iostream>
using namespace std;
int main()
{
	int n,i,ans=1,maxi=1;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=1;i<n;i++)
	{
		if (arr[i]>=arr[i-1])
		ans++;
		else
		{
			if (ans>maxi)
			maxi=ans;
			ans=1;
		}
	}
	cout << max(maxi,ans);
}