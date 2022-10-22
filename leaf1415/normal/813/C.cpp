#include <iostream>
#include <string>
#include <vector>
#define llint long long

using namespace std;

llint n, u, v;
vector<llint> G[200005];
llint distT[200005], distA[200005];
bool used[200005];

void dfs(int v, int p, int d, llint dist[])
{
	dist[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v, d+1, dist);
	}
}

void dfs2(int v, int p)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(distA[G[v][i]] <= distT[G[v][i]]) continue;
		dfs2(G[v][i], v);
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> u; v = 1;
	llint x, y;
	for(int i = 1; i <= n-1; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(u, -1, 0, distT);
	dfs(v, -1, 0, distA);
	dfs2(u, -1);
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(used[i]) ans = max(ans, distA[i]);
	}
	cout << ans*2 << endl;
	
	return 0;
}