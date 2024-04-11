#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,ll> > > edges(n);
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({b, c});
	}

	ll M = ll(1e15);
	vector<vector<ll> > ans(n, vector<ll>(n, M));
	for(int st = 0; st < n; st++){
		vector<ll> dist(n, M);
		vector<int> vis(n, 0);
		for(auto [b, c] : edges[st]){
			dist[b] = min(dist[b], c);
		}
		for(int j = 0; j < n; j++){
			int best = -1;
			for(int v = 0; v < n; v++){
				if(vis[v]) continue;
				if(best == -1 || dist[v] < dist[best]) best = v;
			}
			int v = best;
			vis[v] = 1;
			dist[(v+1) % n] = min(dist[(v+1) % n], dist[v] + 1);
			for(auto [b, c] : edges[v]){
				int go = int((b + dist[v]) % n);
				dist[go] = min(dist[go], dist[v] + c);
			}
		}
		dist[st] = 0;
		ans[st] = dist;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}