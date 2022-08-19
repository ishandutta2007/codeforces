#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int> > > redges(n);
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		u--; v--;
		redges[v].push_back({u, c});
	}
	vector<vector<int> > best(n, vector<int>(2, int(1e8)));
	best[n-1][0] = best[n-1][1] = 0;
	vector<int> vis(n, 0);
	set<pair<int,int> > z;
	z.insert({0, n-1});
	while(!z.empty()){
		pair<int,int> cur = *z.begin();
		z.erase(z.begin());
		int v = cur.second;
		if(vis[v]) continue;
		for(pair<int,int> e : redges[v]){
			int w = e.first;
			int cd = max(best[w][0], best[w][1]);
			best[w][e.second] = min(best[w][e.second], 1 + cur.first);
			int nd = max(best[w][0], best[w][1]);
			if(nd < cd){
				z.insert({nd, w});
			}
		}
	}
	int ans = max(best[0][0], best[0][1]);
	if(ans >= int(1e7)) ans = -1;
	cout << ans << '\n';
	for(int i = 0; i < n; i++){
		if(best[i][0] > best[i][1]){
			cout << 0;
		} else {
			cout << 1;
		}
	}
	cout << '\n';
}