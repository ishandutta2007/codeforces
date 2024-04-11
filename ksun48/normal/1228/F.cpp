#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;
vector<int> par;
vector<int> sz;

vector<bool> works;

int dfs_sz(int v, int p){
	par[v] = p;
	sz[v] = 1;
	for(int w : edges[v]){
		if(w == p) continue;
		sz[v] += dfs_sz(w, v);
	}
	return sz[v];
}

int centroid;

void dfs2(int tsz, int v, int p){
	if(sz[v] * 2 >= tsz){
		centroid = v;
	}
	for(int w : edges[v]){
		if(w == p) continue;
		dfs2(tsz, w, v);
	}
}
void find_centroid(int v){
	int sz = dfs_sz(v, -1);
	centroid = -1;
	dfs2(sz, v, -1);
	return;
}
int d;

bool check_tree(int v, int p, int level){
	vector<int> e;
	for(int x : edges[v]){
		if(x == p) continue;
		e.push_back(x);
	}
	if(level == 1){
		return e.empty();
	}
	if(e.size() != 2) return false;
	return check_tree(e[0], v, level-1) && check_tree(e[1], v, level-1);
}
void solve(int v, int p, int level){
	assert(level >= 2);
	vector<int> e;
	for(int x : edges[v]){
		if(x == p) continue;
		e.push_back(x);
	}
	if(e.size() > 3) return;
	if(level == 2 && e.size() == 1 && check_tree(e[0], v, level-1)){
		works[v] = true;
	}
	if(e.size() == 2){
		if(check_tree(e[0], v, level-1)) solve(e[1], v, level-1);
		if(check_tree(e[1], v, level-1)) solve(e[0], v, level-1);
	} else if(e.size() == 3){
		if(level == 2) return;
		for(int i = 0; i < 3; i++){
			int a = e[i];
			int b = e[(i+1)%3];
			int c = e[(i+2)%3];
			if(check_tree(a, v, level-1)
				&& check_tree(b, v, level-2)
				&& check_tree(c, v, level-2)){
				works[v] = true;
			}
		}
	} else {
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> d;
	int n = (1 << d) - 2;
	edges.resize(n);
	works.assign(n, false);
	par.assign(n, -1);
	sz.assign(n, 0);
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	find_centroid(0);
	assert(centroid >= 0);
	vector<int> c = {centroid};
	if(sz[centroid] * 2 == n){
		c.push_back(par[centroid]);
	}
	for(int x : c){
		solve(x, -1, d);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(works[i]) ans++;
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++){
		if(works[i]){
			cout << i + 1 << ' ';
		}
	}
	cout << '\n';
}