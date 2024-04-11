#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int> > edges(m);
	vector<set<int> > edge_exists(n);
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edges[i] = {a, b, c};
		edge_exists[a].insert(b);
		edge_exists[b].insert(a);
	}
	vector<tuple<int, int, int> > orig_edges = edges;
	sort(edges.begin(), edges.end(), [&](tuple<int, int, int> x, tuple<int, int, int> y){
		return get<2>(x) < get<2>(y);
	});
	vector<vector<int> > ccs_real_edges(n);
	vector<int> par_real_edges(n);
	vector<set<int> > ccs_contained(n);
	vector<vector<int> > ccs_complement(n);
	vector<int> par_complement(n);
	for(int i = 0; i < n; i++){
		ccs_real_edges[i] = ccs_complement[i] = {i};
		ccs_contained[i].insert(i);
		par_real_edges[i] = par_complement[i] = i;
	}
	auto merge_small = [&](int a, int b) -> bool {
		a = par_complement[a];
		b = par_complement[b];
		if(a == b) return false;
		if(ccs_complement[a].size() > ccs_complement[b].size()) swap(a, b);
		for(int x : ccs_complement[a]) par_complement[x] = b;
		for(int x : ccs_complement[a]) ccs_complement[b].push_back(x);
		ccs_complement[a] = {};
		assert(par_real_edges[a] == par_real_edges[b]);
		ccs_contained[par_real_edges[b]].erase(a);
		assert(ccs_contained[par_real_edges[b]].count(b));
		return true;
	};
	auto merge_real = [&](int a, int b) -> void {
		if(ccs_real_edges[a].size() > ccs_real_edges[b].size()) swap(a, b);
		for(int x : ccs_real_edges[a]) par_real_edges[x] = b;
		for(int x : ccs_real_edges[a]) ccs_real_edges[b].push_back(x);
		ccs_real_edges[a] = {};
		for(int x : ccs_contained[a]){
			ccs_contained[b].insert(x);
		}
		ccs_contained[a] = {};
	};
	vector<tuple<int, int, int> > mst_complement;
	for(auto [a, b, c] : edges){
		a = par_real_edges[a];
		b = par_real_edges[b];
		if(a == b) continue;
		if(ccs_real_edges[a].size() > ccs_real_edges[b].size()) swap(a, b);
		vector<int> a_verts = ccs_real_edges[a];
		vector<tuple<int, int, int> > ab_edges;
		for(int v : a_verts){
			set<int> b_cc_processed;
			for(int y : ccs_contained[b]){
				for(int v2 : ccs_complement[y]){
					if(edge_exists[v].count(v2)) continue;
					b_cc_processed.insert(y);
					break;
				}
			}
			if(!b_cc_processed.empty()){
				int cc1 = *b_cc_processed.begin();
				b_cc_processed.erase(cc1);
				ab_edges.push_back({v, cc1, c});
				for(int cc2 : b_cc_processed){
					if(merge_small(cc1, cc2)){
						mst_complement.push_back({cc1, cc2, c});
					}
				}
			}
		}
		merge_real(a, b);
		for(auto [r, s, t] : ab_edges){
			if(merge_small(r, s)){
				mst_complement.push_back({r, s, t});
			}
		}
	}
	vector<int> ans(m, 2e9);
	vector<set<int> > which_edges(n);
	for(int i = 0; i < m; i++){
		auto [a, b, c] = orig_edges[i];
		which_edges[a].insert(i);
		which_edges[b].insert(i);
	}
	for(int i = 0; i < n; i++){
		ccs_real_edges[i] = ccs_complement[i] = {i};
		ccs_contained[i].insert(i);
		par_real_edges[i] = par_complement[i] = i;
	}
	auto merge_small2 = [&](int a, int b) -> bool {
		a = par_complement[a];
		b = par_complement[b];
		if(a == b) return false;
		if(ccs_complement[a].size() > ccs_complement[b].size()) swap(a, b);
		for(int x : ccs_complement[a]) par_complement[x] = b;
		for(int x : ccs_complement[a]) ccs_complement[b].push_back(x);
		ccs_complement[a] = {};
		return true;
	};
	for(auto [a, b, c] : mst_complement){
		a = par_complement[a];
		b = par_complement[b];
		assert(a != b);
		if(ccs_complement[a].size() > ccs_complement[b].size()) swap(a, b);
		for(int x : ccs_complement[a]){
			for(int i : which_edges[x]){
				auto [u, v, cc] = orig_edges[i];
				if((par_complement[u] == a && par_complement[v] == b) || (par_complement[u] == b && par_complement[v] == a)){
					ans[i] = min(ans[i], c);
				}
			}
		}
		assert(merge_small2(a, b));
	}
	for(int i = 0; i < m; i++){
		cout << ans[i] << " \n"[i == m-1];
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}