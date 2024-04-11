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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> h(n);
	for(int& x : h) cin >> x;
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<int> hord(n);
	for(int i = 0; i < n; i++) hord[i] = i;
	sort(hord.begin(), hord.end(), [&](int x, int y) { return h[x] > h[y]; });
	int root = hord[0];

	vector<int> par(n);
	y_combinator(
		[&](auto self, int v, int p) -> void {
			par[v] = p;
			for(int w : edges[v]){
				if(w == p) continue;
				self(w, v);
			}
		}
	)(root, -1);


	using ll = int64_t;

	vector<int> seen(n, 0);
	vector<int> deg(n, 0);

	int nleaves = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int v = hord[i];
		int nexth = (i == n-1) ? 0 : h[hord[i+1]];
		int diff = h[v] - nexth;
		if(v == root){
			seen[v] = 1;
		} else {
			while(!seen[v]){
				int p = par[v];
				if(deg[p] == 1) nleaves--;
				if(deg[v] == 1) nleaves--;
				deg[p]++;
				deg[v]++;
				if(deg[p] == 1) nleaves++;
				if(deg[v] == 1) nleaves++;
				seen[v] = 1;
				v = p;
			}
		}
		int leaves = nleaves;
		ans += ll(diff) * ll(max(leaves, 2));
	}
	cout << ans << '\n';
}