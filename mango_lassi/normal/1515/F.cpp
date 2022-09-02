#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU {
	private:
		vector<int> comp, siz;
	public:
		DSU(int n) : comp(n), siz(n, 1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
		}
		int getc(int i) {
			if (comp[i] != i) comp[i] = getc(comp[i]);
			return comp[i];
		}
		bool join(int a, int b) {
			a = getc(a);
			b = getc(b);
			if (a == b) return false;

			if (siz[a] < siz[b]) swap(a, b);
			siz[a] += siz[b];
			comp[b] = a;
			return true;
		}
		int compSize(int i) { return siz[getc(i)]; }
};

void dfs(int i, vector<pair<int, int>>& par, const vector<vector<pair<int, int>>>& g) {
	for (auto pr : g[i]) {
		if (pr == par[i]) continue;
		int t = pr.first;
		par[t] = {i, pr.second};
		dfs(t, par, g);
	}
}

int cascade(int i, vector<int>& comp) {
	if (comp[i] != i) comp[i] = cascade(comp[i], comp);
	return comp[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	ll x;
	cin >> n >> m >> x;
	
	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	
	// Necessary condition \sum a_i >= (n-1) * x
	// -> then, there is always some edge we can join over!
	// -> any greedy works!
	// -> can even operate on a tree!

	vector<vector<pair<int, int>>> g(n);
	{
		DSU dsu(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			if (dsu.join(a, b)) {
				g[a].emplace_back(b, i);
				g[b].emplace_back(a, i);
			}
		}

		ll sum = 0;
		for (ll& a : as) sum += a;

		if (dsu.compSize(0) != n || sum < x * (n-1)) {
			cout << "NO\n";
			return 0;
		}
	}
	
	// At every component in the tree, store the parent of the component, and the set of values of the children
	// -> after update, easy to check if a operation is possible on a child
	vector<pair<int, int>> par(n, {-1, -1});
	dfs(0, par, g);

	vector<int> comp(n);
	vector<set<pair<ll, int>>> offs(n);
	for (int i = 0; i < n; ++i) {
		comp[i] = i;
		int p = par[i].first;
		if (p != -1) {
			offs[p].emplace(as[i], i);
		}
	}

	priority_queue<pair<ll, int>> glob;
	for (int i = 0; i < n; ++i) {
		if (! offs[i].empty()) {
			auto it = offs[i].end();
			--it;
			auto off = (*it);
			off.first += as[i];
			off.second = i;
			glob.push(off);
		}
	}

	vector<int> res;
	while(! glob.empty()) {
		int i = cascade(glob.top().second, comp);
		glob.pop();

		if (offs[i].empty()) continue;
		auto it = offs[i].end();
		--it;
		auto pr = *it;
		if (pr.first + as[i] >= x) {
			int p = (par[i].first == -1 ? -1 : cascade(par[i].first, comp));
			if (p != -1) {
				offs[p].erase(make_pair(as[i], i));
			}

			offs[i].erase(it);

			int j = cascade(pr.second, comp);

			res.push_back(par[j].second);
			comp[j] = i;
			as[i] = as[i] + as[j] - x;
			as[j] = 0;
			

			if (offs[j].size() > offs[i].size()) swap(offs[j], offs[i]);
			for (auto pr : offs[j]) offs[i].insert(pr);
			offs[j].clear();
			
			if (p != -1) {
				offs[p].insert(make_pair(as[i], i));
				glob.emplace(as[i] + as[p], p);
			}

			if (! offs[i].empty()) {
				it = offs[i].end();
				--it;
				auto off = (*it);
				off.first += as[i];
				off.second = i;
				glob.push(off);
			}
		}
	}

	cout << "YES\n";
	for (int i : res) cout << i+1 << '\n';
}