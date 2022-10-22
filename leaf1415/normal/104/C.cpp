#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> P;

int n, m;
vector<int> G[105];
P E[5005];
bool used[105];

bool dfs(int v, int prev, int ng)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		if(E[ng] == make_pair(min(v, G[v][i]), max(v, G[v][i]))) continue;
		if(used[G[v][i]]) return false;
		if(!dfs(G[v][i], v, ng)) return false;
	}
	return true;
}

int main(void)
{
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		E[i] = make_pair(min(u, v), max(u, v));
	}
	
	if(n != m){
		cout << "NO" << endl;
		return 0;
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 1; j <= n; j++) used[j] = false;
		if(!dfs(1, -1, i)) continue;
		bool flag = true;
		for(int j = 1; j <= n; j++){
			if(!used[j]){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "FHTAGN!" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}