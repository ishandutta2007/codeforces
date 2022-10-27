#include <bits/stdc++.h>
using namespace std;


signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		if(a > b)
		{
			swap(a, b);
		}
		if(b > 2 * a)
		{
			cout << "NO\n";
		}
		else if(b % 3 == a % 3 && b %3 != 0 || a % 3 == 0 && b % 3 != 0 || a % 3 != 0 && b % 3 == 0)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
	return 0;
}