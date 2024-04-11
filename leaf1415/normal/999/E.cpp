#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s;
vector<int> G[5005], revG[5005], g[5005], revg[5005];
vector<int> topo;
bool used[5005];
int scc[5005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}

void dfs(int v, int id)
{
	used[v] = true;
	scc[v] = id;
	for(int i = 0; i < revG[v].size(); i++){
		if(!used[revG[v][i]]) dfs(revG[v][i], id);
	}
}

int main(void)
{
	cin >> n >> m >> s;
	int u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		revG[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++){
		if(!used[i]) tpsort(i);
	}
	reverse(topo.begin(), topo.end());
	
	int cid = 0;
	for(int i = 1; i <= n; i++) used[i] = false;
	for(int i = 0; i < n; i++){
		if(!used[topo[i]]) dfs(topo[i], cid++);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			if(scc[i] == scc[G[i][j]]) continue;
			g[scc[i]].push_back(scc[G[i][j]]);
			revg[scc[G[i][j]]].push_back(scc[i]);
		}
	}
	
	int ans = 0;
	for(int i = 0; i < cid; i++){
		if(i == scc[s]) continue;
		if(revg[i].size() == 0) ans++;
	}
	cout << ans << endl;
	
	return 0;
}