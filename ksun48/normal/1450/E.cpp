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
	int n, m;
	cin >> n >> m;
	vector<int> u(m), v(m), b(m);
	vector<vector<int> > edges(n);
	for(int i = 0; i < m; i++){
		cin >> u[i] >> v[i] >> b[i];
		u[i]--; v[i]--;
		edges[u[i]].push_back(v[i]);
		edges[v[i]].push_back(u[i]);
	}
	// bipartite?
	vector<int> color(n, 0);
	bool bip = true;
	y_combinator(
		[&](auto self, int x, int c){
			if(color[x] == c) return;
			if(color[x] == -c){
				bip = false;
				return;
			}
			color[x] = c;
			for(int w : edges[x]){
				self(w, -c);
			}
		}
	)(0, 1);
	if(!bip){
		cout << "NO" << '\n';
		return 0;
	}

	auto set_min = [&](int& x, int y) -> bool {
		if(y < x){
			x = y;
			return 1;
		}
		return 0;
	};
	int best_diff = -1;
	vector<int> best_income;
	for(int st = 0; st < n; st++){
		vector<int> bound(n, 1e9);
		bound[st] = 0;
		bool fail = false;
		for(int j = 0; j <= n+1; j++){
			bool did = false;
			for(int i = 0; i < m; i++){
				did |= set_min(bound[u[i]], bound[v[i]] + 1);
				did |= set_min(bound[v[i]], bound[u[i]] + 1);
				if(b[i]) did |= set_min(bound[u[i]], bound[v[i]] - 1);
			}
			if(j == n+1 && did) fail = true;
		}
		if(!fail){
			int cmax = -1e9;
			for(int r : bound) if(r > cmax) cmax = r;
			if(cmax > best_diff){
				best_diff = cmax;
				best_income = bound;
			}
		}
	}
	if(best_diff >= 0){
		cout << "YES" << '\n';
		cout << best_diff << '\n';
		for(int a : best_income) cout << a << ' ';
		cout << '\n';
	} else {
		cout << "NO" << '\n';
	}
}