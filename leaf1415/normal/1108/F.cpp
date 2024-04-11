#include <iostream>
#include <map>
#include <utility>
#include <vector>
#define llint long long

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

int n, m;
map<llint, vector<P> > mp;
UnionFind uf(200005);
bool flag[200005];

int main(void)
{
	cin >> n >> m;
	int u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		mp[w].push_back(make_pair(u, v));
	}
	
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		for(int i = 0; i < it->second.size(); i++) flag[i] = false;
		for(int i = 0; i < it->second.size(); i++){
			if(uf.same(it->second[i].first, it->second[i].second)) flag[i] = true;
		}
		for(int i = 0; i < it->second.size(); i++){
			if(flag[i]) continue;
			int u = it->second[i].first, v = it->second[i].second;
			if(uf.same(u, v)){
				ans++;
				mp[it->first+1].push_back(make_pair(u, v));
			}
			else uf.unite(u, v);
		}
	}
	cout << ans << endl;
	
	return 0;
}