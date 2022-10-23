#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int N, M;
	cin >> N >> M;
	vector<vector<int> > edges(N);
	vector<tuple<int, int, ll> > r(M);
	vector<vector<int> > d(N, vector<int>(N, int(1e8)));
	for(int i = 0; i < M; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		r[i] = {u, v, w};
		d[u][v] = d[v][u] = 1;
	}
	for(int i = 0; i < N; i++) d[i][i] = 0;
	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	ll ans = ll(1e18);
	vector<int> best_3(N, int(1e8));
	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++){
			best_3[i] = min(best_3[i], d[0][k] + d[N-1][k] + d[i][k]);
		}
	}
	for(auto [u, v, w] : r){
		int best = ll(1e8);
		best = min(best, d[0][u] + d[N-1][v]);
		best = min(best, d[0][v] + d[N-1][u]);
		best = min(best, 1 + best_3[u]);
		best = min(best, 1 + best_3[v]);
		ans = min(ans, ll(best + 1) * w);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}