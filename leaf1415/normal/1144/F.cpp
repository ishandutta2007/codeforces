#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> G[200005];
int u[200005], v[200005];
int color[200005];

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
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u[i] >> v[i];
		G[v[i]].push_back(u[i]);
		G[u[i]].push_back(v[i]);
	}
	
	if(!dfs(1, -1, 1)){
		cout << "NO" << endl;
		return 0;
	}
	
	string ans;
	cout << "YES" << endl;
	for(int i = 0; i < m; i++){
		if(color[u[i]] == 1) ans += '0';
		else ans += '1';
	}
	cout << ans << endl;
	
	return 0;
}