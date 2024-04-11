#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> G[100005];
int dist[100005];

void dfs(int v, int pre, int d)
{
	dist[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		dfs(G[v][i], v, d+1);
	}
}

vector<int> path;
bool dfs2(int v, int t, int pre)
{
	if(v == t){
		path.push_back(v);
		return true;
	}
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(dfs2(G[v][i], t, v)){
			path.push_back(v);
			return true;
		}
	}
	return false;
}

bool dfs3(int v, int pre, int d)
{
	int deg = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		deg++;
		if(!dfs3(G[v][i], v, d+1)) return false;
	}
	if(deg == 0){
		return d == k;
	}
	else{
		return deg >= 3;
	}
}

int main(void)
{
	cin >> n >> k;
	
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n == 1){
		cout << "No" << endl;
		return 0;
	}
	
	dfs(1, -1, 0);
	int max_d = 0, max_v;
	for(int i = 1; i <= n; i++){
		if(max_d < dist[i]){
			max_d = dist[i];
			max_v = i;
		}
	}
	int a = max_v;
	
	dfs(a, -1, 0);
	max_d = 0, max_v;
	for(int i = 1; i <= n; i++){
		if(max_d < dist[i]){
			max_d = dist[i];
			max_v = i;
		}
	}
	int b = max_v;
	
	if(max_d % 2){
		cout << "No" << endl;
		return 0;
	}
	dfs2(a, b, 0);
	int cent = path[max_d/2], rad = max_d/2;
	
	if(dfs3(cent, -1, 0)) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}