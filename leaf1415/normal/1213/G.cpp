#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

struct UnionFind{
	int size;
	vector<llint> parent;
	vector<llint> num;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		num.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i, num[i] = 1;
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
		num[root_j] += num[root_i];
	}
	llint getnum(int i){
		return num[root(i)];
	}
};

llint n, m;
vector<E> vec;
map<llint, llint> mp;
UnionFind uf(200005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v, w;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v >> w;
		vec.push_back(make_pair(w, make_pair(u, v)));
	}
	
	sort(vec.begin(), vec.end());
	
	uf.init();
	mp[0] = 0;
	
	llint cnt = 0;
	for(int i = 0; i < vec.size(); i++){
		llint w = vec[i].first, u = vec[i].second.first, v = vec[i].second.second;
		if(uf.same(u, v)) continue;
		cnt += uf.getnum(u) * uf.getnum(v);
		uf.unite(u, v);
		mp[w] = cnt;
	}
	
	llint x, y, q;
	for(int i = 0; i < m; i++){
		cin >> q;
		auto it = mp.upper_bound(q);
		it--;
		cout << it->second << " ";
	}
	cout << endl;
	
	return 0;
}