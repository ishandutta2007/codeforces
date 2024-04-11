#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18

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

llint n, m;
vector<llint> G[100005];
vector<E> vec;
set<P> S;
set<llint> T;
UnionFind uf(100005);

llint calc()
{
	sort(vec.begin(), vec.end());
	
	llint ret = 0;
	for(int i = 0; i < vec.size(); i++){
		llint w = vec[i].first, u = vec[i].second.first, v = vec[i].second.second;
		if(uf.same(u, v)) continue;
		ret += w;
		uf.unite(u, v);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		if(u > v) swap(u, v);
		S.insert(P(u, v));
	}
	
	if(n <= 400){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i >= j) continue;
				if(S.count(P(i, j))) vec.push_back(E(1LL, P(i, j)));
				else vec.push_back(E(0LL, P(i, j)));
			}
		}
		cout << calc() << endl;
		return 0;
	}
	
	llint mn = inf, mn_v;
	for(int i = 1; i <= n; i++){
		if(mn > (llint)G[i].size()){
			mn = (llint)G[i].size();
			mn_v = i;
		}
	}
	for(int i = 0; i < G[mn_v].size(); i++) T.insert(G[mn_v][i]);
	
	if(T.size() == 0){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans;
	for(auto it = T.begin(); it != T.end(); it++){
		for(auto it2 = T.begin(); it2 != T.end(); it2++){
			if(*it >= *it2) continue;
			if(S.count(P(*it, *it2))) vec.push_back(E(1LL, P(*it, *it2)));
			else vec.push_back(E(0LL, P(*it,*it2)));
		}
	}
	
	llint comp = n - (llint)T.size();
	for(auto it = T.begin(); it != T.end(); it++){
		int v = *it; bool flag = true;
		if(G[v].size() < comp) flag = false;
		int cnt = 0;
		for(int i = 0; i < G[v].size(); i++){
			if(T.count(G[v][i]) == 0) cnt++;
		}
		if(cnt < comp) flag = false;
		if(flag) vec.push_back(E(1LL, P(mn_v, v)));
		else vec.push_back(E(0LL, P(mn_v, v)));
	}
	ans = calc();
	cout << ans << endl;
	
	return 0;
}