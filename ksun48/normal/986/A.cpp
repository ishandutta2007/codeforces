#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vector<int> values[n];
	vector<int> towns[k];
	vector<int> edges[n];
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a--;
		towns[a].push_back(i);
	}
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	int dist[n];
	int vis[n];
	for(int t = 0; t < k; t++){
		for(int j = 0; j < n; j++){
			dist[j] = 0;
			vis[j] = 0;
		}
		vector<pair<int,int> > q;
		for(int a : towns[t]){
			q.push_back({a, 0});
			vis[a] = 1;
		}
		int s = 0;
		while(s < q.size()){
			pair<int,int> v = q[s];
			dist[v.first] = v.second;
			s++;
			for(int z : edges[v.first]){
				if(vis[z]) continue;
				q.push_back({z, v.second + 1});
				vis[z] = 1;
			}
		}
		for(int j = 0; j < n; j++){
			values[j].push_back(dist[j]);
		}
	}

	for(int i = 0; i < n; i++){
		sort(values[i].begin(), values[i].end());
		int ans = 0;
		for(int j = 0; j < s; j++){
			ans += values[i][j];
		}
		cout << ans << " ";
	}
	cout << '\n';
}