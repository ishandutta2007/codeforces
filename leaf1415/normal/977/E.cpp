#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> G[200005];
int used[200005];

int dfs(int v, int prev)
{
	if(used[v] == 1){
		used[v] = 2;
		return 1;
	}
	
	used[v] = 1;
	int ret = 1;
	if(G[v].size() != 2) ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		if(used[G[v][i]]) continue;
		ret &= dfs(G[v][i], v);
	}
	used[v] = 2;
	return ret;
}

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!used[i]) ans += dfs(i, 0);
	}
	cout << ans << endl;
	return 0;
}