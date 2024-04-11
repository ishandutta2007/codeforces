#include <bits/stdc++.h>
using namespace std;
int n, k;

vector<vector<int> > edges;

vector<int> par;
vector<vector<int> > ch;

vector<vector<int> > paths;

vector<int> down;
vector<int> down_where;
vector<int> up;

vector<int> vs;
void dfs(int v, int p){
	par[v] = p;
	if(p >= 0) ch[p].push_back(v);
	for(int w : edges[v]){
		if(w == p) continue;
		dfs(w, v);
	}
	vs.push_back(v);
}

vector<int> color;
void dfs2(int v, int p, int col, int diff){
	col %= k;
	if(col < 0) col += k;
	color[v] = col;
	for(int w : edges[v]){
		if(w == p) continue;
		dfs2(w, v, col + diff, diff);
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	edges.resize(n); ch.resize(n); par.resize(n);
	paths.resize(n); down.assign(n, 0); down_where.assign(n, -1); up.assign(n, 0);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, -1);
	assert((int)vs.size() == n);
	for(int v : vs){
		int p = par[v];
		if(p == -1) continue;
		paths[p].push_back(1 + down[v]);
		if(1 + down[v] > down[p]){
			down[p] = 1 + down[v];
			down_where[p] = v;
		}
	}
	reverse(vs.begin(), vs.end());
	up[0] = 0;
	for(int v : vs){
		multiset<int> g;
		for(int w : ch[v]){
			g.insert(down[w] + 1);
		}
		for(int w : ch[v]){
			up[w] = up[v] + 1;
			g.erase(g.find(down[w] + 1));
			if(!g.empty()) up[w] = max(up[w], *prev(g.end()) + 1);
			g.insert(down[w] + 1);
			paths[w].push_back(up[w]);
		}
	}
	for(int i = 0; i < n; i++){
		if(up[i] > down[i]){
			down[i] = up[i];
			down_where[i] = par[i];
		}
	}
	int r = -1;
	for(int i = 0; i < n; i++){
		assert(down_where[i] >= 0);
		if(down_where[down_where[i]] == i){
			//assert(r == -1 || r == down_where[i]);
			r = i;
		}
	}
	for(int i = 0; i < n; i++){
		sort(paths[i].begin(), paths[i].end());
		reverse(paths[i].begin(), paths[i].end());
		if(k >= 3 && (int)paths[i].size() >= 3 && paths[i][1] + paths[i][2] >= k-1){
			cout << "No" << '\n';
			return 0;
		}
	}
	color.assign(n, -1);
	dfs2(r, down_where[r], 0, -1);
	dfs2(down_where[r], r, 1, 1);
	cout << "Yes" << '\n';
	for(int i = 0; i < n; i++){
		cout << color[i] + 1 << ' ';
	}
	cout << '\n';
}