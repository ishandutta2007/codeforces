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

const ll MOD = 998244353;
const int N = 210000;

int a[N];
int b[N];
int n, k;
int go[N];

map<int, int> mm;
void solve() {
	mm.clear();
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mm[a[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		go[i] = -1;
	}
	ll ans = 1;
	for (int i = 0; i < k; ++i) {
		cin >> b[i];
		if (mm.count(b[i])) {
			go[mm[b[i]]] = i;
		} else {
			ans = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (go[i] != -1) {
			int cnt = 0;
			if (i > 0 && go[i - 1] < go[i]) {
				++cnt;
			}
			if (i + 1 < n && go[i + 1] < go[i]) {
				++cnt;
			}
			ans = (ans * cnt) % MOD;
		}
	}

	cout << ans << "\n";
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