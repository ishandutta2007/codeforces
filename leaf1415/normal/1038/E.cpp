#include <iostream>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

struct UnionFind{
	llint size;
	vector<llint> parent;
	
	UnionFind(){}
	UnionFind(llint size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(llint i = 0; i <= size; i++) parent[i] = i;
	}
	llint root(llint i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(llint i, llint j){
		return root(i) == root(j);
	}
	void unite(llint i, llint j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};

llint n;
UnionFind uf(50);
llint deg[50];
llint sum[50];

int main(void)
{
	cin >> n;
	llint s, val, t, mn = inf;
	for(int i = 0; i < n; i++){
		cin >> s >> val >> t;
		uf.unite(s, t);
		deg[s]++, deg[t]++;
		sum[s] += val, sum[t] += val;
		if(s != t) mn = min(mn, val);
	}
	
	llint ans = 0;
	for(llint i = 1; i <= 4; i++){
		vector<llint> vec;
		vec.clear();
		for(llint j = 1; j <= 4; j++) if(uf.same(i, j)) vec.push_back(j);
		
		llint odd = 0, S = 0;
		for(llint j = 0; j < vec.size(); j++){
			if(deg[vec[j]] % 2) odd++;
			S += sum[vec[j]];
		}
		S /= 2;
		if(odd != 4) ans = max(ans, S);
		else ans = max(ans, S-mn);
	}
	cout << ans << endl;
	return 0;
}