#include <iostream>
#include <algorithm>
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

llint n, m;
UnionFind uf(1000005);
llint cnt[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int k, x;
	for(int i = 1; i <= m; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> x;
			uf.unite(x, n+i);
		}
	}
	
	for(int i = 1; i <= n; i++) cnt[uf.root(i)]++;
	for(int i = 1; i <= n; i++){
		cout << cnt[uf.root(i)] << " ";
	}
	cout << endl;
	
	return 0;
}