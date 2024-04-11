#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 2e5 + 100;
const int mod = 1e9 + 7;

int funct(int r, int i) {
	int t1 = r / (1 << (i + 1));
	int t2 = r % (1 << (i + 1));
	return t1 * (1 << i) + max(0, 1 + t2 - (1 << i));
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		int ans = 1e9;
		for (int i = 0; i < 20; i++) {
			int s = funct(r, i) - funct(l - 1, i);
			ans = min(ans, (r - l + 1) - s);
		}
		cout << ans << "\n";
	}
	return 0;
}