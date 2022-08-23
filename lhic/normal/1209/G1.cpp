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

int lst[N];
int fl[N];

int n, q;
int a[N];
int sz[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> q;
	for (int i = 0; i < N; ++i)
		lst[i] = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++sz[a[i]];
		lst[a[i]] = i;
	}
	int cur = 0;
	int ans = 0;
	while (cur < n) {
		int st = cur;
		int now = lst[a[cur]];
		int mx = 0;
		while (cur <= now) {
			now = max(now, lst[a[cur]]);
			mx = max(mx, sz[a[cur]]);
			++cur;
		}
		ans += (cur - st) - mx;
	}
	cout << ans << "\n";
	return 0;
}