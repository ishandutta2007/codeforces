
#include <iostream>
#include <set>

using namespace std;

int n, m, u, v;
set<int> adj[200000];
bool col[200000];
bool visited[200000];
int e[200000];

bool bipartite(int idx, bool c) {
	visited[idx] = true;
	col[idx] = c;
	for(int i : adj[idx]) {
		if(!visited[i]) {
			if(!bipartite(i, !c)) {
				return false;
			}
		}else if(col[i] == c) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		e[i] = u - 1;
		adj[u - 1].insert(v - 1);
		adj[v - 1].insert(u - 1);
	}
	if(bipartite(0, 0)) {
		cout << "YES" << endl;
		for(int i = 0; i < m; i++) {
			cout << col[e[i]];
		}
	}else {
		cout << "NO" << endl;
	}
}