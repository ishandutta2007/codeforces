#include <bits/stdc++.h>
const int MN = 1e5+100;
#define F first
#define S second
using namespace std;
int uf[MN];
int sz[MN];
int find(int a) {
	if(uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}
void merge(int a, int b) {
	if(sz[find(a)] > sz[find(b)]) swap(a, b);
	sz[find(b)] += sz[find(a)];
	//merges a into b
	uf[find(a)] = find(b);
}
vector<int> mst(auto v) {
	for(int i = 0; i < MN; ++i) uf[i] = i;
	for(int i = 0; i < MN; ++i) sz[i] = 1;
	vector<int> ans;
	for(int i = 0; i < v.size(); ++i) {
		int a = v[i].S.F;
		int b = v[i].S.S;
		if(find(a) != find(b)) {
			merge(a, b);
		}
		else {
			ans.push_back(i);
		}
	}
	return ans;
}
void mst2(auto v, auto & edge_b_search) {
	for(int i = 0; i < MN; ++i) uf[i] = i;
	for(int i = 0; i < MN; ++i) sz[i] = 1;
	for(int i = 0; i < edge_b_search.size(); ++i) {
		get<0>(edge_b_search[i]) = (get<1>(edge_b_search[i]) + get<2>(edge_b_search[i]))/2;
	}
	sort(edge_b_search.begin(), edge_b_search.end());
	int edge_pos = 0;
	for(int i = 0; i < v.size(); ++i) {
		int a = v[i].S.F;
		int b = v[i].S.S;
		if(find(a) != find(b)) {
			while(edge_pos < edge_b_search.size() && get<0>(edge_b_search[edge_pos]) <= v[i].F.F) {
				int edge_index = get<3>(edge_b_search[edge_pos]);
				if(get<1>(edge_b_search[edge_pos]) <= get<2>(edge_b_search[edge_pos])) {
					if(find(v[edge_index].S.F) != find(v[edge_index].S.S)) {
						get<4>(edge_b_search[edge_pos]) = get<0>(edge_b_search[edge_pos]);
						get<1>(edge_b_search[edge_pos]) = get<0>(edge_b_search[edge_pos])+1;
					}
					else {
						get<2>(edge_b_search[edge_pos]) = get<0>(edge_b_search[edge_pos])-1;
					}
				}
				++edge_pos;
 
			}
			merge(a, b);
		}
	}
	while(edge_pos < edge_b_search.size() && get<0>(edge_b_search[edge_pos]) <= 1e9) {
		int edge_index = get<3>(edge_b_search[edge_pos]);
		if(get<1>(edge_b_search[edge_pos]) <= get<2>(edge_b_search[edge_pos])) {
			if(find(v[edge_index].S.F) != find(v[edge_index].S.S)) {
				get<4>(edge_b_search[edge_pos]) = get<0>(edge_b_search[edge_pos]);
				get<1>(edge_b_search[edge_pos]) = get<0>(edge_b_search[edge_pos])+1;
			}
			else {
				get<2>(edge_b_search[edge_pos]) = get<0>(edge_b_search[edge_pos])-1;
			}
		}
		++edge_pos;
	}
}
int main() {
	vector<pair<pair<int, int>, pair<int, int> > > v;
	int n,m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i < m; ++i) {
		int a, b, e;
		cin>>a>>b>>e;
		v.push_back({{e, i}, {a, b}});
	}
	sort(v.begin(), v.end());
	vector<int> non_mst_edges = mst(v);
	//mid, lo, hi, index
	vector<tuple<int, int, int, int, int> > edge_b_search;
	sort(non_mst_edges.begin(), non_mst_edges.end());
	for(int i = 0; i < non_mst_edges.size(); ++i) {
		//cout<<non_mst_edges[i]<<endl;
		edge_b_search.push_back(make_tuple(0, 0, 1e9, non_mst_edges[i], 0));
	}
	for(int i = 0; i < 32; ++i) {
		mst2(v, edge_b_search);
	}
	vector<pair<int, int> > ans;
	for(int i = 0; i < edge_b_search.size(); ++i) {
		int edge_index = get<3>(edge_b_search[i]);
		int original_index = v[edge_index].F.S;
		ans.push_back({original_index, get<4>(edge_b_search[i])});
	}
	sort(ans.begin(), ans.end());
	for(auto x: ans) cout<<x.S<<'\n';
 
}