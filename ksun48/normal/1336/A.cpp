#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;
vector<int> depth;
vector<int> sz;

void dfs(int v, int p, int d){
	sz[v] = 1;
	depth[v] = d;
	for(int w : edges[v]){
		if(w == p) continue;
		dfs(w, v, d+1);
		sz[v] += sz[w];
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	depth.resize(n);
	sz.resize(n);
	dfs(0, -1, 0);
	vector<int> score;
	for(int i = 0; i < n; i++){
		score.push_back(sz[i] - depth[i] - 1);
	}
	sort(score.begin(), score.end());
	long long ans = 0;
	for(int i = 0; i < k; i++){
		ans += score[i];
	}
	cout << (-ans) << '\n';
}