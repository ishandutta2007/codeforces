#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int N = 2 * (int)1e5;
vector<pair<int, int>> conns[N];
ll dp[N][3]; // 0: root eliminated before edge to parent, 1: eliminated by edge to parent, 2: never eliminated or eliminated after edge to parent

void mAdd(ll& a, ll b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

void solve(int i, int p) {
	sort(conns[i].begin(), conns[i].end());

	int m = conns[i].size();
	vector<ll> pref(m+1, 1); // product of (dp[c][0] + dp[c][1]) of prefix of children
	vector<ll> suff(m+1, 1); // product of (dp[c][0] + dp[c][2]) of suffix of children
	for (int j = 0; j < m; ++j) {
		int t = conns[i][j].second;
		if (t != p) {
			solve(t, i);
			pref[j+1] = (pref[j] * (dp[t][0] + dp[t][1])) % MOD;
		} else {
			pref[j+1] = pref[j];
		}
	}

	dp[i][2] = pref[m]; // Never eliminated

	int sta = 2;
	for (int j = m-1; j >= 0; --j) {
		int t = conns[i][j].second;
		if (t != p) {
			suff[j] = (suff[j+1] * (dp[t][0] + dp[t][2])) % MOD;
		} else {
			suff[j] = suff[j+1];
		}

		ll mult = pref[j] * suff[j+1] % MOD;
		if (t == p) --sta;
		else mult = mult * dp[t][2] % MOD;

		if (sta == 2) mAdd(dp[i][2], mult);
		if (sta == 1) mAdd(dp[i][1], mult);
		if (sta == 0) mAdd(dp[i][0], mult);

		if (t == p) --sta;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back({i, b});
		conns[b].push_back({i, a});
	}

	// Two different sets of eliminating edges cannot cause the same ordering of nodes
	// Proof: Assume doesn't hold, take counterexample, find first edge that eliminates something in exactly
	// 	one of the setups. But all eliminations before it must be the same, so it must eliminate something
	//	in both or in neither, a contradiction.

	conns[0].push_back({n, n}); // Add nonexistant edge to parent for root
	solve(0, n);
	ll res = (dp[0][0] + dp[0][2]) % MOD; // Nonexistant edge cannot remove the token at root
	cout << res << '\n';

}