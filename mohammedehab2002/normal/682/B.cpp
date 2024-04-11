#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long arr[n],ans=1;
	for (int i=0;i<n;i++)
	cin >> arr[i];
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		if (arr[i]<ans)
		continue;
		arr[i]=ans;
		ans++;
	}
	cout << ans;
}