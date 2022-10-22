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
#define mod 998244353

using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> E;

struct TreeUnionFind{
	int size;
	vector<int> parent, top;
	vector<P> tree;
	
	TreeUnionFind(){}
	TreeUnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		top.resize(size+1);
		tree.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++){
			parent[i] = i;
			tree[i] = P(-1, -1);
			top[i] = i;
		}
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	int unite(int i, int j){  //
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return -1;
		
		tree.push_back(P(top[root_i], top[root_j]));
		parent[root_i] = root_j;
		top[root_j] = (int)tree.size()-1;
		return top[root_j];
	}
	int gettop(int i){ //
		return top[root(i)];
	}
};

llint n;
int a[1505][1505], mx[4505];
TreeUnionFind uf(1505);
vector<E> vec;

llint tim[4005];
llint leaf[4005];
llint dp[4005][4005];

int Prev[4005][12];
int depth[4005];

void predfs(int v, int p, int d)
{
	depth[v] = d;
	Prev[v][0] = p;
	
	llint l = uf.tree[v].first, r = uf.tree[v].second;
	if(l != -1){
		predfs(l, v, d+1), predfs(r, v, d+1);
		mx[v] = max(mx[l], mx[r]);
	}
	
}

int getLCA(int u, int v){
	int x = u, y = v;
	if(depth[y] > depth[x]) swap(x, y);
	
	for(int i = 11; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = 11; i >= 0; i--){
		if(Prev[x][i] != Prev[y][i]){
			x = Prev[x][i];
			y = Prev[y][i];
		}
	}
	x = Prev[x][0];
	return x;
}

void dfs2(int v, int p){
	
	llint l = uf.tree[v].first, r = uf.tree[v].second;
	if(l != -1){
		dfs2(l, v), dfs2(r, v);
		chmax(mx[v], mx[l]);
		chmax(mx[v], mx[r]);
	}
}


void dfs(int v, int p)
{
	llint l = uf.tree[v].first, r = uf.tree[v].second;
	if(l != -1){
		dfs(l, v), dfs(r, v);
		leaf[v] = leaf[l]+leaf[r];
	}
	else leaf[v] = 1;
	
	if(l != -1){
		for(int i = 0; i <= leaf[l]; i++){
			for(int j = 0; j <= leaf[r]; j++){
				dp[v][i+j] += dp[l][i] * dp[r][j] % mod;
				dp[v][i+j] %= mod;
			}
		}
	}
	if(p == -1 || mx[v] <= tim[p]) dp[v][1]++, dp[v][1] %= mod;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			vec.push_back(E(a[i][j], P(i, j)));
		}
	}
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < vec.size(); i++){
		llint u = vec[i].second.first, v = vec[i].second.second;
		llint res = uf.unite(u, v);
		if(res != -1) tim[res] = vec[i].first;
	}
	llint root = uf.gettop(1);
	
	predfs(root, 0, 0);
	for(int i = 1; i < 12; i++){
		for(int j = 1; j < uf.tree.size(); j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			chmax(mx[getLCA(i, j)], a[i][j]);
		}
	}
	
	dfs2(root, -1);
	dfs(root, -1);
	for(int i = 1; i <= n; i++) cout << dp[root][i] << " "; cout << endl;
	
	return 0;
}