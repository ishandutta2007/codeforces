#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

const int N = 2 * (int)1e5;
vector<int> g[N];
ll as[N];
ll dp[N];

ll dfs(int i, ll mid) {
	if (dp[i] != 0) return (dp[i] > 0 ? dp[i] : INF);

	dp[i] = -1;
	ll off = 1;
	for (int t : g[i]) {
		if (as[t] > mid) continue;
		off = max(off, 1 + dfs(t, mid));
		if (off >= INF) return INF;
	}
	dp[i] = off;
	return off;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	ll k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
	}

	ll low = 1;
	ll high = INF;
	while(low != high) {
		ll mid = (low + high) >> 1;
		for (int i = 0; i < n; ++i) dp[i] = 0;
		
		ll off = 0;
		for (int i = 0; i < n && off < k; ++i) {
			if (as[i] <= mid) off = max(off, dfs(i, mid));
		}
		if (off >= k) high = mid;
		else low = mid + 1;
	}

	if (low >= INF) cout << -1 << '\n';
	else cout << low << '\n';
}