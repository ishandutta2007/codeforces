#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define inf 1e9

using namespace std;

int n;
int c[200005];
vector<int> G[200005], revG[200005], g[200005];

vector<int> topo;
bool used[200005];
int scc[200005];
set<int> S;
int mn[200005];

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
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	int a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		G[i].push_back(a);
		revG[a].push_back(i);
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
		}
	}
	for(int i = 0; i < cid; i++){
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
	}
	
	for(int i = 0; i < cid; i++){
		if(g[i].size() == 0) S.insert(i);
	}
	for(int i = 0; i < cid; i++) mn[i] = inf;
	for(int i = 1; i <= n; i++){
		if(S.count(scc[i])){
			mn[scc[i]] = min(mn[scc[i]], c[i]);
		}
	}
	
	int ans = 0;
	for(int i = 0; i < cid; i++){
		if(S.count(i)) ans += mn[i];
	}
	cout << ans << endl;
	
	return 0;
}