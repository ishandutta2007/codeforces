#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;

// Struct for finding strongly connected components in a graph
// Condensed graph is in reverse topological order
// "comp" gives component in condensed graph that node i is in
// Complexity: O(n + m)
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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

const int N = (int)1e5 + 10;
vector<bool> open[N];
vector<bool> reach[N];
int comp_gd[N];
int shift[N];
vector<int> score[N];
vector<int> dp[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, d;
	cin >> n >> m >> d;

	Graph g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
	}
	for (int i = 0; i < n; ++i) {
		open[i].resize(d, false);
		string str;
		cin >> str;
		for (int j = 0; j < d; ++j) {
			if (str[j] == '1') open[i][j] = true;
		}
	}
	// CORRECT to this point
	
	// Find all strongly connected components, and the GCD of the lengths of the cycles inside that component
	// To do this, make DP[N][T], and start DFS from some node in the component, with time = 0
	SCC scc(g);

	for (int i = 0; i < n; ++i) reach[i].resize(d, false);
	vector<vector<int>> inv_comp(scc.cc);
	for (int i = 0; i < n; ++i) {
		inv_comp[scc.comp[i]].push_back(i);
	}

	for (int j = 0; j < scc.cc; ++j) {
		int s = inv_comp[j][0];
		vector<pair<int, int>> que;
		que.emplace_back(s, 0);
		reach[s][0] = true;

		// Find all times that we can return to the source
		for (int jj = 0; jj < que.size(); ++jj) {
			int i = que[jj].first;
			int dif = que[jj].second;
			int next_dif = (dif + 1) % d;
			for (auto t : g[i]) {
				if (scc.comp[t] != j) continue;
				if (reach[t][next_dif]) continue;
				reach[t][next_dif] = true;
				que.emplace_back(t, next_dif);
			}
		}

		// comp_gd: GCD of d and lengths of cycles in the graph
		comp_gd[j] = d;
		for (int dif = 1; dif < d; ++dif) {
			if (reach[s][dif]) {
				comp_gd[j] = dif;
				break;
			}
		}
		comp_gd[j] = gcd(comp_gd[j], d);

		// Find which museums you can visit when entering the cycle
		dp[j].resize(comp_gd[j], 0);
		score[j].resize(comp_gd[j], 0);
		for (auto i : inv_comp[j]) {
			shift[i] = -1;
			for (int dif = 0; dif < d; ++dif) {
				if (reach[i][dif]) {
					shift[i] = dif;
					break;
				}
			}
			vector<bool> add(comp_gd[j], false);
			for (int dif = 0; dif < d; ++dif) {
				if (open[i][dif]) add[(dif - shift[i] + comp_gd[j]) % comp_gd[j]] = true;
			}
			for (int dif = 0; dif < comp_gd[j]; ++dif) {
				score[j][dif] += add[dif];
			}
		}

		// cout << "Comp " << j << ": " << comp_gd[j] << ": ";
		// for (auto v : score[j]) cout << v << ' '; cout << '\n';
	}

	// Calculate DP
	for (int j = 0; j < scc.cc; ++j) {
		for (int dif = 0; dif < comp_gd[j]; ++dif) reach[j][dif] = false;
	}
	reach[scc.comp[0]][0] = true;

	int ans = 0;
	// scc.comp is in inverse topological order: Comp that cannot reach anywhere is comp 0
	for (int j = scc.comp[0]; j >= 0; --j) {
		for (int bd = 0; bd < comp_gd[j]; ++bd) {
			if (! reach[j][bd]) continue;
			int base = score[j][bd] + dp[j][bd];
			// cout << j << ' ' << bd << ' ' << base << '\n';
			ans = max(ans, base);

			for (auto i : inv_comp[j]) {
				for (auto t : g[i]) {
					int tc = scc.comp[t];
					if (tc == j) continue;

					int co_gd = gcd(comp_gd[j], comp_gd[tc]);
					int ini_dif = (bd + shift[i] - shift[t] + 1) % co_gd;
					if (ini_dif < 0) ini_dif += co_gd;

					for (int dif = ini_dif; dif < comp_gd[tc]; dif += co_gd) {
						reach[tc][dif] = true;
						dp[tc][dif] = max(dp[tc][dif], base);
					}
				}
			}
		}
	}
	cout << ans << '\n';
}