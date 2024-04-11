
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, u, v;
vector<int> adj[200000];
bool visited[200000];

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	unsigned int maxdeg = 0;
	int vert = 0;
	for(int i = 0; i < n; i++) {
		if(adj[i].size() >= maxdeg) {
			maxdeg = adj[i].size();
			vert = i;
		}
	}
	queue<int> q;
	q.push(vert);
	visited[vert] = true;
	while(q.size()) {
		vert = q.front();
		q.pop();
		for(int a : adj[vert]) {
			if(!visited[a]) {
				q.push(a);
				visited[a] = true;
				cout << (vert + 1) << " " << (a + 1) << endl;
			}
		}
	}
}