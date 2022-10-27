#include <bits/stdc++.h>

using namespace std;

signed main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int cnt = (a + c - 1) / c + (b + d - 1) / d;
		if(cnt > k)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << (a + c - 1) / c << " " << (b + d - 1) / d << "\n";
		}
	}
	return 0;
}