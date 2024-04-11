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
};

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll dfs(int i, vector<ll>& dist, const vector<vector<pair<int, ll>>>& g) {
	ll res = 0;
	for (auto pr : g[i]) {
		int t = pr.first;
		if (dist[t] == 0) {
			dist[t] = dist[i] + pr.second;
			res = gcd(res, dfs(t, dist, g));
		} else {
			if (dist[t] < dist[i]) res = gcd(res, dist[i] - dist[t] + pr.second);
			else res = gcd(res, abs((dist[t] - dist[i]) - pr.second));
		}
	}
	return res;
}
void fillVec(int i, vector<ll>& res, ll v, const vector<vector<pair<int, ll>>>& g) {
	res[i] = v;
	for (auto pr : g[i]) {
		int t = pr.first;
		if (res[t] == -1) fillVec(t, res, v, g);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<pair<int, int>, ll>> ed(m);
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		--a; --b;
		g[a].push_back(b);
		ed[i] = {{a, b}, w};
	}
	SCC scc(g);

	vector<vector<pair<int, ll>>> red_g(n);
	for (auto pr : ed) {
		int a = pr.first.first;
		int b = pr.first.second;
		ll w = pr.second;
		if (scc.getComp(a) == scc.getComp(b)) red_g[a].emplace_back(b, w);
	}

	vector<ll> dist(n, 0);
	vector<ll> cyc_gcd(n, -1);
	for (int i = 0; i < n; ++i) {
		if (dist[i] == 0) {
			dist[i] = 1;
			ll gd = dfs(i, dist, red_g);
			fillVec(i, cyc_gcd, gd, red_g);
		}
	}

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int i;
		ll s, t;
		cin >> i >> s >> t;
		--i;

		ll v = gcd(t, cyc_gcd[i]);
		if (s % v == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	
}