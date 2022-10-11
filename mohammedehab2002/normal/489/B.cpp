#include <iostream>
#include <algorithm>
using namespace std;
bool check(int a,int b)
{
	if (a>=b-1 && a<=b+1)
	return false;
	return true;
}
int main()
{
	int n,m,ans=0;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	cin >> m;
	int arr2[m];
	for (int i=0;i<m;i++)
	cin >> arr2[i];
	sort(arr,arr+n);
	sort(arr2,arr2+m);
	int x=0;
	for (int i=0;i<n;i++)
	{
		while (x<m && check(arr2[x],arr[i]))
		{
			if (arr2[x]>arr[i]+1)
			goto con;
			x++;
		}
		if (x>=m)
		break;
		x++;
		ans++;
		con:continue;
	}
	cout << ans;
}