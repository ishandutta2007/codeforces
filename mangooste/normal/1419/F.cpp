#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2.1e9;

int n;
vector<int> x, y;
map<int, vector<int>> row;
map<int, vector<int>> col;

vector<vector<int>> g;
vector<pair<int, int>> edges;
int now = 0;
vector<int> num;

inline void clear_all() {
	g = vector<vector<int>>(n);
	edges.clear();
	now = 0;
	num = vector<int>(n, -1);
}

inline void add_edge(int v, int u) {
	g[v].push_back(u);
	g[u].push_back(v);
}

void dfs(int v) {
	num[v] = now;
	for (auto u : g[v])
		if (num[u] == -1)
			dfs(u);
}

bool check(int t) {
	clear_all();
	for (auto [x_, all] : col)
		for (int i = 1; i < (int) all.size(); i++) {
			int v = all[i - 1];
			int u = all[i];
			if (y[u] - y[v] <= t)
				add_edge(v, u);
		}

	for (auto [y_, all] : row)
		for (int i = 1; i < (int) all.size(); i++) {
			int v = all[i - 1];
			int u = all[i];
			if (x[u] - x[v] <= t)
				add_edge(v, u);
		}

	for (int i = 0; i < n; i++)
		if (num[i] == -1) {
			dfs(i);
			now++;
		}

	for (auto [x_, all] : col)
		for (int i = 0; i < (int) all.size() - 1; i++) {
			int v = all[i];
			int u = all[i + 1];
			if (num[v] != num[u])
				edges.emplace_back(v, u);
		}

	for (auto [y_, all] : row)
		for (int i = 0; i < (int) all.size() - 1; i++) {
			int v = all[i];
			int u = all[i + 1];
			if (num[v] != num[u])
				edges.emplace_back(v, u);
		}
	
	if (now == 1)
		return true;
	if (now == 2) {
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (num[i] != num[j]) {
					if (x[i] == x[j] && abs(y[i] - y[j]) <= 2ll * t)
						return true;
					if (y[i] == y[j] && abs(x[i] - x[j]) <= 2ll * t)
						return true;
					if (max(abs(x[i] - x[j]), abs(y[i] - y[j])) <= t)
						return true;
				}

		return false;
	}
	if (now == 3) {
		for (auto [v, u] : edges)
			for (int i = 0; i < n; i++)
				if (num[i] != num[v] && num[i] != num[u]) {
					assert(y[v] <= y[u]);
					assert(x[v] <= x[u]);
					if (y[v] == y[u] && abs(y[v] - y[i]) <= t && x[v] <= x[i] && x[i] <= x[u] && max(x[u] - x[i], x[i] - x[v]) <= t)
						return true;
					if (x[v] == x[u] && abs(x[v] - x[i]) <= t && y[v] <= y[i] && y[i] <= y[u] && max(y[u] - y[i], y[i] - y[v]) <= t)
						return true;
				}

		return false;
	}
	if (now == 4) {
		for (int i = 0; i < (int) edges.size(); i++) {
			auto [v1, u1] = edges[i];
			if (num[v1] == num[u1])
				continue;
			for (int j = i + 1; j < (int) edges.size(); j++) {
				auto [v2, u2] = edges[j];
				if (num[v2] == num[u2])
					continue;
				vector<int> now{num[v1], num[v2], num[u1], num[u2]};
				sort(now.begin(), now.end());
				if (now != vector<int>{0, 1, 2, 3})
					continue;
				if ((x[v1] == x[u1]) == (x[v2] == x[u2]))
					continue;
				if (x[v1] == x[u1]) {
					if (y[v1] <= y[v2] && y[v2] <= y[u1] && x[v2] <= x[v1] && x[v1] <= x[u2])
						if (max({y[v2] - y[v1], y[u1] - y[v2], x[v1] - x[v2], x[u2] - x[v1]}) <= t)
							return true;
				} else {
					swap(v1, v2);
					swap(u1, u2);
					if (y[v1] <= y[v2] && y[v2] <= y[u1] && x[v2] <= x[v1] && x[v1] <= x[u2])
						if (max({y[v2] - y[v1], y[u1] - y[v2], x[v1] - x[v2], x[u2] - x[v1]}) <= t)
							return true;
					swap(v1, v2);
					swap(u1, u2);
				}
			}
		}
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	x.resize(n);
	y.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		col[x[i]].push_back(i);
		row[y[i]].push_back(i);
	}
	for (auto &[x_, all] : col) {
		sort(all.begin(), all.end(), [&](int i, int j) {
			assert(y[i] != y[j]);
			return y[i] < y[j];
		});
	}
	for (auto &[y_, all] : row) {
		sort(all.begin(), all.end(), [&](int i, int j) {
			assert(x[i] != x[j]);
			return x[i] < x[j];
		});
	}
	
	int L = 0, R = INF;
	while (R - L > 1) {
		int t = ((long long) L + R) / 2;
		if (check(t))
			R = t;
		else
			L = t;
	}
	if (R == INF)
		R = -1;
	cout << R << '\n';
}