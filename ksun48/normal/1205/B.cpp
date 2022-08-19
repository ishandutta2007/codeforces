#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	vector<int> cnt(64);
	for(ll x : a){
		for(int b = 0; b < 62; b++){
			if(x & (1ll << b) ) cnt[b] += 1;
		}
	}
	for(int b = 0; b < 62; b++){
		if(cnt[b] >= 3){
			cout << 3 << '\n';
			return 0;
		}
	}
	a.resize(unique(a.begin(), a.end()) - a.begin());
	n = (int)a.size();
	vector<vector<int> > edges(n, vector<int>(n, 0));

	vector<vector<int> > adj(n);
	int ans = 100000;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i] & a[j]){
				edges[i][j] = 1;
				adj[i].push_back(j);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(edges[i][j]){
				vector<pair<int,int> > bfs;
				vector<bool> vis(n, false);
				int s = 0;
				bfs.push_back({i, 1});
				vis[i] = true;
				while(s < bfs.size()){
					int x = bfs[s].first;
					int d = bfs[s].second;
					s += 1;
					for(int y : adj[x]){
						if(vis[y]) continue;
						if(x == i && y == j) continue;
						if(x == j && y == i) continue;
						if(y == j){
							ans = min(ans, d + 1);
						}
						bfs.push_back({y, d + 1});
						vis[y] = true;
					}
				}
			}
		}
	}
	if(ans == 100000){
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
}