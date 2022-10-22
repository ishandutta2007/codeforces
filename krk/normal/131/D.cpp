#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 3005;

int n;
vector <int> neigh[Maxn];
bool taken[Maxn];
int p[Maxn];
bool found;
int dist[Maxn];
queue <int> Q;

void Get(int v)
{
	taken[v] = true;
	for (int i = 0; i < neigh[v].size() && !found; i++) {
		int u = neigh[v][i];
		if (p[v] != u)
			if (!taken[u]) { p[u] = v; Get(u); }
			else {
				do {
					dist[v] = 0; Q.push(v);
					v = p[v];
				} while (v != u);
				dist[v] = 0; Q.push(v);
				found = true;
			}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	fill(dist + 1, dist + n + 1, Maxn);
	Get(1);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (dist[v] + 1 < dist[u]) dist[u] = dist[v] + 1, Q.push(u);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", dist[i], i + 1 <= n? ' ': '\n');
	return 0;
}