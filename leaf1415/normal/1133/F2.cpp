#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> P;

struct UnionFind{
	int size;
	vector<int> parent;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};

int n, m, d;
vector<int> G[200005];
UnionFind uf(200005), uf2(200005);
P E[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> d;
	int u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		E[i] = make_pair(u, v);
	}
	if(d > G[1].size()){
		cout << "NO" << endl;
		return 0;
	}
	
	int num = n;
	for(int i = 1; i <= m; i++){
		if(E[i].first == 1 || E[i].second == 1) continue;
		if(uf.same(E[i].first, E[i].second)) continue;
		uf.unite(E[i].first, E[i].second);
		num--;
	}
	if(d < num-1){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	for(int i = 0; i < G[1].size(); i++){
		if(uf.same(1, G[1][i])) continue;
		cout << 1 << " " << G[1][i] << endl;
		uf.unite(1, G[1][i]);
		uf2.unite(1, G[1][i]);
		d--;
	}
	
	for(int i = 0; i < G[1].size(); i++){
		if(d == 0) break;
		if(uf2.same(1, G[1][i])) continue;
		cout << 1 << " " << G[1][i] << endl;
		uf2.unite(1, G[1][i]);
		d--;
	}
	
	for(int i = 1; i <= m; i++){
		int u = E[i].first, v = E[i].second;
		if(u == 1 || v == 1) continue;
		if(uf2.same(u, v)) continue;
		cout << u << " " << v << endl;
		uf2.unite(u, v);
	}
	
	return 0;
}