#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#define llint long long

using namespace std;
typedef pair<string, int> P;

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

llint n;
UnionFind uf(210005);
set<llint> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	string s;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 0; j < s.size(); j++){
			uf.unite(i, n+s[j]-'a'+1);
		}
	}
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		S.insert(uf.root(i));
	}
	cout << S.size() << endl;
	return 0;
}