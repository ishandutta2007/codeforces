#include <bits/stdc++.h>
 
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a <= b)
		{
			cout << b << "\n";
		}
		else
		{
			int sum = a - b;
			if(c <= d)
			{
				cout << -1 << "\n";
			}
			else
			{
				b += ((sum + (c - d - 1)) / (c - d)) * c;
				cout << b << "\n";
			}
		}
	}
    return 0;
}