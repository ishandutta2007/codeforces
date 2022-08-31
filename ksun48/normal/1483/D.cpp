#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	using ll = long long;
	const ll F = 1e14;
	vector<vector<ll> > edges(n, vector<ll>(n, F));
	vector<vector<ll> > trips(n, vector<ll>(n, -1));
	for(int i = 0; i < m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u][v] = edges[v][u] = w;
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		trips[u][v] = trips[v][u] = w;
	}
	vector<vector<ll> > dist(n, vector<ll>(n, F));
	for(int i = 0; i < n; i++){
		dist[i][i] = 0;
		for(int j = 0; j < n; j++){
			dist[i][j] = min(dist[i][j], edges[i][j]);
		}
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
			}
		}
	}
	vector<vector<bool> > useful(n, vector<bool>(n, false));
	for(int u = 0; u < n; u++){
		vector<ll> score = trips[u];
		vector<bool> vis(n, false);
		while(true){
			int best = -1;
			for(int v = 0; v < n; v++){
				if(vis[v]) continue;
				if(best == -1 || score[v] > score[best]) best = v;
			}
			if(best == -1) break;
			int v = best;
			vis[v] = true;
			for(int w = 0; w < n; w++){
				if(score[v] - edges[v][w] > score[w]){
					score[w] = score[v] - edges[v][w];
				}
			}
		}
		for(int v = 0; v < n; v++){
			for(int w = 0; w < n; w++){
				if(dist[u][v] + edges[v][w] <= score[w]){
					useful[v][w] = true;
				}
			}
		}
	}
	int ans = 0;
	for(int u = 0; u < n; u++){
		for(int v = 0; v < u; v++){
			if(useful[u][v] || useful[v][u]) ans++;
		}
	}
	cout << ans << '\n';
}