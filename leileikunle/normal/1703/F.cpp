#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
using pii = pair<int, int>;
const int N = 1e6 + 10, M = N, inf = 1e18, mod = 998244353;

void solve() {

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> h(n + 1, 0);
	auto add = [&](int x, int d) -> void{
		for (int i = x; i <= n; i += i & -i) h[i] += d;
	};
	auto ask1 = [&](int x) -> int{
		int res(0);
		for (int i = x; i > 0; i -= i & -i) res += h[i];
		return res;
	};
	auto ask2 = [&](int l, int r) -> int{
		return ask1(r) - ask1(l - 1);
	};

	int ans(0);
	for (int i = 1; i <= n; i++) {
		if (a[i] < i) ans += ask2(0, a[i] - 1), add(i, 1);
	}
	cout << ans << endl;
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