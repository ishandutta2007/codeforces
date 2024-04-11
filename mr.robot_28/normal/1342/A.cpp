#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x, y, a, b;
		cin >> x >> y >>  a >> b;
		int ans = 0;
		ans += abs(x - y) * a;
		ans += min(x, y) * min(b, a * 2);
		cout << ans << "\n";
	}
	return 0;
}