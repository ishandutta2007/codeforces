#include <iostream>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	long long x,y,ans=0;
	cin >> x;
	for (i=1;i<n;i++)
	{
		cin >> y;
		if (y<x)
		ans+=x-y;
		x=y;
	}
	cout << ans;
}