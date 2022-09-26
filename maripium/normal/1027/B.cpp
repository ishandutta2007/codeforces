#include <bits/stdc++.h>
#define int long long
using namespace std;

long long n, q;

signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	long long hlf = (n * n + 1) / 2;
	while (q--) {
		long long x, y; cin >> x >> y;
		if (x + y & 1) {
			long long res = (x - 1) / 2 * n;
			if (x % 2 == 0) res += n / 2;
			res += (y + 1) / 2;
			cout << res + hlf << '\n';
		}
		else {
			long long res = (x - 1) / 2 * n;
			if (x % 2 == 0) res += (n + 1) / 2;
			res += (y + 1) / 2;
			cout << res << '\n';
		}
	}
}