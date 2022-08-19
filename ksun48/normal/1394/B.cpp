#include <bits/stdc++.h>
using namespace std;

using i128 = __uint128_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int,int> > > edges(n);
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back({w, v});
	}
	vector<i128> id(n);
	i128 total = 0;
	for(int i = 0; i < n; i++){
		id[i] = (i128(mt()) << 64) ^ i128(mt());
		total += id[i];
	}
	vector<vector<i128>> what(k+1);
	for(int r = 1; r <= k; r++){
		what[r].resize(r);
	}
	for(int i = 0; i < n; i++){
		int deg = (int)edges[i].size();
		assert(deg >= 1 && deg <= k);
		sort(edges[i].begin(), edges[i].end());
		for(int j = 0; j < deg; j++){
			what[deg][j] += id[edges[i][j].second];
		}
	}
	vector<i128> cand = {0};
	for(int r = 1; r <= k; r++){
		vector<i128> newcand;
		for(i128 a : cand){
			for(i128 f : what[r]){
				newcand.push_back(a+f);
			}
		}
		cand = newcand;
	}
	int ans = 0;
	for(i128 g : cand) if(g == total) ans += 1;
	cout << ans << '\n';
}