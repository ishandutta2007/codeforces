
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct color {
	int c;
	color(int c) : c(c) {}
};

struct color_matroid {
	vector<int> cnt, a;
	color_matroid(vector<int> cnt) : cnt(cnt.begin(), cnt.end()), a(cnt.size()) {}
	void clear() {
		fill(a.begin(), a.end(), 0);
	}
	void add(const color &x) {
		a[x.c]++;
	}
	void prepare() {}
	bool free(const color &x) {
		return a[x.c] < cnt[x.c];
	}
	bool exchange(const color &x, const color &y) {
		a[x.c]--;
		bool ans = (a[y.c] < cnt[y.c]);
		a[x.c]++;
		return ans;
	}
};

struct edge {
	int u, v;
	edge(int u, int v) : u(u), v(v) {}
};

struct graph_matroid {
	int n;
	vector<vector<int>> g;
	vector<int> tin, tout, comp;
	int ti;
	graph_matroid(int n) : n(n), g(n), tin(n), tout(n), comp(n) {}
	void clear() {
		for(int i = 0; i < n; i++) {
			g[i].clear();
		}
	}
	void add(const edge &x) {
		g[x.u].push_back(x.v);
		g[x.v].push_back(x.u);
	}
	void dfs(int x) {
		tin[x] = ti++;
		for(int y : g[x]) {
			if(tin[y] == 0) {
				comp[y] = comp[x];
				dfs(y);
			}
		}
		tout[x] = ti++;
	}
	void prepare() {
		fill(tin.begin(), tin.end(), 0);
		ti = 1;
		for(int i = 0; i < n; i++) {
			if(tin[i] == 0) {
				comp[i] = i;
				dfs(i);
			}
		}
	}
	bool anc(int x, int y) const {
		return tin[x] <= tin[y] && tout[y] <= tout[x];
	}
	bool free(const edge &x) const {
		return comp[x.u] != comp[x.v];
	}
	bool exchange(const edge &x, const edge &y) const {
		if(comp[y.u] != comp[y.v]) return true;
		int u = (tin[x.u] < tin[x.v] ? x.v : x.u);
		return anc(u, y.u) ^ anc(u, y.v);
	}
};

template<typename M1, typename E1, typename M2, typename E2>
struct matroid_intersection {
	M1 m1;
	M2 m2;
	matroid_intersection(M1 m1, M2 m2) : m1(m1), m2(m2) {}
	vector<int> solve(const vector<pair<E1, E2>> &e) {
		int rank = 0, n = (int) e.size();
		vector<int> par(n, -1);
		vector<bool> used(n, false);
		vector<int> basis;
		while(true) {
			queue<int> Q;
			m1.clear(); m2.clear(); basis.clear();
			fill(par.begin(), par.end(), -1);
			for(int i = 0; i < n; i++) {
				if(used[i]) {
					basis.push_back(i);
					m1.add(e[i].first);
					m2.add(e[i].second);
				}
			}
			m1.prepare(); m2.prepare();
			
			bool aug = false;
			auto enqueue = [&](int i, int j) {
				par[j] = i;
				Q.push(j);
				if(!used[j] && m2.free(e[j].second)) {
					do {
						used[j] = !used[j];
						j = par[j];
					}while(j != par[j]);
					aug = true;
				}
				return aug;
			};
			for(int i = 0; i < n; i++) {
				if(!used[i] && m1.free(e[i].first)) {
					if(enqueue(i, i)) break;
				}
			}
			while(!Q.empty() && !aug) {
				int i = Q.front(); Q.pop();
				if(used[i]) {
					for(int j = 0; j < n; j++) {
						if(!used[j] && par[j] == -1 && m1.exchange(e[i].first, e[j].first)) {
							if(enqueue(i, j)) break;
						}
					}
				}else {
					for(int j : basis) {
						if(par[j] == -1 && m2.exchange(e[j].second, e[i].second)) {
							if(enqueue(i, j)) break;
						}
					}
				}
			}
			if(aug) rank++;
			else break;
		}
		return basis;
	}
	template<typename Cost>
	vector<int> solve(const vector<pair<E1, E2>> &e, const vector<Cost> &cost) {
		int rank = 0, n = (int) e.size();
		vector<bool> used(n, false);
		const Cost MX = numeric_limits<Cost>::max();
		vector<vector<Cost>> dist(2, vector<Cost>(n, MX));
		vi par(n, -1);
		vector<vector<int>> g(n);
		while(true) {
			m1.clear(); m2.clear();
			for(int i = 0; i < n; i++) {
				g[i].clear();
				if(used[i]) {
					m1.add(e[i].first);
					m2.add(e[i].second);
				}
			}
			m1.prepare(); m2.prepare();
			
			for(int i = 0; i < n; i++) {
				if(!used[i] && m2.free(e[i].second)) {
					dist[0][i] = cost[i];
					par[i] = i;
				}else {
					dist[0][i] = MX;
					par[i] = -1;
				}
				if(used[i]) {
					for(int j = 0; j < n; j++) {
						if(!used[j]) {
							if(m1.exchange(e[i].first, e[j].first)) {
								g[i].push_back(j);
							}
							if(m2.exchange(e[i].second, e[j].second)) {
								g[j].push_back(i);
							}
						}
					}
				}
			}
			Cost best = MX;
			int idx = -1;
			bool go = true;
			while(go) {
				go = false;
				for(int i = 0; i < n; i++) {
					if(dist[0][i] < best && m1.free(e[i].first)) {
						best = dist[0][i];
						idx = i;
					}
					dist[1][i] = dist[0][i];
					Cost c = (used[i] ? -cost[i] : cost[i]);
					for(int j : g[i]) {
						if(dist[0][j] != MX && c + dist[0][j] < dist[1][i]) {
							go = true;
							dist[1][i] = c + dist[0][j];
							par[i] = j;
						}
					}
				}
				dist[0].swap(dist[1]);
			}
			if(idx == -1) break;
			rank++;
			while(par[idx] != idx) {
				used[idx] = !used[idx];
				idx = par[idx];
			}
			used[idx] = !used[idx];
		}
		vector<int> basis;
		for(int i = 0; i < n; i++) {
			if(used[i]) {
				basis.push_back(i);
			}
		}
		return basis;
	}
};

