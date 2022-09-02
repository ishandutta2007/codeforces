#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int N = 2 * (int)1e5;
vector<int> conns[N];

ll dp0[N]; // Ways to take no connected groups from below
ll dp1[N]; // Ways to take one connected group from below
ll dp2[N]; // Ways to take multiple connected groups from below

void dfs(int i) {
	if (conns[i].empty()) {
		dp0[i] = 0;
		dp1[i] = 0;
		dp2[i] = 1;
	} else {
		for (auto t : conns[i]) dfs(t);

		int deg = conns[i].size();
		vector<ll> pref_prod(deg);
		vector<ll> suff_prod(deg);

		for (ll ti = 0, val = 1; ti < deg; ++ti) {
			int t = conns[i][ti];
			val = (val * (dp0[t] + dp2[t])) % MOD;
			pref_prod[ti] = val;
		}
		for (ll ti = deg-1, val = 1; ti >= 0; --ti) {
			int t = conns[i][ti];
			val = (val * (dp0[t] + dp2[t])) % MOD;
			suff_prod[ti] = val;
		}

		// dp0: \prod (dp0 + dp2) children
		dp0[i] = suff_prod[0];

		// dp1: \prod (dp0 + dp2) children, except one with (dp1 + dp2)
		dp1[i] = 0;
		for (int ti = 0; ti < deg; ++ti) {
			// cout << i << ' ' << ti << ": " << pref_prod[ti] << ' ' << suff_prod[ti] << '\n';
			int t = conns[i][ti];
			ll val = (dp1[t] + dp2[t]) % MOD;
			ll le = (ti == 0 ? 1 : pref_prod[ti-1]);
			ll ri = (ti == deg-1 ? 1 : suff_prod[ti+1]);
			ll mu = (le * ri) % MOD;
			dp1[i] += (val * mu) % MOD;
		}
		dp1[i] %= MOD;

		// dp2: \prod ((dp0 + dp2) + (dp1 + dp2)) - dp0 - dp1
		dp2[i] = 1;
		for (auto t : conns[i]) {
			ll val = ((dp0[t] + dp2[t]) + (dp1[t] + dp2[t])) % MOD;
			dp2[i] = (dp2[i] * val) % MOD;
		}

		dp2[i] = (dp2[i] - dp1[i] - dp0[i]) % MOD;
		if (dp2[i] < 0) dp2[i] += MOD;
	}
	// cout << i << ": " << dp0[i] << ' ' << dp1[i] << ' ' << dp2[i] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		conns[p].push_back(i);
	}

	dfs(0);
	ll res = (dp0[0] + dp2[0]) % MOD;
	cout << res << '\n';
}