#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

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
llint l[500005], r[500005];
vector<P> vec;
set<P> S;
UnionFind uf(500005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		vec.push_back(P(l[i], i));
		vec.push_back(P(r[i], i));
	}
	sort(vec.begin(), vec.end());
	
	llint ans = 0;
	for(int i = 0; i < vec.size(); i++){
		llint pos = vec[i].first, id = vec[i].second;
		if(l[id] == pos){
			for(auto it = S.begin(); it != S.end(); it++){
				if(it->first >= r[id]) break;
				if(uf.same(it->second, id)){
					cout << "NO" << endl;
					return 0;
				}
				uf.unite(it->second, id);
			}
			S.insert(P(r[id], id));
		}
		else S.erase(P(r[id], id));
	}
	
	for(int i = 1; i <= n; i++){
		if(uf.root(i) != uf.root(1)){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	
	return 0;
}