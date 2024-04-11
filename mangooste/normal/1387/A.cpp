#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline bool equal(double a, double b) {
	return abs(a - b) < 1e-5;
}

int n, m;
vector<vector<pair<int, int>>> g;

array<vector<int>, 2> col;
vector<char> used;

vector<char> already;
vector<double> ans;

int num;
array<vector<int>, 2> comp;

vector<pair<int, int>> cur;

bool dfs(int v, int now, vector<int> &vers) {
	vers.push_back(v);
	used[v] = 1;
	comp[now][v] = num;

	bool ok = true;
	for (auto [u, tp] : g[v]) {
		if (tp != now)
			continue;
		ok &= (col[now][u] == -1 || col[now][u] == (col[now][v] ^ 1));
		col[now][u] = col[now][v] ^ 1;
		if (!used[u])
			ok &= dfs(u, now, vers);
	}
	return ok;
}

void dfs_fill(int v) {
	used[v] = 1;
	for (auto [u, tp] : g[v]) {
		if (already[u] && !equal((double) tp + 1, ans[v] + ans[u])) {
			cout << "NO\n";
			exit(0);
		}
		already[u] = 1;
		ans[u] = tp + 1 - ans[v];
		if (!used[u])
			dfs_fill(u);
	}
}

void dfs_solve(int v, vector<int> &vers) {
	vers.push_back(v);
	used[v] = 1;
	for (auto [u, tp] : g[v]) {
		if (used[u])
			continue;
		cur[u] = {-cur[v].first, tp + 1 - cur[v].second};
		dfs_solve(u, vers);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int v, u, tp;
		cin >> v >> u >> tp;
		v--, u--, tp--;
		g[v].emplace_back(u, tp);
		g[u].emplace_back(v, tp);
	}

	ans.resize(n);
	already.resize(n);

	array<vector<vector<int>>, 2> comps;
	for (int now = 0; now < 2; now++) {
		col[now].resize(n, -1);
		used = vector<char>(n, 0);
		num = 0;
		comp[now].resize(n);

		for (int i = 0; i < n; i++)
			if (!used[i]) {
				num++;
				vector<int> vers;
				col[now][i] = 0;
				if (!dfs(i, now, vers))
					for (auto u : vers) {
						if (already[u] && !equal(ans[u], (double) (now + 1) / 2))
							return cout << "NO\n", 0;
						already[u] = 1;
						ans[u] = (double) (now + 1) / 2;
					}

				comps[now].push_back(vers);
			}
	}

	for (int v = 0; v < n; v++)
		for (auto [u, tp] : g[v]) {
			if (comp[tp ^ 1][v] != comp[tp ^ 1][u])
				continue;
			if (col[tp ^ 1][v] != col[tp ^ 1][u])
				return cout << "NO\n", 0;

			already[v] = already[u] = 1;
			ans[v] = ans[u] = 1 - (1 - tp) * 0.5;
		}

	used = vector<char>(n, 0);
	for (int i = 0; i < n; i++)
		if (!used[i] && already[i])
			dfs_fill(i);

	used = vector<char>(n, 0);
	cur.resize(n);
	for (int i = 0; i < n; i++) {
		if (already[i] || used[i])
			continue;
		vector<int> vers;
		cur[i] = {1, 0};
		dfs_solve(i, vers);

		vector<double> solves;
		for (auto v : vers)
			for (auto [u, tp] : g[v]) {
				if (solves.size())
					break;
				int k = cur[v].first + cur[u].first;
				if (!k) {
					if (cur[v].second + cur[u].second != tp + 1)
						return cout << "NO\n", 0;
					continue;
				}
				solves.push_back((double) (tp + 1 - cur[v].second - cur[u].second) / k);
			}

		if (solves.size()) {
			for (auto v : vers)
				used[v] = 0;
			ans[i] = solves[0];
			already[i] = 1;
			dfs_fill(i);
			continue;
		}

		array<vector<int>, 2> types;
		for (auto v : vers)
			types[cur[v].first < 0].push_back(cur[v].second);
		for (auto &x : types)
			sort(x.begin(), x.end());
		array<vector<int>, 2> pref;
		for (int i = 0; i < 2; i++) {
			pref[i].push_back(0);
			for (int j = 0; j < types[i].size(); j++)
				pref[i].push_back(pref[i].back() + types[i][j]);
		}

		vector<int> all;
		for (auto v : vers) {
			if (cur[v].first > 0)
				all.push_back(-cur[v].second);
			else
				all.push_back(cur[v].second);
		}

		// cout << "all =";
		// for (auto x : all)
		// 	cout << ' ' << x;
		// cout << '\n';

		vector<pair<int, int>> maybe;
		for (auto x : all) {
			int now = 0;

			int pos = upper_bound(types[0].begin(), types[0].end(), -x) - types[0].begin();
			now += pref[0][types[0].size()] - pref[0][pos] + (types[0].size() - pos) * x;

			pos = lower_bound(types[0].begin(), types[0].end(), -x) - types[0].begin();
			now -= pref[0][pos] - pref[0][0] + pos * x;

			pos = upper_bound(types[1].begin(), types[1].end(), x) - types[1].begin();
			now += pref[1][types[1].size()] - pref[1][pos] - (types[1].size() - pos) * x;

			pos = lower_bound(types[1].begin(), types[1].end(), x) - types[1].begin();
			now -= pref[1][pos] - pref[1][0] - pos * x;

			// cout << "x = " << x << " now = " << now << '\n';
			maybe.emplace_back(now, x);
		}
		sort(maybe.begin(), maybe.end());

		ans[i] = maybe[0].second;
		already[i] = 1;
		for (auto v : vers)
			used[v] = 0;
		dfs_fill(i);
	}

	cout << "YES\n";
	for (auto x : ans)
		cout << x << ' ';
	cout << '\n';
}