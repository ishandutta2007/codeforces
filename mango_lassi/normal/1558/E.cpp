#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = (ll)1e9 + 7;
const int N = 1000;
vector<pair<ll, int>> g[N];
int zc[N];
bool used[N];
ll as[N];
ll bs[N];

ll min_str[N];
int pre[N];

ll res_a;
ll res_b;

pair<int, int> dfs(ll ini, int n) {
	for (int i = 0; i < n; ++i) {
		pre[i] = -1;
		min_str[i] = INF;
	}

	min_str[0] = ini;
	vector<int> que;
	for (int t = 0; t < n; ++t) {
		if (zc[t] == -1 || used[t] || as[t] >= ini) continue;
		
		min_str[t] = ini;
		if (zc[t] == -2) {
			pre[t] = 0;
			return {t, 0};
		} else {
			pre[t] = zc[t];
			que.push_back(t);
		}
	}

	for (int j = 0; j < que.size(); ++j) {
		int i = que[j];
		ll cur = min_str[i] + bs[i];
		for (auto pr : g[i]) {
			int t = pr.second;
			if (as[t] >= cur) break;
			if (t == pre[i]) continue;
			if (pre[t] != -1 || used[t]) return {t, i};

			pre[t] = i;
			min_str[t] = cur;
			que.push_back(t);
		}
	}
	return {-1, -1}; // No cycle we could return through. Since impossible to get stuck, also impossible to beat all monsters
}

void makeUsed(int i) {
	res_b += bs[i];
	used[i] = 1;
	for (auto pr : g[i]) {
		if (zc[pr.second] == -1) zc[pr.second] = i;
		else zc[pr.second] = -2;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	as[0] = 0;
	bs[0] = 0;
	for (int i = 0; i < n; ++i) zc[i] = -1;
	for (int i = 1; i < n; ++i) cin >> as[i];
	for (int i = 1; i < n; ++i) cin >> bs[i];
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].emplace_back(as[y], y);
		g[y].emplace_back(as[x], x);
	}
	for (int i = 0; i < n; ++i) sort(g[i].begin(), g[i].end());

	ll tot = 0;
	for (int i = 0; i < n; ++i) tot += bs[i];

	res_a = 0;
	res_b = 0;
	makeUsed(0);
	while(res_b < tot) {
		ll low = res_a + res_b;
		ll high = max(low, INF);
		while(low != high) {
			ll ini = (low + high) >> 1;
			pair<int, int> off = dfs(ini, n);
			if (off.first == -1) low = ini + 1;
			else high = ini;
		}

		res_a = low - res_b;
		pair<int, int> off = dfs(low, n);

		int x = off.first;
		int y = off.second;
		while(! used[x]) {
			makeUsed(x);
			x = pre[x];
		}
		while(! used[y]) {
			makeUsed(y);
			y = pre[y];
		}
	}
	cout << res_a << '\n';

	for (int i = 0; i < n; ++i) {
		g[i].clear();
		g[i].shrink_to_fit();
		used[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}