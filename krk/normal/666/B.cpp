#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3005;
const int Inf = 1000000000;

int n, m;
vector <int> neigh[Maxn];
int dist[Maxn][Maxn];
ii my[Maxn][3], his[Maxn][3];
int res = -Inf;
int ba, bb, bc, bd;

void Solve(int v, int dist[])
{
	fill(dist, dist + n + 1, Inf); dist[v] = 0;
	queue <int> Q; Q.push(v);
	while (!Q.empty()) {
		v = Q.front(); Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (dist[v] + 1 < dist[u]) {
				dist[u] = dist[v] + 1;
				Q.push(u);
			}
		}
	}
}

void Insert(ii best[], ii val)
{
	if (val.first > best[0].first) best[2] = best[1], best[1] = best[0], best[0] = val;
	else if (val.first > best[1].first) best[2] = best[1], best[1] = val;
	else if (val.first > best[2].first) best[2] = val;
}

void Propose(int cand, int a, int b, int c, int d)
{
	if (cand > res) {
		res = cand;
		ba = a; bb = b; bc = c; bd = d;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		Solve(i, dist[i]);
	for (int i = 1; i <= n; i++)
		my[i][0] = my[i][1] = his[i][0] = his[i][1] = ii(-Inf, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (i != j && dist[i][j] != Inf) {
			Insert(my[i], ii(dist[i][j], j));
			Insert(his[j], ii(dist[i][j], i));
		}
	for (int i = 1; i <= n; i++) if (his[i][0].first != -Inf)
		for (int j = 1; j <= n; j++) if (i != j && dist[i][j] != Inf && my[j][0].first != -Inf)
			for (int l = 0; l < 3; l++) if (his[i][l].first != -Inf)
				for (int z = 0; z < 3; z++) if (my[j][z].first != -Inf)
					if (his[i][l].second != j && his[i][l].second != my[j][z].second && i != my[j][z].second)
						Propose(his[i][l].first + dist[i][j] + my[j][z].first, his[i][l].second, i, j, my[j][z].second);
	printf("%d %d %d %d\n", ba, bb, bc, bd);
	return 0;
}