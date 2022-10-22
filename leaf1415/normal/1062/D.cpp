#include <iostream>
#include <vector>
#include <map>
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

int n;
UnionFind uf(100005);
map<int, llint> mp;

int main(void)
{
	cin >> n;
	if(n <= 3){
		cout << 0 << endl;
		return 0;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 2*i; j <= n; j+=i) uf.unite(i, j);
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2*i; j <= n; j+=i){
			mp[uf.root(i)] += j/i;
		}
	}
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		ans = max(ans, it->second);
	}
	cout << ans*4 << endl;
	
	return 0;
}