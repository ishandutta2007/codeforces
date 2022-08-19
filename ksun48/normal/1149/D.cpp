#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int> > ea(n), eb(n);
	vector<vector<int> > conn(n, vector<int>(n, 0));
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		u--; v--;
		assert(c == a || c == b);
		if(c == a){
			conn[u][v] = conn[v][u] = 1;
			ea[u].push_back(v);
			ea[v].push_back(u);
		} else {
			eb[u].push_back(v);
			eb[v].push_back(u);
		}
	}
	for(int i = 0; i < n; i++) conn[i][i] = 1;
	for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		conn[i][j] |= (conn[i][k] & conn[k][j]);
	}
	int ncc = 0;
	vector<int> mask(n, -1);
	for(int i = 0; i < n; i++){
		if(mask[i] != -1) continue;
		vector<int> cc;
		for(int j = 0; j < n; j++){
			if(conn[i][j]) cc.push_back(j);
		}
		int sz = cc.size();
		int v = 0;
		if(sz >= 4){
			v = (1 << ncc);
			ncc++;
		}
		for(int x : cc){
			mask[x] = v;
		}
	}
	const int Z = (1 << ncc);
	vector<vector<int> > edgesa(n * Z), edgesb(n * Z);
	vector<int> dist(n * Z, 2e9);
	vector<bool> vis(n * Z, false);
	dist[0] = 0;
	priority_queue<pair<int,int> > cur;
	for(int i = 0; i < n * Z; i++){
		cur.push({-dist[i], i});
	}
	while(!cur.empty()){
		int v = cur.top().second;
		cur.pop();
		if(vis[v]) continue;
		vis[v] = true;
		for(auto x : ea[v / Z]){
			int w = x * Z + (v & (Z-1));
			if(dist[v] + a < dist[w]){
				dist[w] = dist[v] + a;
				cur.push({-dist[w], w});				
			}
		}
		for(auto x : eb[v / Z]){
			if(mask[x] & v) continue;
			if(conn[v / Z][x]) continue;
			int w = x * Z + ((v & (Z-1)) | mask[v / Z]);
			if(dist[v] + b < dist[w]){
				dist[w] = dist[v] + b;
				cur.push({-dist[w], w});				
			}
		}
	}
	for(int i = 0; i < n; i++){
		int ans = 2e9;
		for(int f = 0; f < Z; f++){
			ans = min(ans, dist[i * Z + f]);
		}
		cout << ans << " ";
	}
	cout << '\n';
}