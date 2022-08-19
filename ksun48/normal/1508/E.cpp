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
	vector<int> a(n);
	for(int& x : a){
		cin >> x;
		x--;
	}
	vector<int> par(n, -1);
	vector<vector<int> > ch(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		assert(v != 0);
		par[v] = u;
		ch[u].push_back(v);
	}
	vector<int> depth(n);
	y_combinator([&](auto self, int v, int d) -> void {
		depth[v] = d;
		for(int w : ch[v]) self(w, d+1);
	})(0, 0);
	vector<int> loc(n);
	for(int i = 0; i < n; i++) loc[a[i]] = i;
	vector<int> deg(n, 0);
	for(int i = 1; i < n; i++) deg[par[i]]++;
	int nonleaf = n;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		int x = loc[i];
		ans += depth[x];
		if(deg[x] == 0){
			if(par[x] >= 0){
				deg[par[x]]--;
			}
		} else {
			nonleaf = i;
			break;
		}
	}
	if(nonleaf < n){
		int v = loc[nonleaf];
		while(v > 0){
			swap(a[v], a[par[v]]);
			v = par[v];
		}
	}
	vector<int> real_ord;
	vector<int> post_ord;
	vector<int> excl;
	y_combinator([&](auto self, int v) -> void {
		if(a[v] >= nonleaf) excl.push_back(v);
		real_ord.push_back(v);
		vector<int> c = ch[v];
		sort(c.begin(), c.end(), [&](int x, int y){
			return a[x] < a[y];
		});
		for(int w : c) self(w);
		post_ord.push_back(v);
	})(0);
	vector<int> sorted_excl = excl;
	sort(sorted_excl.begin(), sorted_excl.end(), [&](int x, int y){
		return a[x] < a[y];
	});
	if(sorted_excl != excl){
		cout << "NO" << '\n';
		exit(0);
	}
	for(int j = 0; j < nonleaf; j++){
		if(post_ord[j] != loc[j]){
			cout << "NO" << '\n';
			exit(0);
		}
	}
	if(nonleaf < n){
		int x = loc[nonleaf];
		int y = post_ord[nonleaf];
		bool found = false;
		while(y >= 0){
			if(y == x) found = true;
			y = par[y];
		}
		if(!found){
			cout << "NO" << '\n';
			exit(0);
		}
	}
	cout << "YES" << '\n';
	cout << ans << '\n';
	vector<int> real_idx(n);
	for(int i = 0; i < n; i++) real_idx[real_ord[i]] = i;
	for(int x : real_idx){
		cout << (x+1) << ' ';
	}
	cout << '\n';
}