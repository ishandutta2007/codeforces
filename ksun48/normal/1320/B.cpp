#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > edges(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edges[v].push_back(u);
	}
	int len;
	cin >> len;
	vector<int> path(len);
	for(int i = 0; i < len; i++){
		cin >> path[i];
		path[i]--;
	}

	int en = path.back();
	vector<int> dist(n, -1);
	vector<int> bfs;
	bfs.push_back(en);
	dist[en] = 0;
	int s = 0;
	while(s < (int)bfs.size()){
		int v = bfs[s];
		s++;
		for(int w : edges[v]){
			if(dist[w] == -1){
				dist[w] = dist[v] + 1;
				bfs.push_back(w);
			}
		}
	}
	vector<int> nout(n, 0);
	for(int v = 0; v < n; v++){
		for(int w : edges[v]){
			if(dist[w] == dist[v] + 1){
				nout[w]++;
			}
		}
	}
	int minv = 0;
	int maxv = 0;
	for(int i = 0; i + 1 < len; i++){
		if(dist[path[i+1]] != dist[path[i]] - 1) minv++;
		if(dist[path[i+1]] != dist[path[i]] - 1 || nout[path[i]] != 1) maxv++;
	}
	cout << minv << ' ' << maxv << '\n';
}