#include <bits/stdc++.h>
using namespace std;

const int N = 10000007;

unsigned int b[N], x, y, z;

#define int long long
int n, l, r;
int a[N];

void solve() {
	if (false) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
	}
	else {
		cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];
		for (int i = 3; i <= n; ++i) {
			b[i] = b[i - 2] * x + b[i - 1] * y + z;
		}
		for (int i = 1; i <= n; ++i) {
			a[i] = (long long)(b[i]) % (r - l + 1) + l;
		}
	}
	bool found = false;
	for (int i = 2; i <= n; ++i) {
		if (a[i] > a[i - 1]) {
			found = true; break;
		}
	}
	if (!found) {
		cout << "IMPOSSIBLE\n"; return;
	}
	if (*max_element(a + 1, a + n + 1) <= 0) {
		int mx = a[n];
		long long res = 5e18;
		for (int i = n - 1; i > 0; --i) {
			if (a[i] >= mx) mx = a[i];
			else {
				res = min(res, 1LL * a[i] * mx);
			}
		}
		cout << res << '\n'; return;
	}
	if (*min_element(a + 1, a + n + 1) >= 0) {
		int mn = a[1];
		long long res = 5e18;
		for (int i = 2; i <= n; ++i) {
			if (a[i] <= mn) mn = a[i];
			else {
				res = min(res, 1LL * a[i] * mn);
			}
		}
		cout << res << '\n'; return;
	}
	else {
		int st = -1;
		for (int i = 1; i <= n; ++i) if (a[i] <= 0) {
			st = i; break;
		}
		bool found = false;
		for (int i = st; i <= n; ++i) {
			if (a[i] > 0) found = true;
		}
		if (!found) {
			long long res = 5e18;
			int mn = a[1];
			for (int i = 2; i <= st - 1; ++i) {
				if (a[i] <= mn) mn = a[i];
				else {
					res = min(res, 1LL * mn * a[i]);
				}
			}
			int mx = a[n];
			for (int i = n - 1; i >= st; --i) {
				if (a[i] >= mx) mx = a[i];
				else {
					res = min(res, 1LL * mx * a[i]);
				}
			}
			cout << res << '\n';
		}
		else {
			long long res = 5e18;
			int mn = 2e9 + 1234;
			for (int i = 1; i <= n; ++i) {
				if (a[i] > 0 && mn <= 0) {
					res = min(res, 1LL * a[i] * mn);
				}
				else if (a[i] < 0) {
					mn = min(mn, a[i]);
				}
				else if (a[i] == 0) {
					if (mn < 0) res = min(res, 0LL);
					else mn = 0;
				}
			}
			cout << res << '\n';
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
}