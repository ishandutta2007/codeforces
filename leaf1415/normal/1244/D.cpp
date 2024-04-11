#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#define llint long long
#define inf 100000000000000000

using namespace std;

llint n;
llint cost[100005][3];
vector<llint> G[100005];
llint color[100005];

llint dfs(llint v, llint p, llint pc, llint c)
{
	llint ret = 0;
	color[v] = c, ret += cost[v][c];
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		ret += dfs(G[v][i], v, c, 3-(c+pc));
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < 3; i++){
		for(int j = 1; j <= n; j++) cin >> cost[j][i];
	}
	
	llint u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	llint root;
	for(int i = 1; i <= n; i++){
		if(G[i].size() >= 3){
			cout << -1 << endl;
			return 0;
		}
		if(G[i].size() == 1) root = i;
	}
	
	llint ans = inf, mn_i, mn_j, node = G[root][0];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
			llint res = dfs(node, root, i, j) + cost[root][i];
			if(res < ans){
				ans = res;
				mn_i = i, mn_j = j;
			}
		}
	}
	color[root] = mn_i, color[node] = mn_j;
	dfs(node, root, mn_i, mn_j);
	
	cout << ans << endl;
	for(int i = 1; i <= n; i++) cout << color[i]+1 << " "; cout << endl;
	
	return 0;
}