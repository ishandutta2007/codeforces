#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
	int n, m;
	ll X;
	cin >> n >> m >> X;
	vector<ll> val(n);
	for(ll& b : val) cin >> b;
	ll thave = 0;
	for(ll b : val) thave += b;
	if(thave < X * (n-1)){
		cout << "NO" << '\n';
		return 0;
	}
	vector<vector<pair<int,int> > > edges(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back({v, i});
		edges[v].push_back({u, i});
	}
	vector<int> vis(n, 0);
	vector<int> par(n, -1);
	vector<int> par_id(n, -1);
	vector<vector<int> > ch(n);
	y_combinator(
		[&](auto self, int v) -> void {
			vis[v] = 1;
			for(auto [w, id] : edges[v]){
				if(!vis[w]){
					par[w] = v;
					ch[v].push_back(w);
					par_id[w] = id;
					self(w);
				}
			}
		}
	)(0);

	vector<int> uf_par(n);
	for(int i = 0; i < n; i++) uf_par[i] = i;
	auto find_root = y_combinator(
		[&](auto self, int a) -> int {
	        if(a != uf_par[a]) uf_par[a] = self(uf_par[a]);
	        return uf_par[a];
	    }
	);
	// b above a

	vector<int> sequence;
	vector<int> check;
	for(int i = 0; i < n; i++){
		check.push_back(i);
	}
	int s = 0;
	while(s < (int)check.size()){
		int v = check[s];
		s++;
		v = find_root(v);
		if(v == 0) continue;
		if(val[v] >= X){
			int p = find_root(par[v]);
			if(p == v) continue;
			sequence.push_back(par_id[v]);
			val[p] += val[v] - X;
			val[v] = 0;
			check.push_back(p);
			uf_par[v] = p;
		}
	}
	y_combinator(
		[&](auto self, int v) -> void {
			if(par[v] >= 0 && find_root(v) != 0){
				val[0] += val[v] - X;
				sequence.push_back(par_id[v]);
				assert(val[0] >= 0);
				uf_par[v] = 0;
			}
			for(int w : ch[v]){
				self(w);
			}
		}
	)(0);

	cout << "YES" << '\n';
	for(int a : sequence){
		cout << (a+1) << '\n';
	}
}