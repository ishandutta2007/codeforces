#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int Maxn = 3005;

int n, m;
vector <int> neigh[Maxn];
int dist[Maxn][Maxn];
int s1, t1, l1;
int s2, t2, l2;
int res;

void BFS(int v, int dist[])
{
	fill(dist, dist + n + 1, Maxn); dist[v] = 0;
	queue <int> Q; Q.push(v);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (dist[v] + 1 < dist[u]) {
				dist[u] = dist[v] + 1;
				Q.push(u);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	scanf("%d %d %d", &s1, &t1, &l1);
	scanf("%d %d %d", &s2, &t2, &l2);
	for (int i = 1; i <= n; i++)
		BFS(i, dist[i]);
	res = m + 1;
	if (dist[s1][t1] <= l1 && dist[s2][t2] <= l2)
		res = min(res, dist[s1][t1] + dist[s2][t2]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int a = dist[s1][i] + dist[i][j] + dist[j][t1];
			int b = dist[s2][i] + dist[i][j] + dist[j][t2];
			if (a <= l1 && b <= l2) res = min(res, a + b - dist[i][j]);
			b = dist[t2][i] + dist[i][j] + dist[j][s2];
			if (a <= l1 && b <= l2) res = min(res, a + b - dist[i][j]);
		}
	printf("%d\n", m - res);
	return 0;
}