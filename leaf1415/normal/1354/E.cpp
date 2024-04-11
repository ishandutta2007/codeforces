#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define PI 3.141592653589793238

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

llint n, m;
llint c[5];
vector<llint> G[5005];
llint color[5005];
UnionFind uf(5005);
map<llint, vector<llint> > mp;
vector<llint> vec[5005][2];

bool dp[5005][5005];
llint rec[5005][5005];

vector<llint> avec, bvec;
llint ans[5005];

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
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= 3; i++) cin >> c[i];
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		uf.unite(u, v);
	}
	
	for(int i = 1; i <= n; i++){
		if(color[i]) continue;
		if(!dfs(i, -1, 1)){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(color[i] < 0) color[i] = 0;
		mp[uf.root(i)].push_back(i);
	}
	
	//for(int i = 1; i <= n; i++) cout << color[i] << " "; cout << endl;
	
	llint N = mp.size(), id = 1;
	for(auto it = mp.begin(); it != mp.end(); it++){
		vector<llint> &cvec = it->second;
		for(int i = 0; i < cvec.size(); i++){
			vec[id][color[cvec[i]]].push_back(cvec[i]);
		}
		id++;
	}
	
	dp[0][0] = true;
	for(int i = 0; i < N; i++){
		llint bcnt = vec[i+1][0].size(), wcnt = vec[i+1][1].size();
		for(int j = 0; j <= n; j++){
			if(!dp[i][j]) continue;
			if(j+bcnt <= n) dp[i+1][j+bcnt] = true, rec[i+1][j+bcnt] = 0;
			if(j+bcnt <= n) dp[i+1][j+wcnt] = true, rec[i+1][j+wcnt] = 1;
		}
	}
	if(!dp[N][c[2]]){
		cout << "NO" << endl;
		return 0;
	}
	
	llint I = N, J = c[2];
	while(I > 0){
		llint id = rec[I][J];
		for(int i = 0; i < vec[I][id].size(); i++) avec.push_back(vec[I][id][i]);
		for(int i = 0; i < vec[I][1-id].size(); i++) bvec.push_back(vec[I][1-id][i]);
		//cout << vec[I][id].size() << endl;
		J -= vec[I][id].size(), I--;
	}
	
	for(int i = 0; i < avec.size(); i++) ans[avec[i]] = 2;
	for(int i = 0; i < bvec.size(); i++){
		if(i < c[1]) ans[bvec[i]] = 1;
		else ans[bvec[i]] = 3;
	}
	
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++) cout << ans[i];
	cout << endl;
	
	return 0;
}