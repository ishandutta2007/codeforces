#include <iostream>
#include <vector>
using namespace std;

const int N = 3 * (int)1e5;
vector<int> edges[N];
vector<bool> bridge[N];
int step[N];
int dist[N];

int dfs(int i, int p, int s) {
	// Returns smallest step-index found in the subgraph.
	if (step[i] != -1) return step[i];
	step[i] = s;

	int res = s;
	int pe = -1;
	for (int it = 0; it < edges[i].size(); ++it) {
		int t = edges[i][it];
		if (t == p) {
			pe = it;
			continue;
		}
		if (step[t] == -1) {
			int sub = dfs(t, i, s+1);
			if (sub > s) bridge[i][it] = true;
			res = std::min(res, sub);
		}
		res = std::min(res, step[t]);
	}
	if (res >= s && pe != -1) bridge[i][pe] = true;
	return res;
}

int bfs(int s) {
	std::vector<int> que;
	que.push_back(s);
	dist[s] = 0;
	int best_val = -1;
	int best_ind = -1;
	for (int j = 0; j < que.size(); ++j) {
		int i = que[j];
		if(dist[i] > best_val) {
			best_val = dist[i];
			best_ind = i;
		}
	
		for (int it = 0; it < edges[i].size(); ++it) {
			int t = edges[i][it];
			int offer = dist[i] + bridge[i][it];
			if (dist[t] == -1) {
				dist[t] = offer;
				que.push_back(t);
			}
		}
	}
	return best_ind;
}

int main() {
	// Bridge width in the graph
	// 1. For  each edge, figure out if it's a bridge
	// 2. just find the answer
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
		bridge[a].push_back(false);
		bridge[b].push_back(false);
	}
	for (int i = 0; i < n; ++i) step[i] = -1;
	dfs(0, 0, 0);
	for (int i = 0; i < n; ++i) dist[i] = -1;
	int s = bfs(0);
	for (int i = 0; i < n; ++i) dist[i] = -1;
	int e = bfs(s);

	cout << dist[e] << '\n';
}