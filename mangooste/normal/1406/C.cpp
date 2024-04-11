#include <bits/stdc++.h>

using namespace std;

template<class T>
string to_string(T v);

string to_string(string s) {
	return "\"" + s + "\"";
}

string to_string(bool b) {
	return b ? "true" : "false";
}

template<class A, class B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class T>
string to_string(T v) {
	string s = "{";
	bool first = true;
	for (auto x : v) {
		if (!first)
			s += ", ";
		first = false;
		s += to_string(x);
	}
	return s + "}";
}

void debug_out() { cerr << endl; }
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}

#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

vector<vector<int>> g;
vector<int> sz;
vector<pair<int, int>> all;

void dfs1(int v, int pr) {
	sz[v] = 1;
	for (auto u : g[v])
		if (u != pr) {
			dfs1(u, v);
			sz[v] += sz[u];
		}
}

void dfs2(int v, int pr, int up_sz) {
	// debug(v, pr, up_sz);
	int mx_sz = 0;
	for (auto u : g[v])
		if (u != pr)
			mx_sz = max(mx_sz, sz[u]);

	all.emplace_back(max(up_sz, mx_sz), v);
	int sum = up_sz + 1;
	for (auto u : g[v])
		if (u != pr)
			sum += sz[u];

	for (auto u : g[v])
		if (u != pr)
			dfs2(u, v, sum - sz[u]);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		g.clear();
		sz.clear();
		all.clear();

		int n;
		cin >> n;
		g.resize(n);
		for (int i = 1; i < n; i++) {
			int v, u;
			cin >> v >> u;
			v--, u--;
			g[v].push_back(u);
			g[u].push_back(v);
		}

		sz.resize(n, 1);
		dfs1(0, 0);
		dfs2(0, 0, 0);

		sort(all.begin(), all.end());
		// debug(all);
		vector<int> centroids;
		for (int i = 0; i < n; i++)
			if (all[i].first == all[0].first)
				centroids.push_back(all[i].second);

		debug(centroids);
		assert((int) centroids.size() < 3);
		if ((int) centroids.size() == 1) {
			cout << 1 << ' ' << g[0][0] + 1 << '\n';
			cout << 1 << ' ' << g[0][0] + 1 << '\n';
		} else {
			int v = centroids[0];
			int u = centroids[1];
			assert((int) g[v].size() > 1);
			assert((int) g[u].size() > 1);
			int del = -1;
			for (auto w : g[v])
				if (w != u) {
					cout << v + 1 << ' ' << w + 1 << '\n';
					del = w;
					break;
				}

			cout << del + 1 << ' ' << u + 1 << '\n';
		}
	}
}