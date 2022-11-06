#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

vector<int> g[MAXN];

bool vis[MAXN];
int pa[MAXN];

//DFS to compute the parent of each node
//parent of node i is stored at pa[i]
void dfs(int v){
	vis[v] = 1;
	for(auto i : g[v]){
		if(!vis[i]){
			pa[i] = v;
			dfs(i);
		}
	}
}

pair<int, int> dp[MAXN][2];

//Computes the value of function f, using dp
//the second coordinate of the pair is negated (to take maximums)
pair<int, int> f(int x, int y){
	pair<int, int> & res = dp[x][y];
	if(res.first >= 0) return res;
	res = {y, y ? -((int) g[x].size()) : -1};
	for(auto i : g[x]){
		if(i != pa[x]){
			pair<int, int> maxi = f(i, 0);
			if(y == 0) maxi = max(maxi, f(i, 1));
			res.first += maxi.first;
			res.second += maxi.second;
		}
	}
	return res;
}

vector<int> is_good;

//Recursive construction of the answer
//is_good[i] tells whether vertex i is good or not.
void build(pair<int, int> value, int v){
	if(value == f(v, 0)){
		is_good[v] = 0;
		for(auto i : g[v]){
			if(i != pa[v]){
				build(max(f(i, 0), f(i, 1)), i);
			}
		}
	}else{
		is_good[v] = 1;
		for(auto i : g[v]){
			if(i != pa[v]){
				build(f(i, 0), i);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v; 
		cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n == 2){
		cout<<"2 2\n1 1\n";
		return 0;
	}
	pa[0] = -1;
	dfs(0);
	for(int i = 0; i < n; i++) dp[i][0] = {-1, -1}, dp[i][1] = {-1, -1};
	pair<int, int> res = max(f(0, 0), f(0, 1));
	cout << res.first << " " << -res.second << "\n";
	is_good.resize(n);
	build(res, 0);
	for(int i = 0; i < n; i++){
		if(is_good[i]) cout << g[i].size() << " ";
		else cout << "1 ";
	}
	cout << "\n";
	return 0;
}