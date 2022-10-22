#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Inf = 1000000000;

int T;
int n, m;
vector <int> neigh[Maxn], rneigh[Maxn];
int D[Maxn], dist[Maxn];

void BFS()
{
	fill(D, D + n + 1, Inf); D[1] = 0;
	vector <int> Q; Q.push_back(1);
	for (int i = 0; i < Q.size(); i++) {
		int v = Q[i];
		for (int j = 0; j < neigh[v].size(); j++) {
			int u = neigh[v][j];
			if (D[v] + 1 < D[u]) {
				D[u] = D[v] + 1;
				Q.push_back(u);
			}
		}
	}
}

void Dijkstra()
{
	priority_queue <ii> Q;
	for (int i = 1; i <= n; i++) {
		dist[i] = D[i];
		for (int j = 0; j < neigh[i].size(); j++) {
			int u = neigh[i][j];
			dist[i] = min(dist[i], D[u]);
		}
		Q.push(ii(-dist[i], i));
	}
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		for (int i = 0; i < rneigh[v].size(); i++) {
			int u = rneigh[v][i];
			if (D[v] > D[u] && d < dist[u]) {
				dist[u] = d;
				Q.push(ii(-dist[u], u));
			}
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			neigh[i].clear();
			rneigh[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].push_back(b);
			rneigh[b].push_back(a);
		}
		BFS();
		Dijkstra();
		for (int i = 1; i <= n; i++)
			printf("%d%c", dist[i], i + 1 <= n? ' ': '\n');
	}
    return 0;
}