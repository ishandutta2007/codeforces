/*
this works if an edge is not always part of the minimum spanning tree.
therefore we can now concentrate on edges that are always part of the minimum spanning tree.

what about edges that can be part of the minimum spanning tree but are not necessarily so?
with the E2 solution we get a lower bound for the answer
if the E3 solution find a better solution, we can just choose that 

so the answer is max(E2, E3)

*/
#include <bits/stdc++.h>
const int MN = 1e5+100;
#define F first
#define S second
using namespace std;
int uf[MN];
int sz[MN];
int ans2[(int)1e6+100];
vector<pair<int, int> >  edges[MN];
vector<pair<int, int> > mst_v[MN];

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
bool used[MN];
bool depth[MN];
vector<int> parents;
int new_ids[MN];
int new_to_old[MN];
int id = 0;
void make_mst(int x) {
	used[x] = 1;
	new_to_old[id] = x;
	new_ids[x] = id++;
	vector<pair<int, int> > new_edges;
	for(auto y: mst_v[x]) {
		if(!used[y.F]) {
			make_mst(y.F);
			parents[new_ids[y.F]] = new_ids[x];
			new_edges.push_back(y);
		}
	}
	mst_v[x] = new_edges;
};
struct HLD {
	vector<int> par; // Parent
	vector<int> pp; // Path parent
	vector<int> ind; // HLD index

	// p: parent of node i. Must have p[i] < i (p[0] = -1).
	HLD(const vector<int>& p) : par(p), pp(p.size()), ind(p.size(), -1) {
		int n = p.size();
		vector<int> siz(n, 1); // subtree size
		for (int i = n-1; i > 0; --i) siz[par[i]] += siz[i];

		vector<int> pc(n, -1); // Preferred child
		for (int i = n-1; i > 0; --i) {
			if (2*siz[i] >= siz[par[i]]) pc[par[i]] = i;
		}

		int cur = 0; // Current position in array
		for (int i = 0; i < n; ++i) {
			if (ind[i] != -1) continue;
			for (int j = i; j != -1; j = pc[j], ++cur) {
				ind[j] = cur;
				pp[j] = i;
			}
		}
	}
	// Get intervals corresponding to path between a and b
	vector<pair<int, int>> get(int a, int b) {
		vector<pair<int, int>> res;
		while(true) {
			if (ind[b] < ind[a]) swap(a, b);
			if (ind[pp[b]] <= ind[a]) {
				res.push_back({ind[a], ind[b]});
				return res;
			} else {
				res.push_back({ind[pp[b]], ind[b]});
				b = par[pp[b]];
			}
		}
	}
	// Get LCA of a and b
	int lca(int a, int b) const {
		while(true) {
			if (ind[b] < ind[a]) swap(a, b);
			if (ind[pp[b]] <= ind[a]) return a;
			else b = par[pp[b]];
		}
	}
};

vector<pair<int, int> > lcas[MN];


//value, index
set<pair<int, int> > f(int x) {
	vector<set<pair<int, int> > > sets;
	for(auto y: mst_v[x]) {
		//could be too slow
		sets.push_back(f(y.F));
		if(sets.back().size()) {
			ans2[y.S] = sets.back().begin()->F;
		}
		else {
			ans2[y.S] = 1e9;
		}
	}
	pair<int, int> ma = {0, 0};
	for(int i = 0; i < sets.size(); ++i) {
		if(sets[i].size() > ma.F) {
			ma = {(int)sets[i].size(), i};
		}
	}
	set<pair<int, int> > new_set;
	if(sets.size() == 0) {
	}
	else if(sets.size() == 1) {
		swap(new_set, sets[0]);
	}
	else {
		swap(new_set, sets[ma.S]);
		for(int i = 0; i < sets.size(); ++i) {
			if(i != ma.S) {
				for(auto x: sets[i]) {
					new_set.insert(x);
				}
			}
		}
	}
	for(auto x: edges[x]) {
		new_set.insert(x);
	}

	for(auto x: lcas[x]) {
		new_set.erase(x);
	}
	return new_set;

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
	/*E3 solution*/
	vector<int> mst_edges = mst(v);
	set<pair<int, int> > mst_edges_set;
	for(int i = 0; i < mst_edges.size(); ++i) {
		int a = v[mst_edges[i]].S.F;
		int b = v[mst_edges[i]].S.S;
		mst_edges_set.insert({a, b});
		mst_v[a].push_back({b, v[mst_edges[i]].F.S});
		mst_v[b].push_back({a, v[mst_edges[i]].F.S});
	}
	parents.resize(n);
	make_mst(1);
	parents[0] = -1;
	HLD hld(parents);

	for(int i = 0; i < m; ++i) {
		if(!mst_edges_set.count(v[i].S) && !mst_edges_set.count({v[i].S.S, v[i].S.F})) {
			int a = v[i].S.F;
			int b = v[i].S.S;
			edges[a].push_back(v[i].F);
			edges[b].push_back(v[i].F);
			int l = new_to_old[hld.lca(new_ids[a], new_ids[b])];
			lcas[l].push_back(v[i].F);
		}
	}
	f(1);





	/*E2 solution*/

	//mid, lo, hi, index
	vector<tuple<int, int, int, int, int> > edge_b_search;
	for(int i = 0; i < m; ++i) {
		//cout<<non_mst_edges[i]<<endl;
		edge_b_search.push_back(make_tuple(0, 0, 1e9, i, 0));
	}
	for(int i = 0; i < 32; ++i) {
		mst2(v, edge_b_search);
	}
	vector<pair<int, int> > ans;
	for(int i = 0; i < edge_b_search.size(); ++i) {
		int edge_index = get<3>(edge_b_search[i]);
		int original_index = v[edge_index].F.S;
		ans2[original_index] = max(ans2[original_index], get<4>(edge_b_search[i]));
	}
	for(int i = 0; i < m; ++i) {
		cout<<ans2[i]<<'\n';
	}
}