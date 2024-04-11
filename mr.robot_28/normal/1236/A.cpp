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
		int a, b, c;
		cin >> a >> b >> c;
		int k = min(b, c / 2);
		b -= k;
		cout << 3 * min(a, b / 2) + k * 3 << "\n";
	}
    return 0;
}