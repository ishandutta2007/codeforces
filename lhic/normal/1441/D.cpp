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

int n;

int c[N];

vector<int> eds[N];
int ans = 0;

int dp[N][2];
int was[N];

void dfs1(int v) {
	was[v] = 1;
	dp[v][0] = dp[v][1] = 0;
	if (c[v] == 1) {
		dp[v][0] = 1;
	} else if (c[v] == 2) {
		dp[v][1] = 1;
	}

	for (int u : eds[v]) {
		if (was[u]) {
			continue;
		}

		dfs1(u);

		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				int l = dp[v][i] + dp[u][j];
				if (i == j) {
					--l;
				}
				ans = max(ans, l);
			}
		}

		if (c[v] == 0) {
			dp[v][0] = max(dp[v][0], dp[u][0]);
			dp[v][1] = max(dp[v][1], dp[u][1]);
		} else if (c[v] == 1) {
			dp[v][0] = max({dp[v][0], dp[u][0], dp[u][1] + 1});
		} else {
			dp[v][1] = max({dp[v][1], dp[u][1], dp[u][0] + 1});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> c[i];
		}
		for (int i = 0; i < n; ++i) {
			eds[i].clear();
			was[i] = 0;
		}

		ans = 0;

		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			cin >> a >> b;
			--a, --b;
			eds[a].push_back(b);
			eds[b].push_back(a);
		}

		dfs1(0);

		cout << (ans / 2) + 1 << "\n";
	}
	return 0;
}