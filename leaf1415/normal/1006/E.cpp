#include <iostream>
#include <vector>

using namespace std;

int n, Q;
vector<int> G[200005];
vector<int> vec;
int s[200005], t[200005];

void dfs(int v, int prev)
{
	s[v] = vec.size();
	vec.push_back(v);
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		dfs(G[v][i], v);
	}
	t[v] = vec.size();
}

int main(void)
{
	cin >> n >> Q;
	int p;
	for(int i = 2; i <= n; i++){
		cin >> p;
		G[p].push_back(i);
		G[i].push_back(p);
	}
	
	dfs(1, -1);
	
	int u, k;
	for(int q = 0; q < Q; q++){
		cin >> u >> k;
		if(t[u] - s[u] < k) cout << -1 << endl;
		else cout << vec[s[u] + k-1] << endl;
	}
	return 0;
}