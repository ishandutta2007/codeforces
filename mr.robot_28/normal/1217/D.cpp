#include<bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 55;

int n, m;
vector <pair<int, int> > g[N];
int col[N];
bool cyc;
int res[N];

void dfs(int v){
	col[v] = 1;
	for(auto p : g[v]){
		int to = p.first, id = p.second;
		if(col[to] == 0){
			dfs(to);
			res[id] = 1;
		}
		else if(col[to] == 2)
			res[id] = 1;
		else{
			res[id] = 2;
			cyc = true;
		}
	}
	col[v] = 2;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(make_pair(v, i));
	}
	
	for(int i = 0; i < n; ++i)
			if(col[i] == 0)
				dfs(i);
			
	cout << (cyc? 2 : 1) << endl;
	for(int i = 0; i < m; ++i) cout << res[i] << ' ';
	cout << endl;
	return 0;
}