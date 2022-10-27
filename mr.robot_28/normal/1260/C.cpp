#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		int k;
		cin >> k;
		if(a> b)
		{
			swap(a, b);
		}
		int gcd = __gcd(a, b);
		a /= gcd;
		b /= gcd;
		if((k - 1) * a + 1 < b)
		{
			cout << "REBEL\n";
		}
		else
		{
			cout << "OBEY\n";
		}
	}
	return 0;
}