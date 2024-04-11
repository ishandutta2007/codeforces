#include<bits/stdc++.h>
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
		int a, k;
		cin >> a >> k;
		k--;
		int mindigit = 10, maxdigit = 0;
		int b = a;
		while(b > 0)
		{
			mindigit = min(mindigit, b % 10);
			maxdigit = max(maxdigit, b % 10);
			b = b / 10;
		}
		int go = mindigit * maxdigit;
		while(go != 0 && k > 0)
		{
			k--;
			a += go;
			b = a;
			mindigit = 10;
			maxdigit = 0;
			while(b > 0)
			{
				mindigit = min(mindigit, b % 10);
				maxdigit = max(maxdigit, b % 10);
				b = b / 10;
			}
			go = mindigit * maxdigit;
		}
		cout << a << "\n";
	}
    return 0;
}