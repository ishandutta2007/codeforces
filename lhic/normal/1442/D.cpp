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

const int N = 3100;

vector<ll> vv[N];
int n, k;

ll dpl[N][N];
ll dpr[N][N];

int av[N][N];


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		ll cs = 0;
		vv[i].push_back(cs);
		for (int j = 0; j < t; ++j) {
			int x;
			cin >> x;
			cs += x;
			vv[i].push_back(cs);
		}
	}

	for (int i = 0; i <= n; ++i) {
		av[i][0] = 1;
	}

	for (int i = 1; i <= k; ++i) {
		vector<pair<ll, int>> lst;
		for (int j = 0; j < n; ++j) {
			if (vv[j].size() > i) {
				lst.emplace_back(vv[j][i], j);
			}
		}
		sort(ALL(lst));
		reverse(ALL(lst));
		for (int j = 0; j < lst.size() && i * (j + 1) <= k; ++j) {
			av[lst[j].second][i] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		int sz = vv[i].size();
		--sz;
		for (int j = 0; j <= k; ++j) {
			dpl[i + 1][j] = dpl[i][j];
		}
		for (int j = k - sz; j >= 0; --j) {
			dpl[i + 1][j + sz] = max(dpl[i + 1][j + sz], dpl[i][j] + vv[i].back());
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		int sz = vv[i].size();
		--sz;
		for (int j = 0; j <= k; ++j) {
			dpr[i][j] = dpr[i + 1][j];
		}
		for (int j = k - sz; j >= 0; --j) {
			dpr[i][j + sz] = max(dpr[i][j + sz], dpr[i + 1][j] + vv[i].back());
		}
	}

	ll ans = max(dpl[n][k], dpr[0][k]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k && j < vv[i].size(); ++j) {
			if (av[i][j]) {
				for (int x = 0; x <= k - j; ++x) {
					ans = max(ans, dpl[i][x] + dpr[i + 1][k - j - x] + vv[i][j]);
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}