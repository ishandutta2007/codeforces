#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, a, b, da, db;
	cin >> n >> a >> b >> da >> db;
	a--; b--;
	vector<vector<int> > edges(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int dab = 0;
	int st = a;
	int diam = 0;
	for(int j = 0; j < 2; j++){
		vector<pair<int,int> > bfs;
		vector<int> vis(n, 0);
		bfs.push_back({st, 0});
		vis[st] = 1;
		int s = 0;
		while(s < (int)bfs.size()){
			int v = bfs[s].first;
			int d = bfs[s].second;
			if(j == 0 && v == b) dab = d;
			s++;
			for(int w : edges[v]){
				if(!vis[w]){
					vis[w] = 1;
					bfs.push_back({w, d+1});
				}
			}
		}
		st = bfs.back().first;
		diam = bfs.back().second;
	}
	if(2 * da >= min(db, diam) || dab <= da){
		cout << "Alice" << '\n';
	} else {
		cout << "Bob" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}