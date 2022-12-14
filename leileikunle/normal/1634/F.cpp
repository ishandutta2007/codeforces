#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

const int N = 1e6 + 10, inf = 1e18;

int a[N], f[N], mod;
void solve() {

	int n, q, mod;
	cin >> n >> q >> mod;
	f[1] = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, x; i <= n; i++) cin >> x, (a[i] += mod - x) %= mod;
	for (int i = n; i > 1; i--) (a[i] += mod - a[i - 1]) %= mod, (a[i] += mod - a[i - 2]) %= mod;
	for (int i = 2; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += !!a[i];
	auto update = [&](int pos, int val) {
		if (pos <= n) cnt -= (!!a[pos]) - (!!((a[pos] += val) %= mod));
	};
	while (q--) {
		char opt;
		int l, r;
		cin >> opt >> l >> r;
		if (opt == 'A') update(l, 1), update(r + 1, mod - f[r - l + 2]), update(r + 2, mod - f[r - l + 1]);
		else update(l, mod - 1), update(r + 1, f[r - l + 2]), update(r + 2, f[r - l + 1]);
		cout << (cnt == 0 ? "YES" : "NO") << endl;
	}

}
signed main() {

	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}



}