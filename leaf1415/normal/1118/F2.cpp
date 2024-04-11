#include <iostream>
#include <vector>
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

llint n, k;
llint a[300005];
vector<int> G[300005], g[300005];
vector<int> vec[300005];
int dep[300005], pre[300005];
UnionFind uf(300005);
llint dp[300005][2];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void dfs(int v, int p, int d)
{
	dep[v] = d;
	pre[v] = p;
	for(int i = 0; i < g[v].size(); i++){
		if(g[v][i] == p) continue;
		dfs(g[v][i], v, d+1);
	}
}

void dfs2(int v, int p)
{
	dp[v][0] = dp[v][1] = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs2(G[v][i], v);
	}
	if(a[v] == 0){
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i];
			if(u == p) continue;
			dp[v][0] *= (dp[u][0] + dp[u][1]) % mod;
			dp[v][0] %= mod;
		}
	}
	else dp[v][0] = 0;
	
	llint mul = 1;
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		if(u == p) continue;
		mul *= (dp[u][0] + dp[u][1]) % mod;
		mul %= mod;
	}
	
	if(a[v] == 0){
		dp[v][1] = 0;
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i];
			if(u == p) continue;
			dp[v][1] += mul * modpow((dp[u][0] + dp[u][1])%mod, mod-2) % mod * dp[u][1] % mod;
			dp[v][1] %= mod;
		}
	}
	else{
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i];
			if(u == p) continue;
			dp[v][1] *= dp[u][0] + dp[u][1];
			dp[v][1] %= mod;
		}
	}
}

int Prev[300005][19];
int getLCA(int u, int v){
	int x = u, y = v;
	if(dep[y] > dep[x]) swap(x, y);
	
	for(int i = 18; i >= 0; i--){
		if(dep[x] - (1<<i) >= dep[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = 18; i >= 0; i--){
		if(Prev[x][i] != Prev[y][i]){
			x = Prev[x][i];
			y = Prev[y][i];
		}
	}
	x = Prev[x][0];
	return x;
}

bool connect(llint u, llint c)
{
	while(1){
		int p = pre[u];
		if(a[p] == c) return true;
		if(a[p] != 0 && a[p] != c) return false;
		uf.unite(p, u);
		a[p] = c;
		u = pre[u];
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0, 0);
	
	for(int i = 1; i <= n; i++) Prev[i][0] = pre[i];
	for(int i = 1; i < 19; i++){
		for(int j = 1; j <= n; j++) Prev[j][i] = Prev[Prev[j][i-1]][i-1];
	}
	
	for(int i = 1; i <= n; i++) vec[a[i]].push_back(i);
	for(int i = 1; i <= k; i++){
		int lca = vec[i][0];
		for(int j = 1; j < vec[i].size(); j++) lca = getLCA(lca, vec[i][j]);
		if(a[lca] != 0 && a[lca] != i){
			cout << 0 << endl;
			return 0;
		}
		a[lca] = i;
		for(int j = 0; j < vec[i].size(); j++){
			if(vec[i][j] == lca) continue;
			if(!connect(vec[i][j], i)){
				cout << 0 << endl;
				return 0;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < g[i].size(); j++){
			int u = uf.root(i), v = uf.root(g[i][j]);
			if(u != v) G[u].push_back(v);
		}
	}
	int root = uf.root(1);
	
	dfs2(root, -1);
	
	cout << dp[root][1] << endl;
	
	return 0;
}