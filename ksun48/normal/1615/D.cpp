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

struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};


void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int> > > edges(n);
	UF uf(2*n);
	for(int i = 0; i < n-1; i++){
		int x, y, v;
		cin >> x >> y >> v;
		x--; y--;
		edges[x].push_back({y, v});
		edges[y].push_back({x, v});
		if(v >= 0){
			int d = __builtin_popcount(v) & 1;
			uf.join(2*x, 2*y + d);
			uf.join(2*x + 1, 2*y + (d^1));
		}
	}
	for(int i = 0; i < m; i++){
		int x, y, d;
		cin >> x >> y >> d;
		x--; y--;
		uf.join(2*x, 2*y + d);
		uf.join(2*x + 1, 2*y + (d^1));
	}
	for(int i = 0; i < n; i++){
		if(uf.find(2*i) == uf.find(2*i+1)){
			cout << "NO" << '\n';
			return;
		}
	}
	vector<int> side(n);
	for(int i = 0; i < n; i++){
		side[i] = uf.find(2*i) < uf.find(2*i+1);
	}
	cout << "YES" << '\n';
	y_combinator(
		[&](auto self, int v, int p) -> void {
			for(auto [w, wgt] : edges[v]){
				if(w == p) continue;
				if(wgt == -1) wgt = side[v] ^ side[w];
				cout << (v+1) << ' ' << (w+1) << ' ' << wgt << '\n';
				self(w, v);
			}
		}
	)(0, -1);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}