#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Inf = 1000000000;
const int Maxn = 505;
const int Maxm = 10005;

int n, m;
vector <int> neigh[Maxn];
int dist[Maxn][Maxn][2];
int par[Maxn][Maxn][2];
int a[Maxn * Maxn], b[Maxn * Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	fill((int*)dist, (int*)dist + Maxn * Maxn * 2, Inf); dist[1][n][0] = 0;
	queue <iii> Q; Q.push(iii(ii(1, n), 0));
	while (!Q.empty()) {
		iii v = Q.front(); int d = dist[v.first.first][v.first.second][v.second]; Q.pop();
		if (v.second == 0)
			for (int i = 0; i < neigh[v.first.first].size(); i++) {
				int u = neigh[v.first.first][i];
				if (d < dist[u][v.first.second][1]) {
					dist[u][v.first.second][1] = d;
					par[u][v.first.second][1] = v.first.first;
					Q.push(iii(ii(u, v.first.second), 1));
				}
			}
		else for (int i = 0; i < neigh[v.first.second].size(); i++) {
				int u = neigh[v.first.second][i];
				if (v.first.first != u && d + 1 < dist[v.first.first][u][0]) {
					dist[v.first.first][u][0] = d + 1;
					par[v.first.first][u][0] = v.first.second;
					Q.push(iii(ii(v.first.first, u), 0));
				}
			}
	}
	if (dist[n][1][0] == Inf) printf("-1\n");
	else {
		printf("%d\n", dist[n][1][0]);
		iii v = iii(ii(n, 1), 0);
		for (int i = dist[n][1][0]; i >= 0; i--) {
			b[i] = v.first.second;
			v = iii(ii(v.first.first, par[v.first.first][v.first.second][v.second]), 1);
			a[i] = v.first.first;
			v = iii(ii(par[v.first.first][v.first.second][v.second], v.first.second), 0);
		}
		for (int i = 0; i <= dist[n][1][0]; i++)
			printf("%d%c", a[i], i + 1 <= dist[n][1][0]? ' ': '\n');
		for (int i = 0; i <= dist[n][1][0]; i++)
			printf("%d%c", b[i], i + 1 <= dist[n][1][0]? ' ': '\n');
	}
	return 0;
}