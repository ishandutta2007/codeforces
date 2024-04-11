#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#define llint long long
#define mod 1000000007

using namespace std;
typedef pair<pair<llint, llint> , llint> edge;


llint n, m, k;

struct UnionFind{
	llint size;
	llint num;
	vector<llint> parent;
	set<llint> change;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		num = n;
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	void init2(){
		num = n;
		for(auto it = change.begin(); it != change.end(); it++){
			parent[*it] = *it;
		}
		change.clear();
	}
	int root(llint i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(llint i, llint j){
		return root(i) == root(j);
	}
	void unite(llint i, llint j){
		llint root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		num--;
		parent[root_i] = root_j;
		change.insert(root_i);
	}
};

llint c[500005];
edge E[500005];
UnionFind uf(500005);
llint beki[500005];
map<llint, vector<llint> > mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	llint mul = 1;
	for(int i = 0; i < 500005; i++) beki[i] = mul, mul *= 2, mul %= mod;
	
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		E[i] = make_pair(make_pair(u, v), c[u]^c[v]);
		mp[c[u] ^ c[v]].push_back(i);
	}
	
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		uf.init2();
		for(int i = 0; i < it->second.size(); i++){
			edge e = E[it->second[i]];
			uf.unite(e.first.first, e.first.second);
		}
		ans += beki[uf.num];
		ans %= mod;
		
		//cout << it->first << " " << uf.num << endl;
	}
	llint cnum = ((1LL << k) - mp.size()) % mod;
	ans += beki[n] * cnum % mod;
	ans %= mod;
	
	cout << ans << endl;
	
	return 0;
}