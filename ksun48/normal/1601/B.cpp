#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n+1), b(n+1);
	a[0] = 0;
	b[0] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	const int M = int(1e8);
	vector<int> dist(n+1, M);
	vector<int> par(n+1, -1);
	vector<int> bfs;
	set<int> unknown;
	for(int i = 0; i <= n; i++) unknown.insert(i);
	for(int i = n; i >= n-a[n]; i--){
		dist[i] = 1;
		bfs.push_back(i);
		par[i] = n;
		unknown.erase(i);
	}
	int st = 0;
	while(st < (int)bfs.size()){
		int v = bfs[st];
		st++;
		int w = v + b[v];
		int p = w - a[w];
		while(true){
			auto it = unknown.lower_bound(p);
			if(it != unknown.end() && (*it <= w)){
				int s = *it;
				dist[s] = dist[v] + 1;
				par[s] = v;
				bfs.push_back(s);
				unknown.erase(s);
			} else {
				break;
			}
		}
	}
	if(dist[0] == M){
		cout << -1 << '\n';
	} else {
		int cur = 0;
		vector<int> jumps;
		while(cur != n){
			jumps.push_back(cur);
			cur = par[cur];
		}
		cout << jumps.size() << '\n';
		reverse(jumps.begin(), jumps.end());
		for(int x : jumps) cout << x << ' ';
		cout << '\n';
	}
}