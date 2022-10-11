#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n],ans[n+1];
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		ans[a]=i+1;
	}
	for (int i=1;i<=n;i++)
	cout << ans[i] << ' ';
}