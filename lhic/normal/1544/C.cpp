#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 120000;

int n;
int a[N];
int b[N];
int sa[N];
int sb[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		sa[i + 1] = sa[i] + a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; ++i) {
		sb[i + 1] = sb[i] + b[i];
	}
	int lb = -1;
	int rb = n + 1;
	while (rb - lb > 1) {
		int mid = (lb + rb) >> 1;

		int da = (n + mid) / 4;
		int db = (n + mid) / 4;
		int ca = 100 * mid + sa[n] - sa[da];
		db = max(0, db - mid);
		int cb = sb[n] - sb[db];
		if (ca >= cb) {
			rb = mid;
		} else {
			lb = mid;
		}
	}
	cout << rb << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		solve();
	}
	return 0;
}