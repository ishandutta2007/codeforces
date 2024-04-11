#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
vector<int> conns[N];
ll dp[N];
ll siz[N];

void dfs0(int i = 0, int p = 0) {
	siz[i] = 1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs0(t, i);
		siz[i] += siz[t];
		dp[i] += dp[t];
	}
	dp[i] += siz[i];
}
ll dfs1(int i = 0, int p = 0, ll up_siz = 0, ll up_dp = 0) {
	ll res = dp[i] + up_siz + up_dp;
	for (auto t : conns[i]) {
		if (t == p) continue;
		ll nxt_siz = siz[i] + up_siz - siz[t];
		ll nxt_dp = dp[i] + (up_siz + up_dp) - (siz[t] + dp[t]);
		ll sub = dfs1(t, i, nxt_siz, nxt_dp);
		res = max(res, sub);
	}
	return res;
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
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	dfs0();
	ll res = dfs1();
	cout << res << '\n';
}