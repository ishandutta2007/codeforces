#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define llint long long

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

llint Q;
llint n;
llint p[200005];
map<llint, llint> mp;
UnionFind uf;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i];
		
		uf = UnionFind(n);
		mp.clear();
		for(int i = 1; i <= n; i++) uf.unite(i, p[i]);
		for(int i = 1; i <= n; i++) mp[uf.root(i)]++;
		for(int i = 1; i <= n; i++) cout << mp[uf.root(i)] << " ";
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}