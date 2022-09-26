#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, root;
bool visit[N];
int deg[N];
int h[N];
vector<int> G[N];
vector<int> res;

void dfs(int u,int p) {
	for (int i = 0;i < G[u].size();++i) {
		int v = G[u][i];
		if (v == p) continue;
		h[v] = h[u] + 1;
		dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n;
	if (n % 2 == 0) return cout << "NO" << endl,0;
	
	for (int i = 1;i <= n;++i) {
		int p;	cin >> p;
		if (p == 0) root = i;
		else {
			G[p].push_back(i); G[i].push_back(p);
			++deg[i]; ++deg[p];
		}
	}
	
	dfs(root, root);
	priority_queue<pair<int,int> > pq;
	for (int i = 1;i <= n;++i) {
		if (deg[i] % 2 == 0) pq.push(make_pair(h[i], i));
	}
	
	while(!pq.empty()) {
		pair<int,int> u = pq.top(); pq.pop();
		
		if (visit[u.second] || deg[u.second] & 1) continue;
		deg[u.second] = 0; visit[u.second] = true; res.push_back(u.second);
		for (int i = 0;i < G[u.second].size();++i) {
			int v = G[u.second][i];
			if (deg[v] == 0) continue;
			--deg[v]; if (deg[v] % 2 == 0) pq.push(make_pair(h[v], v));
		}
	}
	cout << "YES" << endl;
	for (int i = 0;i < n;++i) cout << res[i] << endl;
}