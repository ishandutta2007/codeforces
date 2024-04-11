#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long

const int N = 1e6 + 10, M = N * N, inf = 1e18, mod = 998244353;

int n, m;
int a[N];
void solve() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = accumulate(a + 1, a + n + 1, 0ll);
	cout << (ans - m >= 0 ? ans - m : 0) << endl;

}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}