struct dsu {
    vector<int> a;
    dsu(int n) : a(n, -1) {}
    int find(int x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }
    int size(int x) {
        return -a[find(x)];
    }
    bool join(int x, int y) {
        if((x = find(x)) == (y = find(y))) return false;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi d(k + 1);
	rep(i, 1, k + 1) cin >> d[i];
	d[0] = n * n;
	vector<vi> w(n + 1, vi(n + 1));
	rep(i, 1, n + 1) {
		rep(j, i + 1, n + 1) {
			cin >> w[i][j];
		}
	}

	using M1 = graph_matroid;
	using M2 = color_matroid;

	dsu D2(n + 1);
	vector<pair<int, edge>> ve;
	rep(i, k + 1, n + 1) rep(j, i + 1, n + 1) {
		ve.push_back({w[i][j], edge(i, j)});
	}
	sort(all(ve), [&](auto &a, auto &b) { return a.first < b.first; });
	vector<edge> mst;
	for(auto &pa : ve) {
		int u = pa.second.u, v = pa.second.v;
		if(D2.find(u) != D2.find(v)) {
			D2.join(u, v);
			mst.push_back(pa.second);
		}
	}

	dsu D(k + 1);
	int ed = k * (k - 1) / 2;
	int ans = INT_MAX;
	rep(mask, 0, 1 << ed) {
		fill(all(D.a), -1);
		int idx = 0;
		bool ok = true;
		int cost = 0;
		int num = 0;
		vi d2(all(d));
		rep(i, 1, k + 1) {
			rep(j, i + 1, k + 1) {
				if(mask >> idx & 1) {
					if(D.find(i) == D.find(j)) {
						ok = false;
					}
					if(--d2[i] < 0) ok = false;
					if(--d2[j] < 0) ok = false;
					num++;
					D.join(i, j);
					cost += w[i][j];
				}
				idx++;
			}
		}
		if(ok) {
			M1 m1(n + 1);
			M2 m2(d2);

			vector<pair<edge, color>> e;
			vi weight;
			rep(i, 1, k + 1) rep(j, k + 1, n + 1) {
				e.push_back({edge(D.find(i), j), color(i)});
				weight.push_back(w[i][j]);
			}
			for(auto &ed : mst) {
				e.push_back({ed, color(0)});
				weight.push_back(w[ed.u][ed.v]);
			}

			matroid_intersection<M1, edge, M2, color> I(m1, m2);
			vi basis = I.solve(e, weight);
			if(sz(basis) + num != n - 1) continue;
			for(int i : basis) {
				cost += weight[i];
			}
			ans = min(ans, cost);
		}
	}
	cout << ans << '\n';
}