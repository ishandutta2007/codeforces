#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Inf = 1000000000;
const int Maxn = 405;

int h, t, R;
int n, h1[Maxn], t1[Maxn];
int m, h2[Maxn], t2[Maxn];
vector <ii> neigh[Maxn][Maxn], rneigh[Maxn][Maxn];
int res1[Maxn][Maxn], res2[Maxn][Maxn];
int taken[Maxn][Maxn];
bool added[Maxn][Maxn];
vector <ii> V;

void Dijkstra()
{
	fill((int*)res2, (int*)res2 + Maxn * Maxn, Inf); res1[0][0] = 1; res2[0][0] = 0;
	priority_queue <iii> Q; Q.push(iii(0, ii(0, 0)));
	while (!Q.empty()) {
		ii v = Q.top().second; int d = -Q.top().first; Q.pop();
		if (res2[v.first][v.second] != d) continue;
		res1[v.first][v.second] = 1;
		for (int i = 0; i < neigh[v.first][v.second].size(); i++) {
			ii u = neigh[v.first][v.second][i];
			if (d + 1 < res2[u.first][u.second]) { res2[u.first][u.second] = d + 1; Q.push(iii(-(d + 1), u)); }
		}
	}
}

void DFS(int i, int j)
{
	if (res1[i][j] == 1 || taken[i][j] == 2) return;
	if (taken[i][j] == 1) {
		if (!added[i][j]) { V.push_back(ii(i, j)); added[i][j] = true; }
		return;
	}
	taken[i][j] = 1;
	for (int k = 0; k < neigh[i][j].size(); k++) {
		ii u = neigh[i][j][k]; DFS(u.first, u.second);
	}
	taken[i][j] = 2;
}

void BFS()
{
	for (int i = 0; i < V.size(); i++) {
		ii v = V[i]; res1[v.first][v.second] = 0;
		for (int j = 0; j < neigh[v.first][v.second].size(); j++) {
			ii u = neigh[v.first][v.second][j];
			if (res1[u.first][u.second] == -2 && !added[u.first][u.second]) { V.push_back(u); added[u.first][u.second] = true; }
		}
	}
}

int Get(int i, int j)
{
	if (i + j > R) return 0;
	if (!added[i][j]) {
		res2[i][j] = 0;
		for (int k = 0; k < rneigh[i][j].size(); k++) {
			ii u = rneigh[i][j][k]; res2[i][j] = max(res2[i][j], Get(u.first, u.second) + 1);
		}
		added[i][j] = true;
	}
	return res2[i][j];
}

int main()
{
	scanf("%d %d %d", &h, &t, &R);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &h1[i], &t1[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &h2[i], &t2[i]);
	for (int i = 0; i <= R; i++)
		for (int j = 0; i + j <= R; j++) {
			for (int k = 1; k <= n && k <= i; k++) {
				neigh[i - k + h1[k]][j + t1[k]].push_back(ii(i, j));
				rneigh[i][j].push_back(ii(i - k + h1[k], j + t1[k]));
			}
			for (int k = 1; k <= m && k <= j; k++) {
				neigh[i + h2[k]][j - k + t2[k]].push_back(ii(i, j));
				rneigh[i][j].push_back(ii(i + h2[k], j - k + t2[k]));
			}
		}
	fill((int*)res1, (int*)res1 + Maxn * Maxn, -2);
	Dijkstra();
	for (int i = 0; i < Maxn; i++)
		for (int j = 0; j < Maxn; j++)
			if (res1[i][j] == -2 && !taken[i][j])
				DFS(i, j);
	BFS();
	fill((bool*)added, (bool*)added + Maxn * Maxn, false);
	for (int i = 0; i < Maxn; i++)
		for (int j = 0; j < Maxn; j++) 
			if (res1[i][j] == -2) { res1[i][j] = -1; Get(i, j); }
	if (res1[h][t] == 1) printf("Ivan\n%d\n", res2[h][t]);
	else if (res1[h][t] == 0) printf("Draw\n");
	else printf("Zmey\n%d\n", res2[h][t]);
	return 0;
}