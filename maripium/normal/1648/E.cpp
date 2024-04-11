#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	struct edge_t {
		int v, u, w, id;
		edge_t(int v = 0, int u = 0, int w = 0, int id = -1): v(v), u(u), w(w), id(id) {
		} 
		bool operator < (const edge_t &e) const {
			return w < e.w;
		}
	};

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;	
		
		vector<set<int>> adj(N);
		vector<edge_t> edges;
		for (int i = 0; i < M; ++i) {
			int v, u, w; cin >> v >> u >> w;
			edges.emplace_back(--v, --u, w, i);
			adj[v].insert(u);
			adj[u].insert(v);
		}

		sort(edges.begin(), edges.end());

		vector<int> par(N);
		vector<set<int>> verts(N); 
		vector<int> par2(N);
		vector<set<int>> verts2(N);
		vector<set<int>> roots(N);

		for (int i = 0; i < N; ++i) {
			par[i] = i;
			verts[i].insert(i);
			par2[i] = i;
			verts2[i].insert(i);
			roots[i].insert(i);
		}

		auto merge2 = [&](int v, int u) {
			assert(par[v] == par[u]);
			v = par2[v];
			u = par2[u];
			if (v == u) return false;
			int r = par[u];
			if (verts2[v].size() < verts2[u].size()) swap(v, u);
			for (int z : verts2[u]) {
				verts2[v].insert(z);
				par2[z] = v;
			}
			verts2[u] = {};
			roots[r].erase(u);
			return true;
		};

		auto merge = [&](int v, int u) {
			v = par[v];
			u = par[u];
			if (v == u) return;
			if (verts[v].size() < verts[u].size()) swap(v, u);

			for (int z : verts[u]) {
				par[z] = v;
				verts[v].insert(z);
			}

			for (int r : roots[u]) {
				roots[v].insert(r);
			}

			verts[u] = {};
			roots[u] = {};
		};

		vector<edge_t> edges2;
		for (auto [v, u, w, i] : edges) {
			v = par[v];
			u = par[u];
			if (v == u) continue;

			vector<edge_t> toAdd;
			for (int x : roots[v]) {
				vector<int> ys;
				for (int y : roots[u]) {
					if ([&]() {
						for (int a : verts2[x]) {
							for (int b : verts2[y]) {
								if (!adj[a].count(b)) return true;
							}
						}
						return false;
					}()) {
						ys.push_back(y);
					};
				}

				if (ys.size()) {
					int y1 = ys.back();
					toAdd.emplace_back(x, y1, w);
					for (int y : ys) {
						if (merge2(y, y1)) {
							edges2.emplace_back(y, y1, w);
						}
					}
				}
			}

			merge(v, u);
			for (auto [v0, u0, w0, i0] : toAdd) {
				if (merge2(v0, u0)) {
					edges2.emplace_back(v0, u0, w);	
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			par[i] = i;
			verts[i] = {i};
		}
		vector<set<int>> queries(N);
		for (auto [v, u, w, i] : edges) {
			queries[v].insert(i);
			queries[u].insert(i);
		}

		vector<int> ans(M);
		for (auto [v, u, w, _] : edges2) {

			// cerr << v << ' ' << u << ' ' << w << '\n';
			v = par[v];
			u = par[u];
			assert(v != u);
			if (verts[v].size() < verts[u].size()) swap(v, u);
			for (int z : verts[u]) {
				par[z] = v;
				verts[v].insert(z);
			}
			for (int i : queries[u]) {
				if (queries[v].count(i)) {
					queries[v].erase(i);
					ans[i] = w;
				} else {
					queries[v].insert(i);
				}
			}
		}

		for (int i = 0; i < M; ++i) {
			if (i) cout << ' ';
			cout << ans[i];
		}
		cout << '\n';
	}
	return 0;
}