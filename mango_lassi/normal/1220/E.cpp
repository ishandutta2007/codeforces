#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

// Condenses components of nodes into single nodes. There is an edge from
// component X to Y if there's an edge from some node in X to some node in Y.
// Time complexity: O(n + m)
Graph getCond(int cc, const vector<int>& comp, const Graph& g) {
	vector<vector<int>> rev(cc);
	for (int i = 0; i < g.size(); ++i) rev[comp[i]].push_back(i);

	Graph res(cc);
	vector<bool> seen(cc, 0);
	for (int j = 0; j < cc; ++j) {
		for (auto i : rev[j]) {
			for (auto ti : g[i]) {
				int t = comp[ti];
				if (t == j || seen[t]) continue;
				res[j].push_back(t);
				seen[t] = true;
			}
		}
		for (auto t : res[j]) seen[t] = false;
	}
	return res;
}

// Class for finding bridges in an undirected graph. Assumes there are no self-loops.
// Time complexity (of construction): O(n + m)
class Bridges {
	private:
		const Graph& g;
		vector<int> comp, dep; 
		int di = 0, cc = 0;

		void flood(int i, int ban, bool s = 1) {
			comp[i] = cc;
			for (auto t : g[i]) {
				if (t != ban && comp[t] == -1) flood(t, ban, 0);
			}
			if (s) ++cc;
		}
		int dfs(int i, int p) {
			dep[i] = dep[p] + 1;
			int res = dep[i];

			for (auto t : g[i]) {
				if (dep[t]) {
					if (t == p) p = -1;
					else res = min(res, dep[t]);
				} else {
					int sub = dfs(t, i);
					if (sub > dep[i]) flood(t, i); // Bridge
					else res = min(res, sub);
				}
			}
			if (p == i) flood(i, -1);
			return res;
		}
	public:
		Bridges(const Graph& gr) : g(gr), comp(gr.size(), -1), dep(gr.size(), 0) {
			for (int i = 0; i < g.size(); ++i) {
				if (! dep[i]) dfs(i, i);
			}
		}
		bool isBridge(int a, int b) const { return comp[a] != comp[b]; }
		int operator[](int i) const { return comp[i]; }
		Graph condense() const { return getCond(cc, comp, g); }
};

tuple<ll, ll, bool> solve(int i, int p, const vector<ll>& vals, const vector<int>& siz, const Graph& g) {
	ll rs = 0;
	ll sink = 0;
	bool ret = (siz[i] > 1);
	for (auto t : g[i]) {
		if (t == p) continue;
		ll sub_rs, sub_sink;
		bool sub_ret;
		tie(sub_rs, sub_sink, sub_ret) = solve(t, i, vals, siz, g);
		rs += sub_rs;
		sink = max(sink, sub_sink);
		ret |= sub_ret;
	}

	if (ret) rs += vals[i];
	else sink += vals[i];

	return {rs, sink, ret};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> orig(n);
	for (int i = 0; i < n; ++i) cin >> orig[i];

	Graph tmp(n);
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		tmp[a].push_back(b);
		tmp[b].push_back(a);
	}

	Bridges bd(tmp);
	Graph g = bd.condense();

	int c = g.size();
	vector<ll> vals(c, 0);
	vector<int> siz(c, 0);
	for (int i = 0; i < n; ++i) {
		vals[bd[i]] += orig[i];
		++siz[bd[i]];
	}

	int s;
	cin >> s;
	s = bd[s-1];

	ll rs, sink;
	bool ret;
	tie(rs, sink, ret) = solve(s, s, vals, siz, g);
	cout << rs + sink << '\n';
}