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
	vector<vector<int> > edges;
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<vector<pair<int,int> > > new_edges(n);
	y_combinator([&](auto self, int v, int p, int d) -> void {
		int nc = 0;
		for(int w : edges[v]){
			if(w == p) continue;
			nc++;
		}
		int id = 0;
		if(nc < d) id = d - nc;
		for(int w : edges[v]){
			if(w == p) continue;
			if(id == d) id++;
			new_edges[v].push_back({w, id});
			new_edges[w].push_back({v, id});
			self(w, v, id);
			id++;
		}
	})(0, -1, -1);
	new_edges[0].push_back({-1, -1});
	for(int i = 0; i < n; i++){
		sort(new_edges[i].begin(), new_edges[i].end(), [&](pair<int,int> a, pair<int,int> b){
			return a.second < b.second;
		});
	}
	vector<pair<int,int> > times;
	y_combinator([&](auto self, int v, int d) -> void {
		int k = (int)new_edges[v].size();
		int z = 0;
		while(z < k && new_edges[v][z].second < d) z++;
		int ct = d;
		for(int q = 0; q < k; q++){
			z++;
			ct++;
			times.push_back({v, ct});
			if(z == k){
				z -= k;
				ct -= k;
				times.push_back({v, ct});
			}
			if(q < k-1) self(new_edges[v][z].first, ct);
		}
	})(0, -1);
	times.pop_back();
	cout << times.size() << '\n';
	for(pair<int,int> q : times){
		cout << q.first + 1 << ' ' << q.second << '\n';
	}
}