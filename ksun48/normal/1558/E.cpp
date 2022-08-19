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

using ll = int64_t;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for(int i = 1; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		cin >> b[i];
	}
	vector<vector<int> > edges(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int s = -1;
	int e = int(1e9) + 1;
	while(s + 1 < e){
		int mid = (s + e) / 2;
		vector<int> vis(n, 0);
		vis[0] = 1;
		vector<int> par(n, -1);
		ll cpower = mid;
		while(true){
			par = vector<int>(n, -1);
			int found = -1;
			for(int st = 0; st < n; st++){
				if(!vis[st]) continue;
				for(int st2 : edges[st]){
					if(vis[st2]) continue;
					y_combinator(
						[&](auto self, int v, int p, ll power) -> void {
							// cerr << "dfs " << st << ' ' << st2 << ' ' << v << ' ' << p << ' ' << power << '\n';
							if(found >= 0) return;
							if(power <= a[v]) return;
							if(vis[v]){
								found = p;
							} else if(par[v] != -1){
								found = v;
							} else {
								power += b[v];
								par[v] = p;
								for(int w : edges[v]){
									if(w == p) continue;
									self(w, v, power);
								}
							}
						}
					)(st2, st, cpower);
				}
			}
			if(found == -1) break;
			cpower += b[found];
			vis[found] = 1;
			// cerr << mid << ' ' << "found " << found << '\n';
		}
		if(vis == vector<int>(n, 1)){
			e = mid;
		} else {
			s = mid;
		}
	}
	cout << e << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}