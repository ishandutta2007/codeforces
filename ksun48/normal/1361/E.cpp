#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > edges(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
	}
	mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
	for(int _ = 0; _ < 60; _++){
		int st = uniform_int_distribution<int>(0, n-1)(mt);
		vector<int> bfs = {st};
		vector<int> vis(n, 0);
		int s = 0;
		vis[st] = 1;
		vector<int> par(n);
		vector<int> d(n);
		par[st] = st;
		d[st] = 0;
		while(s < (int)bfs.size()){
			int v = bfs[s];
			s++;
			for(int w : edges[v]){
				if(vis[w]) continue;
				par[w] = v;
				d[w] = d[v] + 1;
				bfs.push_back(w);
				vis[w] = 1;
			}
		}
		if((int)bfs.size() != n){
			continue;
		}
		const int MAXJ = 18;
		vector<vector<int> > jmp(MAXJ, vector<int>(n));
		jmp[0] = par;
		for(int j = 1; j < MAXJ; j++){
			for(int i = 0; i < n; i++){
				jmp[j][i] = jmp[j-1][jmp[j-1][i]];
			}
		}
		vector<int> count_over(n, 0);
		bool fail = false;
		vector<int> up_where(n, -1);
		for(int v = 0; v < n; v++){
			for(int w : edges[v]){
				if(par[w] == v) continue;
				int dv = d[v];
				int dw = d[w];
				if(dv <= dw){
					fail = true;
				} else {
					int dist = dv - dw;
					int cv = v;
					for(int j = 0; j < MAXJ; j++){
						if(dist & (1 << j)){
							cv = jmp[j][cv];
						}
					}
					if(cv != w){
						fail = true;
					} else {
						count_over[v] += 1;
						count_over[w] -= 1;
						if(up_where[v] == -1 || d[w] < d[up_where[v]]){
							up_where[v] = w;
						}
					}
				}
			}
		}
		if(fail){
			continue;
		}
		vector<int> answers;
		for(int g = n-1; g > 0; g--){
			int v = bfs[g];
			int p = par[v];
			count_over[p] += count_over[v];
			if(up_where[v] != -1){
				if(up_where[p] == -1 || d[up_where[v]] < d[up_where[p]]){
					up_where[p] = up_where[v];
				}
			}
		}
		vector<int> good(n, 1);
		for(int g = 1; g < n; g++){
			int v = bfs[g];
			if(count_over[v] != 1 || !good[up_where[v]]){
				good[v] = 0;
			}
		}
		for(int i = 0; i < n; i++){
			if(good[i]) answers.push_back(i);
		}
		if((int)answers.size() * 5 < n){
			cout << -1 << '\n';
		} else {
			for(int a : answers){
				cout << a + 1 << ' ';
			}
			cout << '\n';
		}
		return;
	}
	cout << -1 << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}