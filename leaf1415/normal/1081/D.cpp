#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, pair<int, int> > edge;

struct UnionFind{
	int size;
	vector<int> parent, num;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		num.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i, num[i] = 0;
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
		num[root_j] += num[root_i];
		parent[root_i] = root_j;
	}
};

int n, m, k;
vector<edge> vec;
UnionFind uf(100005);
int x[100005];

int main(void)
{
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		cin >> x[i];
		uf.num[x[i]] = 1;
	}
	int u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		vec.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(vec.begin(), vec.end());
	
	int ans;
	for(int i = 0; i < vec.size(); i++){
		uf.unite(vec[i].second.first, vec[i].second.second);
		if(uf.num[uf.root(x[0])] == k){
			ans = vec[i].first;
			break;
		}
	}
	for(int i = 1; i <= k; i++) cout << ans << " "; cout << endl;
	
	return 0;
}