#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// Struct for finding strongly connected components in a graph
// Condensed graph is in reverse topological order (node with no out-edges first)
// Complexity: O(n + m)
class SCC {
	private:
		Graph g;
		vector<int> comp, ind, sta;
		int di = 0, cc = 0;

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
	public:
		SCC(const Graph& gr) : g(gr), comp(gr.size(), -1), ind(gr.size(), -1) {
			for (int i = 0; i < g.size(); ++i) dfs(i);
		}
		int getComp(int i) const { return comp[i]; }
		int compCount() const { return cc; }
};

void solve() {
	int n;
	cin >> n;

	vector<int> as(n), bs(n);
	for (int& a : as) cin >> a;
	for (int& b : bs) cin >> b;

	// Answer is "n - max_v #occurrences of v"?
	// Lower bound: make cycle of one occurence of every value that occurs the most times
	// Upper bound: proof by AC?

	vector<int> cou(n + 1, 0);
	for (int a : as) ++cou[a];
	
	int r = 0;
	for (int i = 1; i <= n; ++i) {
		if (cou[i] > cou[r]) r = i;
	}

	bool works = 1;
	Graph g(n + 1);
	for (int i = 0; i < n; ++i) {
		if (bs[i] != r) {
			if (as[i] == bs[i]) works = 0;
			else g[as[i]].push_back(bs[i]);
		}
	}

	SCC scc(g);
	works &= (scc.compCount() == n + 1);
	if (! works) {
		// Cycle not containing the max occ value
		cout << "WA\n";
	} else {
		// Order where all edges either go to a node after you, or to the first node
		cout << "AC\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}