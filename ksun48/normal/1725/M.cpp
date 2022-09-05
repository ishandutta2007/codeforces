#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, ll> > > edges(2*N);
	for(int i = 0; i < M; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back({v, w});
		edges[v + N].push_back({u + N, w});
	}
	for(int u = 0; u < N; u++){
		edges[u].push_back({u+N, 0});
	}
	ll INF = ll(1e15);
	vector<ll> dist(2*N, INF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
	dist[0] = 0;
	pq.push({dist[0], 0});
	vector<int> vis(2*N, 0);
	while(!pq.empty()){
		int v = pq.top().second;
		pq.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(auto [w, l] : edges[v]){
			dist[w] = min(dist[w], dist[v] + l);
			pq.push({dist[w], w});
		}
	}
	for(int u = 1; u < N; u++){
		if(dist[u+N] == INF){
			cout << -1;
		} else {
			cout << dist[u+N];
		}
		cout << " \n"[u == N-1];
	}
}