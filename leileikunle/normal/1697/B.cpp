#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long

const int N = 1e6 + 10, M = N * N, inf = 1e18, mod = 998244353;

int n, m, q;
int a[N];
void solve() {

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << a[l] - a[l - r] << endl;
	}
}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}