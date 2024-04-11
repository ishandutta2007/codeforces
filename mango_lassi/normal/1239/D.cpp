#include <iostream>
#include <vector>
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
		int compCount() const { return cc; }
		int operator[](int i) const { return comp[i]; }
};

void solve() {
	int n, m;
	cin >> n >> m;

	// Possible IFF we can pick some subset of cats that only ban their owners
	// -> If we pick cat, we need to pick all cats owned by people who are friends with that cat
	// -> Build DAG of cats. If it contains more than one component, we're done

	Graph g(n);
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[b].push_back(a);
	}
	SCC scc(g);
	int cc = scc.compCount();
	if (cc == 1) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		
		int cou = 0;
		vector<bool> pick(n, false);
		for (int i = 0; i < n; ++i) {
			if (scc[i] == 0) {
				pick[i] = true;
				++cou;
			}
		}
		cout << n-cou << ' ' << cou << '\n';
		for (int i = 0; i < n; ++i) {
			if (!pick[i]) cout << i+1 << ' ';
		}
		cout << '\n';
		for (int i = 0; i < n; ++i) {
			if (pick[i]) cout << i+1 << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}