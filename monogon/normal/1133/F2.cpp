#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int n, m, D, u, v;
vector<int> adj[200000];
int parent[200000];
bool visited[200000];
set<int> parents;

int Find(int x) {
	if(parent[x] == -1) return x;
	int a = Find(parent[x]);
	parent[x] = a;
	return a;
}
void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if(A != B)
		parent[A] = B;
}

int main() {
	cin >> n >> m >> D;
	for(int i = 0; i < n; i++) {
		parent[i] = -1;
	}
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(u != 0 && v != 0) {
			Union(u, v);
		}
	}
	for(int i = 1; i < n; i++) {
		parents.insert(Find(i));
	}
	if(parents.size() > D || adj[0].size() < D) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	queue<int> q;
	visited[0] = true;
	for(int a : adj[0]) {
		auto it = parents.find(Find(a));
		if(it != parents.end()) {
			visited[a] = true;
			parents.erase(it);
			q.push(a);
			D--;
			cout << "1 " << (a + 1) << endl;
		}
	}
	for(int a : adj[0]) {
		if(!visited[a] && D > 0) {
			visited[a] = true;
			q.push(a);
			D--;
			cout << "1 " << (a + 1) << endl;
		}
	}
	while(q.size()) {
		u = q.front();
		q.pop();
		for(int a : adj[u]) {
			if(!visited[a]) {
				q.push(a);
				visited[a] = true;
				cout << (u + 1) << " " << (a + 1) << endl;
			}
		}
	}
}