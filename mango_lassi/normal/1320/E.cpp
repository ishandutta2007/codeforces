#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = 4 * (ll)1e18;

class HLD {
	private:
		vector<int> par, siz, cmp, ind, dep;

		int dfs1(int i, vector<vector<int>>& g) {
			for (auto& t : g[i]) {
				if (t == par[i]) continue;
				par[t] = i;
				dep[t] = dep[i] + 1;
				siz[i] += dfs1(t, g);
				if (siz[t] > siz[g[i][0]] || g[i][0] == par[i]) swap(t, g[i][0]);
			}
			return siz[i];
		}
		void dfs2(int i, int& x, const vector<vector<int>>& g) {
			ind[i] = x;
			++x;
			for (auto t : g[i]) {
				if (t == par[i]) continue;
				cmp[t] = (x == ind[i]+1 ? cmp[i] : t);
				dfs2(t, x, g);
			}
		}
	public:
		// Assumes the tree is connected and r is the root
		HLD(vector<vector<int>> g, int r = 0)
				: par(g.size(), -1), siz(g.size(), 1), cmp(g.size(), r), ind(g.size()), dep(g.size(), 0) {
			dfs1(r, g);
			int x = 0;
			dfs2(r, x, g);
		}
		int lca(int a, int b) const {
			for (;; b = par[cmp[b]]) {
				if (ind[b] < ind[a]) swap(a, b);
				if (ind[cmp[b]] <= ind[a]) return a;
			}
		}
		pair<int, int> subtree(int i) const {
			return {ind[i], ind[i] + siz[i] - 1};
		}
		int dist(int a, int b) const {
			if (ind[a] > ind[b]) swap(a, b);
			if (ind[a] + siz[a] > ind[b]) return dep[b] - dep[a];
			else return dep[a] + dep[b] - 2 * dep[lca(a, b)];
		}

		// Builds the tree induced by the given vertices
		// ith vertex of induced tree corresponds to ith vertex in the input
		// (Vertices in the induced tree not in the input will be added to it)
		vector<vector<pair<int, int>>> inducedTree(vector<int>& v) const {
			int m = v.size();
			vector<pair<int, int>> ord(m);
			for (int j = 0; j < m; ++j) ord[j] = {ind[v[j]], j};
			sort(ord.begin(), ord.end());

			for (int j = 0; j+1 < m; ++j) {
				int x = lca(v[ord[j].second], v[ord[j+1].second]);
				ord.emplace_back(ind[x], -(x+1));
			}
			sort(ord.begin(), ord.end());
			
			vector<int> act;
			for (int j = (int)ord.size() - 1; j >= 0; --j) {
				if (j+1 < ord.size() && ord[j+1].first == ord[j].first) continue;
				if (ord[j].second < 0) {
					if (j == 0) continue;
					v.push_back(-ord[j].second - 1);
					ord[j].second = (int)v.size() - 1;
				}
				act.push_back(ord[j].second);
			}
			reverse(act.begin(), act.end());

			vector<int> sta;
			vector<vector<pair<int, int>>> g(act.size());
			for (auto j : act) {
				while(sta.size() > 1 && subtree(v[sta.back()]).second < ind[v[j]]) sta.pop_back();
				if (! sta.empty()) {
					int i = sta.back();
					int d = dist(v[i], v[j]);
					g[i].emplace_back(j, d);
					g[j].emplace_back(i, d);
				}
				sta.push_back(j);
			}
			return g;
		}
};

int bins(const vector<int>& vec, int v) {
	int low = 0;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

void solve(const vector<pair<int, int>>& virus, const vector<int>& city, const vector<vector<pair<int, int>>>& g) {
	int n = g.size();
	vector<pair<pair<ll, int>, int>> sic(n, {{INF, -1}, 0});
	priority_queue<pair<pair<ll, int>, int>> que;

	for (int i = 0; i < virus.size(); ++i) {
		que.push({{0, -i}, virus[i].first});
		sic[virus[i].first] = {{0, i}, 0};
	}

	while(! que.empty()) {
		auto tmp = que.top();
		que.pop();

		int i = tmp.second;
		ll di = sic[i].first.first;
		int vi = sic[i].first.second;
		int sta = -sic[i].second;
		if (di != -tmp.first.first || vi != -tmp.first.second) continue;

		for (auto pr : g[i]) {
			int t = pr.first;
			int t_vi = vi;

			int t_sta = sta - pr.second;
			int rest = max(0, ((-t_sta) + (virus[vi].second - 1)) / (virus[vi].second));
			ll t_di = di + rest;
			t_sta += rest * virus[vi].second;

			pair<pair<ll, int>, int> off = {{t_di, t_vi}, -t_sta};
			if (off < sic[t]) {
				sic[t] = off;
				que.push({{-t_di, -t_vi}, t});
			}
		}
	}
	for (auto i : city) cout << sic[i].first.second + 1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	HLD hld(g);

	int q;
	cin >> q;
	for (; q; --q) {
		int k, m;
		cin >> k >> m;

		vector<int> imp(k + m);
		vector<pair<int, int>> virus(k);
		vector<int> city(m);

		for (int i = 0; i < k; ++i) {
			cin >> virus[i].first >> virus[i].second;
			--virus[i].first;
			imp[i] = virus[i].first;
		}
		for (int i = 0; i < m; ++i) {
			cin >> city[i];
			--city[i];
			imp[i+k] = city[i];
		}

		sort(imp.begin(), imp.end());
		imp.erase(unique(imp.begin(), imp.end()), imp.end());
		for (auto& pr : virus) pr.first = bins(imp, pr.first);
		for (auto& i : city) i = bins(imp, i);
		auto ind_g = hld.inducedTree(imp);

		/*
		cerr << "induced tree:\n";
		for (int i = 0; i < ind_g.size(); ++i) {
			cerr << imp[i] << ": ";
			for (auto t : ind_g[i]) cerr << imp[t.first] << ":" << t.second << ", ";
			cerr << '\n';
		}
		*/

		solve(virus, city, ind_g);
	}
}