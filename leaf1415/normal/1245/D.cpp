#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>
#define llint long long
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

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
llint x[2005], y[2005], c[2005], k[2005];
vector<E> vec;
vector<llint> ans;
vector<P> ans2;
UnionFind uf(2005);

llint dist(llint i, llint j)
{
	return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> k[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i >= j) continue;
			vec.push_back(E((k[i]+k[j])*(dist(i, j)), P(i, j)));
		}
		vec.push_back(E(c[i], P(0, i)));
	}
	sort(vec.begin(), vec.end());
	
	llint sum = 0;
	for(int i = 0; i < vec.size(); i++){
		llint u = vec[i].second.first, v = vec[i].second.second, w = vec[i].first;
		if(uf.same(u, v)) continue;
		sum += w;
		uf.unite(u, v);
		if(u == 0) ans.push_back(v);
		else ans2.push_back(P(u, v));
	}
	
	cout << sum << endl;
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	cout << ans2.size() << endl;
	for(int i = 0; i < ans2.size(); i++) cout << ans2[i].first << " " << ans2[i].second << endl;
	
	return 0;
}