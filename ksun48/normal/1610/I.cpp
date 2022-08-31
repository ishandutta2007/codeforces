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
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	if(n % 2 == 0){
		cout << string(n, '1') << '\n';
		return 0;
	}
	vector<int> up_time(n);
	vector<int> par(n);
	vector<int> val(n, 0);
	vector<int> min_id(n, n);
	y_combinator(
		[&](auto self, int v, int p) -> void {
			val[v] = 0;
			par[v] = p;
			min_id[v] = v;
			for(int w : edges[v]){
				if(w == p) continue;
				self(w, v);
				val[v] ^= (val[w] + 1);
				min_id[v] = min(min_id[v], min_id[w]);
			}
		}
	)(0, 0);
	vector<int> res(n+1, 0);
	for(int i = 1; i < n; i++){
		if(min_id[i] > min_id[par[i]]){
			int ival = val[i] + 1;
			res[min_id[par[i]]] ^= ival;
			res[min_id[i]] ^= ival;
		}
	}
	for(int i = 1; i < n; i++){
		res[i] ^= res[i-1];
	}
	for(int i = 0; i < n; i++){
		cout << "12"[res[i] < 2];
	}
	cout << '\n';
}