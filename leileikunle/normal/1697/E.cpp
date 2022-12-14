#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long

const int N = 2e3 + 10, M = N * N, inf = 1e18, mod = 998244353;
int n, x[N], y[N], dis[N][N], color[N], dp[N][N];
vector<int> v[N], a;
int col;
set<int> s;

const int maxn = 1e6 + 10;
int qpow(int a, int x) {
	int  ret = 1;
	while (x) {
		if (x & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		x >>= 1;
	}
	return ret;
}
int fac[maxn], inv[maxn];

void init() {
	fac[0] = 1;
	for (int i = 1; i < maxn; i++)
		fac[i] = fac[i - 1] * i % mod;
	inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}

int c(int n, int m) {
	if (n < m) return 0;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int A(int n, int m) {
	if (n < m) return 0;
	return fac[n] * inv[n - m] % mod;
}

void solve() {

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dis[i][j] = inf;
			else dis[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int mi = *min_element(dis[i] + 1, dis[i] + n + 1);
		for (int j = 1; j <= n; j++) {
			if (dis[i][j] == mi) v[i].push_back(j);
		}
	}

	auto dfs1 = [&](auto self, int x) -> void{
		if (s.find(x) != s.end()) return;
		s.insert(x);
		for (auto j : v[x]) self(self, j);
	};

	auto dfs2 = [&](auto self, int x, int co) -> void{
		if (color[x] == co) return;
		color[x] = co;
		for (auto j : v[x]) self(self, j, co);
	};

	for (int i = 1; i <= n; i++) {
		if (color[i]) continue;
		col++;
		s.clear();
		dfs1(dfs1, i);

		int mi = *min_element(dis[i] + 1, dis[i] + n + 1), flag(0);
		set<int> st = s;
		for (auto x : s)
			for (auto y : st)
				if (x != y and dis[x][y] != mi) flag = 1;

		if (flag) color[i] = col, a.push_back(1);
		else dfs2(dfs2, i, col), a.push_back(s.size());
	}

	dp[0][0] = 1;
	int m = a.size();
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			(dp[i][j] += dp[i - 1][j - 1]) %= mod;
			if (j >= a[i - 1] and a[i - 1] != 1) (dp[i][j] += dp[i - 1][j - a[i - 1]]) % mod;
		}
	}
	int ans(0);
	for (int i = 1; i <= n; i++) {
		(ans += dp[m][i] * A(n, i) % mod) %= mod;
	}
	cout << ans << endl;

}
signed main() {
	init();
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}