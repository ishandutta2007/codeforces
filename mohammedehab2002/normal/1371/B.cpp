#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n,r;
		cin >> n >> r;
		long long ans=0;
		if (r>=n)
		{
			ans=1;
			r=n-1;
		}
		cout << ans+r*(r+1)/2 << endl;
	}
}