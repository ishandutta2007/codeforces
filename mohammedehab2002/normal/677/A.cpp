#include <iostream>
using namespace std;
int main()
{
	int n,h,i,ans=0;
	cin >> n >> h;
	for (i=0;i<n;i++)
	{
		ans++;
		int a;
		cin >> a;
		if (a>h)
		ans++;
	}
	cout << ans;
}