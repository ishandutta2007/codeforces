#include <bits/stdc++.h>
using namespace std;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

namespace ecnerwala {

using std::swap;

struct level_ancestor {
	int N;
	std::vector<int> preorder;
	std::vector<int> idx;
	std::vector<std::pair<int, int>> heavyPar; // heavy parent, distance
	level_ancestor() : N(0) {}

	level_ancestor(const std::vector<int>& par) : N(int(par.size())), preorder(N), idx(N), heavyPar(N) {
		std::vector<std::vector<int>> ch(N);
		for (int i = 0; i < N; i++) {
			if (par[i] != -1) ch[par[i]].push_back(i);
		}
		std::vector<int> sz(N);
		int nxt_idx = 0;
		for (int i = 0; i < N; i++) {
			if (par[i] == -1) {
				std::y_combinator([&](auto self, int cur) -> void {
					sz[cur] = 1;
					for (int nxt : ch[cur]) {
						self(nxt);
						sz[cur] += sz[nxt];
					}
					if (!ch[cur].empty()) {
						auto mit = max_element(ch[cur].begin(), ch[cur].end(), [&](int a, int b) { return sz[a] < sz[b]; });
						swap(*ch[cur].begin(), *mit);
					}
				})(i);
				std::y_combinator([&](auto self, int cur, int isRoot = true) -> void {
					preorder[idx[cur] = nxt_idx++] = cur;
					if (isRoot) {
						heavyPar[idx[cur]] = {par[cur] == -1 ? -1 : idx[par[cur]], 1};
					} else {
						assert(idx[par[cur]] == idx[cur]-1);
						heavyPar[idx[cur]] = heavyPar[idx[cur]-1];
						heavyPar[idx[cur]].second++;
					}
					bool chRoot = false;
					for (int nxt : ch[cur]) {
						self(nxt, chRoot);
						chRoot = true;
					}
				})(i);
			}
		}
	}

	int get_ancestor(int a, int k) const {
		assert(k >= 0);
		a = idx[a];
		while (a != -1 && k) {
			if (k >= heavyPar[a].second) {
				k -= heavyPar[a].second;
				assert(heavyPar[a].first <= a - heavyPar[a].second);
				a = heavyPar[a].first;
			} else {
				a -= k;
				k = 0;
			}
		}
		if (a == -1) return -1;
		else return preorder[a];
	}

	int lca(int a, int b) const {
		a = idx[a], b = idx[b];
		while (true) {
			if (a > b) swap(a, b);
			assert(a <= b);
			if (a > b - heavyPar[b].second) {
				return preorder[a];
			}
			b = heavyPar[b].first;
			if (b == -1) return -1;
		}
	}

	int dist(int a, int b) const {
		a = idx[a], b = idx[b];
		int res = 0;
		while (true) {
			if (a > b) swap(a, b);
			assert(a <= b);
			if (a > b - heavyPar[b].second) {
				res += b - a;
				break;
			}
			res += heavyPar[b].second;
			b = heavyPar[b].first;
			if (b == -1) return -1;
		}
		return res;
	}
};

} // namespace ecnerwala

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > edges(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<int> par(n, -1);
	vector<int> vis(n, 0);
	int root = 0;
	vector<int> e;
	y_combinator(
		[&](auto self, int v, int p) -> void {
			par[v] = p;
			vis[v] = 1;
			for(int w : edges[v]){
				if(vis[w]) continue;
				e.push_back(w);
				self(w, v);
			}
		}
	)(root, -1);
	ecnerwala::level_ancestor la(par);
	int nbad = 0;
	vector<int> upd(n, 0);
	vector<int> upd2(n, 0);
	for(int u = 0; u < n; u++){
		for(int v : edges[u]){
			int clen = la.dist(u, v) + 1;
			if(clen & 1){
				nbad++;
				upd[u]++;
				upd[v]++;
				upd[la.lca(u, v)] -= 2;
			} else if(clen > 2){
				upd2[u]++;
				upd2[v]++;
				upd2[la.lca(u, v)] -= 2;
			}
		}
	}
	reverse(e.begin(), e.end());
	for(int v : e){
		upd[par[v]] += upd[v];
		upd2[par[v]] += upd2[v];
	}
	int bu = -1, bv = -1;
	if(nbad == 0){
		bu = 0;
		bv = 0;
	} else if(nbad == 2){
		for(int u = 0; u < n; u++){
			for(int v : edges[u]){
				int parity = la.dist(u, v) + 1;
				if(parity & 1){
					bu = u;
					bv = v;
				}
			}
		}
	} else {
		for(int x = 0; x < n; x++){
			if(upd[x] == nbad && upd2[x] == 0){
				bu = x;
				bv = par[x];
			}
		}
	}
	if(bu == -1){
		cout << "NO" << '\n';
		return;
	}
	vector<int> color(n, -1);
	vis = vector<int>(n, 0);
	y_combinator([&](auto self, int v, int c) -> void {
		color[v] = c;
		vis[v] = 1;
		for(int w : edges[v]){
			if(v == bu && w == bv) continue;
			if(v == bv && w == bu) continue;
			if(vis[w]) continue;
			self(w, c ^ 1);
		}
	})(bu, 1);
	cout << "YES" << '\n';
	for(int i = 0; i < n; i++) cout << color[i];
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}