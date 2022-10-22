#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> edge;

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
llint a[200005];
vector<P> vec;
vector<edge> E;
UnionFind uf(200005);

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		vec.push_back(make_pair(a[i], i));
	}
	sort(vec.begin(), vec.end());
	
	int x = vec[0].second;
	for(int i = 1; i <= n; i++){
		if(i == x) continue;
		E.push_back(make_pair(a[i]+a[x], make_pair(i, x)));
	}
	
	llint u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		E.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(E.begin(), E.end());
	
	llint ans = 0;
	for(int i = 0; i < E.size(); i++){
		if(!uf.same(E[i].second.first, E[i].second.second)){
			uf.unite(E[i].second.first, E[i].second.second);
			ans += E[i].first;
		}
	}
	cout << ans << endl;
	
	return 0;
}