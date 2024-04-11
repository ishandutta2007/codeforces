#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;
const int Inf = 1000000000;
const int Maxn = 100005;
const int Maxm = 20;

int n, m;
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
vector <int> reds;
int dist[Maxn];
vector <int> gotored;

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] == u) continue;
		L[u] = L[v] + 1; P[u][0] = v;
		Traverse(u);
	}
}

int LCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i]) a = P[a][i], b = P[b][i];
	return P[a][0];
}

void BFS()
{
	fill(dist + 1, dist + n + 1, Inf);
	queue <int> Q;
	for (int i = 0; i < reds.size(); i++) {
		dist[reds[i]] = 0; Q.push(reds[i]);
	}
	while (!Q.empty()) {
		int v = Q.front(), d = dist[v]; Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (d + 1 < dist[u]) { dist[u] = d + 1; Q.push(u); }
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	reds.push_back(1);
	int part = int(sqrt(double(m)) + 0.5);
	for (int i = 0; i < m; i += part) {
		BFS();
		gotored.clear();
		for (int j = i; j < i + part && j < m; j++) {
			int a, b; scanf("%d %d", &a, &b);
			if (a == 1) gotored.push_back(b);
			else {
				int res = dist[b];
				for (int j = 0; j < gotored.size(); j++) {
					int c = gotored[j];
					int lca = LCA(b, c);
					res = min(res, L[b] - L[lca] + L[c] - L[lca]);
				}
				printf("%d\n", res);
			}
		}
		for (int j = 0; j < gotored.size(); j++)
			reds.push_back(gotored[j]);
	}
	return 0;
}