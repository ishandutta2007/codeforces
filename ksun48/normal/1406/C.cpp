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

void solve(){
	int n;
	cin >> n;
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<int> sz(n, 0);
	vector<int> par(n, 0);
	y_combinator(
		[&](auto self, int v, int p) -> void {
			sz[v] = 1;
			par[v] = p;
			for(int w : edges[v]){
				if(w == p) continue;
				self(w, v);
				sz[v] += sz[w];
			}
		}
	)(0, -1);
	int cc = -1;
	for(int i = 0; i < n; i++){
		if(n == 2 * sz[i]) cc = i;
	}
	if(cc == -1){
		cout << 0 + 1 << ' ' << edges[0][0] + 1 << '\n';
		cout << 0 + 1 << ' ' << edges[0][0] + 1 << '\n';
	} else {
		int w2 = -1;
		for(int w : edges[cc]){
			if(w == par[cc]) continue;
			w2 = w;
		}
		assert(w2 >= 0);
		cout << w2 + 1 << ' ' << cc + 1 << '\n';
		cout << w2 + 1 << ' ' << par[cc] + 1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}