#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > edges(n);
	vector<vector<int> > r_edges(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		r_edges[v].push_back(u);
	}
	const int INF = int(1e8);
	vector<int> dist(n, INF);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
	vector<int> vis(n, 0);
	vector<int> need_block(n);
	for(int i = 0; i < n; i++){
		need_block[i] = (int)edges[i].size();
	}
	dist[n-1] = 0;
	pq.push({dist[n-1], n-1});
	while (!pq.empty()){
		auto [d, v] = pq.top();
		pq.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(int w : r_edges[v]){
			need_block[w]--;
			dist[w] = min(dist[w], need_block[w] + 1 + dist[v]);
			pq.push({dist[w], w});
		}
	}
	cout << dist[0] << '\n';
}