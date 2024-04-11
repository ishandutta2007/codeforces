#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> edge;

int n, m, k;
vector<int> G[200005];
edge E[200005];
int deg[200005];
bool invalid[200005];
int cnt;
int ans[200005];

void dfs(int v)
{
	invalid[v] = true; cnt--;
	for(int i = 0; i < G[v].size(); i++){
		if(invalid[G[v][i]]) continue;
		deg[G[v][i]]--;
		if(deg[G[v][i]] < k) dfs(G[v][i]);
	}
}

int main(void)
{
	cin >> n >> m >> k;
	int u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		E[i] = make_pair(u, v);
		deg[u]++, deg[v]++;
	}
	for(int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
	
	
	cnt = n;
	for(int i = 1; i <= n; i++){
		if(!invalid[i] && deg[i] < k) dfs(i);
	}
	
	/*for(int i = 1; i <= n; i++) cout << deg[i] << " "; cout << endl;
	for(int i = 1; i <= n; i++) cout << invalid[i] << " "; cout << endl;
	*/
	
	ans[m] = cnt;
	for(int i = m; i > 1; i--){
		int u = E[i].first, v = E[i].second;
		if(!invalid[u] && !invalid[v]){
			deg[u]--, deg[v]--;
			int p = lower_bound(G[u].begin(), G[u].end(), v) - G[u].begin();
			int q = lower_bound(G[v].begin(), G[v].end(), u) - G[v].begin();
			G[u].erase(G[u].begin() + p);
			G[v].erase(G[v].begin() + q);
			if(!invalid[u] && deg[u] < k) dfs(u);
			if(!invalid[v] && deg[v] < k) dfs(v);
		}
		ans[i-1] = cnt;
		
		//for(int i = 1; i <= n; i++) cout << deg[i] << " "; cout << endl;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << endl;
	return 0;
}