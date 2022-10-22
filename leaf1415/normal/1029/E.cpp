#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> g[200005], G[200005];
int depth[200005];
int pre[200005];
bool mark[200005];
vector<pair<int, int> > vec;

void depdfs(vector<int> G[], int v, int prev, int dep)
{
	depth[v] = dep;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		depdfs(G, G[v][i], v, dep+1);
	}
}

void makedfs(int v, int prev)
{
	for(int i = 0; i < g[v].size(); i++){
		if(g[v][i] == prev) continue;
		G[v].push_back(g[v][i]);
		makedfs(g[v][i], v);
	}
}

void marks(int v)
{
	mark[v] = true;
	for(int i = 0; i < g[v].size(); i++) mark[g[v][i]] = true;
}

int main(void)
{
	cin >> n;
	k = 2;
	
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	depdfs(g, 1, 0, 0);
	makedfs(1, 0);
	
	depdfs(G, 1, 0, 0);
	for(int i = 1; i <= n; i++) vec.push_back(make_pair(depth[i], i));
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			pre[G[i][j]] = i;
		}
	}
	pre[1] = -1;
	
	int ans = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].first <= k) break;
		int v = vec[i].second;
		if(mark[v]) continue;
		ans++;
		marks(pre[v]);
	}
	
	cout << ans << endl;
	return 0;
}