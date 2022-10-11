#include <iostream>
using namespace std;
int main()
{
	int n,b,ans;
	cin >> n >> b;
	ans=b;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	for (int i=0;i<n;i++)
	{
		for (int x=i+1;x<n;x++)
		ans=max(ans,(b/arr[i])*arr[x]+(b%arr[i]));
	}
	cout << ans;
}