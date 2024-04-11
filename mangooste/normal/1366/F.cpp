#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = int(1e9) + 7;
const int INV2 = 500000004;
const ll INF = LLONG_MAX;

bool need_delete(pair<ll, ll> &a, pair<ll, ll> &b, pair<ll, ll> &c) {
	return (a.second - b.second) * (c.first - b.first) >= (b.first - a.first) * (b.second - c.second);
}

ll get_y_sum(pair<ll, ll> &line, int left_x, int right_x) {
	ll len = right_x - left_x + 1;
	if (len < 0)
		return 0;
	ll sum = len * (line.first * left_x % MOD + line.second);
	sum += len * (len - 1) % MOD * INV2 % MOD * line.first;
	return sum % MOD;
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--;
		graph[v].emplace_back(u, w);
		graph[u].emplace_back(v, w);
	}

	vector<vector<ll>> dist(n, vector<ll>(n, -INF));
	dist[0][0] = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			if (dist[j][i] != -INF)
				for (auto [v, w] : graph[j])
					dist[v][i + 1] = max(dist[v][i + 1], dist[j][i] + w);

	vector<pair<ll, ll>> lines;
	for (int i = 0; i < n; i++) {
		int max_edge = INT_MIN;
		for (auto [j, w] : graph[i])
			max_edge = max(max_edge, w);

		if (dist[i][n - 1] != -INF)
			lines.emplace_back(max_edge, dist[i][n - 1] - 1ll * (n - 1) * max_edge);
	}
	sort(lines.begin(), lines.end());

	vector<pair<ll, ll>> hull;
	for (auto line : lines) {
		while ((int(hull.size()) >= 2 && need_delete(hull.end()[-2], hull.back(), line))
			|| (!hull.empty() && hull.back().first == line.first))
			hull.pop_back();
		hull.push_back(line);
	}

	ll ans = 0;
	int lim = min(n, q + 1);
	for (int i = 0; i < lim; i++) {
		ll mx = -INF;
		for (int j = 0; j < n; j++)
			mx = max(mx, dist[j][i]);
		ans += mx % MOD;
	}

	int prev = lim;
	for (int i = 0; i < int(hull.size()) - 1; i++) {
		ll x_intersection = (hull[i].second - hull[i + 1].second) / (hull[i + 1].first - hull[i].first);
		x_intersection = min<ll>(x_intersection, q);

		ans += get_y_sum(hull[i], prev, x_intersection);
		prev = max<ll>(prev, x_intersection + 1);
	}
	ans += get_y_sum(hull.back(), prev, q);
	cout << int(ans % MOD) << '\n';
}