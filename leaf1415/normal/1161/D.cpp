#include <iostream>
#include <string>
#include <vector>
#include <set>
#define llint long long
#define mod 998244353

using namespace std;

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

string s;
UnionFind uf(2005);
vector<int> G[2005];
int color[2005];

bool dfs(int v, int p, int c)
{
	color[v] = c;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(color[G[v][i]] == -c) continue;
		if(color[G[v][i]] == c) return false;
		if(!dfs(G[v][i], v, -c)) return false;
	}
	return true;
}

int main(void)
{
	cin >> s;
	int n = s.size();
	s = "#" + s;
	
	llint ans = 0;
	for(int i = 2; i <= n; i++){
		//cout << "i = " << i << endl;
		uf.init();
		for(int j = 1; j <= n; j++) uf.unite(j, n-j+1);
		for(int j = i; j <= n; j++) uf.unite(n+j, n+n-j+i);
		for(int j = 1; j <= n; j++) if(s[j] == '0') uf.unite(j, n+j);
		for(int j = 2; j < i; j++) uf.unite(1+n, j+n);
		uf.unite(1, 2*n);
		
		for(int j = 1; j <= 2*n; j++) G[j].clear();
		for(int j = 1; j <= n; j++){
			if(s[j] == '1'){
				G[uf.root(j)].push_back(uf.root(n+j));
				G[uf.root(n+j)].push_back(uf.root(j));
			}
		}
		bool flag = true;
		for(int j = 1; j <= 2*n; j++) color[j] = 0;
		for(int j = 1; j <= 2*n; j++){
			if(color[j]) continue;
			if(!dfs(j, -1, 1)){
				flag = false;
				break;
			}
		}
		//cout << flag << endl;
		if(!flag) continue;
		
		for(int j = 1; j <= n; j++){
			if(s[j] == '1') uf.unite(j, n+j);
		}
		set<int> S, T;
		S.insert(uf.root(1));
		for(int j = 1; j <= i; j++) S.insert(uf.root(j+n));
		for(int j = 1; j <= 2*n; j++){
			if(!S.count(uf.root(j))) T.insert(uf.root(j));
		}
		
		llint tmp = 1;
		for(int j = 0; j < T.size(); j++) tmp *= 2, tmp %= mod;
		ans += tmp, ans %= mod;
		//cout << i << " " << ans << endl;
	}
	cout << ans << endl;
	
	return 0;
}