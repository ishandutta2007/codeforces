# include <bits/stdc++.h>
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		if(__gcd(a, b) == 1)
		{
			cout << "Finite\n";
		}
		else
		{
			cout << "Infinite\n";
		}
	}
	return 0;
}