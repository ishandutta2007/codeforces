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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(n);
	for(int& x : c){
		cin >> x;
		x--;
	}
	vector<vector<pair<int,int> > > each_edges(k);
	map<pair<int,int>, vector<pair<int,int> > > color_edges;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		int cu = c[u];
		int cv = c[v];
		if(cu > cv){
			swap(cu, cv);
			swap(u, v);
		}
		if(cu == cv){
			each_edges[cu].push_back({u, v});
		} else {
			color_edges[{cu, cv}].push_back({u, v});
		}
	}
	vector<vector<int> > color_verts(k);
	for(int i = 0; i < n; i++){
		color_verts[c[i]].push_back(i);
	}
	vector<bool> fail(k, false);
	vector<int> par(n);
	vector<int> offset(n);
	for(int i = 0; i < n; i++){
		par[i] = i;
		offset[i] = 0;
	}
	for(int col = 0; col < k; col++){
		map<int, vector<int> > edges;
		for(pair<int,int> e : each_edges[col]){
			edges[e.first].push_back(e.second);
			edges[e.second].push_back(e.first);
		}
		for(int st : color_verts[col]){
			if(offset[st]) continue;
			y_combinator(
				[&](auto self, int v, int val) -> void {
					if(offset[v] == -val) fail[col] = true;
					if(offset[v]) return;
					par[v] = st;
					offset[v] = val;
					for(int w : edges[v]){
						self(w, -val);
					}
				}
			)(st, 1);
		}
	}
	using ll = long long;
	ll tot = 1ll * k * (k-1) / 2;
	int good_groups = k;
	for(int i = 0; i < k; i++){
		if(fail[i]){
			good_groups -= 1;
			tot -= good_groups;
		}
	}

	vector<int> tmp(n);
	for(auto edge_set : color_edges){
		pair<int,int> groups = edge_set.first;
		if(fail[groups.first] || fail[groups.second]) continue;

		map<int, vector<pair<int,int> > > edges;
		for(pair<int,int> e : edge_set.second){
			int val = -offset[e.first] * offset[e.second];
			edges[par[e.first]].push_back({par[e.second], val});
			edges[par[e.second]].push_back({par[e.first], val});
		}

		bool works = true;
		for(auto g : edges){
			int st = g.first;
			if(tmp[st]) continue;
			y_combinator(
				[&](auto self, int v, int val) -> void {
					if(tmp[v] == -val) works = false;
					if(tmp[v]) return;
					tmp[v] = val;
					for(auto e : edges[v]){
						self(e.first, val * e.second);
					}
				}
			)(st, 1);
		}

		for(auto g : edges){
			int st = g.first;
			tmp[st] = 0;
		}
		if(!works) tot -= 1;
	}
	cout << tot << '\n';
}