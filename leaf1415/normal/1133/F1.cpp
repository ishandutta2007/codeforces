#include <iostream>
#include <vector>

using namespace std;

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

int n, m;
vector<int> G[200005];
UnionFind uf(200005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int mx = 0, mx_i;
	for(int i = 1; i <= n; i++){
		if(G[i].size() > mx){
			mx = G[i].size();
			mx_i = i;
		}
	}
	
	for(int i = 0; i < G[mx_i].size(); i++){
		cout << mx_i << " " << G[mx_i][i] << endl;
		uf.unite(mx_i, G[mx_i][i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			if(uf.same(i, G[i][j])) continue;
			cout << i << " " << G[i][j] << endl;
			uf.unite(i, G[i][j]);
		}
	}
	
	return 0;
}