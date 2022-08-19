#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;

set<int> bad;

void ask(int u, int v, int w){
	cout << "? " << u + 1 << " " << v + 1 << '\n';
	cout << flush;
	int ans;
	cin >> ans;
	ans--;
	assert(ans == u || ans == v || ans == w);
	if(ans != u) bad.insert(u);
	if(ans != v) bad.insert(v);
	if(ans != w) bad.insert(w);
}

int dfs(int v, int p){
	vector<int> nc;
	for(int w : edges[v]){
		if(w == p) continue;
		int z = dfs(w, v);
		if(z != -1) nc.push_back(z);
	}
	int ret = v;
	if(nc.size() % 2 == 1){
		ret = -1;
		nc.push_back((p == -1) ? v : p);
	}
	for(int i = 0; i < (int)nc.size(); i += 2){
		ask(nc[i], nc[i+1], v);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, -1);
	assert((int)bad.size() == (n-1));
	for(int i = 0; i < n; i++){
		if(!bad.count(i)){
			cout << "! " << i + 1 << '\n';
			cout << flush;
		}
	}
}