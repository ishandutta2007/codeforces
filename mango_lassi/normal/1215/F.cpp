#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// Struct for finding strongly connected components in a graph
// Condensed graph is in reverse topological order
// "comp" gives component in condensed graph that node i is in
// Time Complexity: O(n + m)
struct SCC {
	Graph g;
	vector<int> comp;
	vector<int> ind;
	vector<int> sta;
	int di = 0; // DFS counter
	int cc = 0; // Comp count

	int dfs(int i) {
		if (ind[i] != -1) return (comp[i] == -1) ? ind[i] : di;
		ind[i] = di;
		int md = di;
		++di;

		sta.push_back(i);
		for (auto t : g[i]) md = min(md, dfs(t));

		if (md == ind[i]) {
			while(comp[i] == -1) {
				comp[sta.back()] = cc;
				sta.pop_back();
			}
			++cc;
		}
		return md;
	}
	SCC(const Graph& gr) : g(gr), comp(gr.size(), -1), ind(gr.size(), -1) {
		for (int i = 0; i < g.size(); ++i) dfs(i);
	}
};

// Struct for solving twosat
// addClause(i, twosat.neg(j)) adds clause i, -j
// solve() returns empty vector if unsolvable
// Time Complexity: O(n + m)
struct TwoSat {
	const int n;
	Graph g; // Implication graph, of size 2*n

	TwoSat(int nodes) : n(nodes), g(2*nodes) {}

	int neg(int i) {
		return i >= n ? i-n : i+n;
	}
	void addClause(int a, int b) {
		g[neg(a)].push_back(b);
		g[neg(b)].push_back(a);
	}
	vector<bool> solve() {
		SCC scc(g);

		vector<int> inv(scc.cc);
		for (int i = 0; i < 2*n; ++i) {
			inv[scc.comp[i]] = scc.comp[neg(i)];
		}

		vector<int> state(scc.cc, -1);
		for (int i = 0; i < scc.cc; ++i) {
			if (state[i] != -1) continue;
			if (i == inv[i]) return {};
			state[i] = 1;
			state[inv[i]] = 0;
		}

		vector<bool> res(n);
		for (int i = 0; i < n; ++i) res[i] = state[scc.comp[i]];
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int c, n, mxf, m; // complaints, stations, max signal strength, frequency issues
	cin >> c >> n >> mxf >> m;
	mxf += 2; // Add frequencies 0 and mxf + 1

	TwoSat sat(n + 2*mxf);

	// p_i: Some segment starts after this point. p_i => p_i-1. Indexes [n, n + mxf)
	// s_i: Some segment ends at or before this point. s_i => s_i+1. Indexes [n + mxf, n + 2mxf)
	// Segments are disjoint if p_i && s_i for some i
	for (int i = 0; i < mxf; ++i) {
		sat.addClause(sat.neg(n + i), sat.neg(n+mxf + i)); // !p_i or !s_i
		if (i+1 < mxf) {
			sat.addClause(sat.neg(n + i+1), n + i); // p_i or !p_i+1 : p_i+1 => p_i
			sat.addClause(sat.neg(n+mxf + i), n+mxf + i+1); // !s_i or s_i+1 : s_i => s_i+1
		}
	}

	// Must get either station a or b
	for (int i = 0; i < c; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		sat.addClause(a, b);
	}

	// Stations must have some overlap in wanted ranges
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		sat.addClause(sat.neg(i), n + (l-1)); // !seg_i or p_l-1: seg_i => p_l-1
		sat.addClause(sat.neg(i), n+mxf + r); // !seg_i or s_r: seg_i => s_r
	}

	// Must not get both station i and j
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		sat.addClause(sat.neg(a), sat.neg(b));
	}

	// Solve and output!
	vector<bool> res = sat.solve();
	if (res.empty()) {
		cout << -1 << '\n';
	} else {
		int k = 0;
		for (int i = 0; i < n; ++i) {
			if (res[i]) ++k;
		}
		int f = -1;
		for (int i = 0; f == -1; ++i) {
			if (res[n+mxf + i]) f = i;
		}

		cout << k << ' ' << f << '\n';
		for (int i = 0; i < n; ++i) {
			if (res[i]) cout << i+1 << ' ';
		}
		cout << '\n';
	}
}