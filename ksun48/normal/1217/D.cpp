#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> ans(m);
	vector<vector<int> > edges(n);
	vector<int> deg(n, 0);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		deg[v]++;
		ans[i] = (u < v);
		edges[u].push_back(v);
	}
	vector<int> bfs;
	for(int i = 0; i < n; i++){
		if(deg[i] == 0) bfs.push_back(i);
	}
	int s = 0;
	while(s < (int)bfs.size()){
		int v = bfs[s];
		s += 1;
		for(int w : edges[v]){
			deg[w]--;
			if(deg[w] == 0) bfs.push_back(w);
		}
	}
	if(n == (int)bfs.size()){
		cout << 1 << '\n';
		for(int x : ans) cout << 1 << ' ';
		cout << '\n';
	} else {
		cout << 2 << '\n';
		for(int x : ans) cout << 1 + x << ' ';
		cout << '\n';		
	}
}