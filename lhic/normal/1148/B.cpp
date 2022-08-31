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

const int N = 210000;

ll a[N];
ll b[N];

int n, m;
ll ta, tb;
int k;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> m >> ta >> tb >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i], a[i] += ta + tb;
	for (int i = 0; i < m; ++i)
		cin >> b[i], b[i] += tb;
	if (k >= n || k >= m) {
		cout << -1 << "\n";
		return 0;
	}
	ll ans = 0;
	for (int i = 0; i <= k; ++i) {
		int j = k - i;
		int x = lower_bound(b, b + m, a[i]) - b;
		x += j;
		if (x >= m) {
			cout << -1 << "\n";
			return 0;
		}
		ans = max(ans, b[x]);
	}
	cout << ans << "\n";
	return 0;
}