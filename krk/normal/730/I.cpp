#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3015;
const int Inf = 1000000000;

int n, p, s;
int a[Maxn], mxa;
int b[Maxn], mxb;
int N;
vector <int> neigh[Maxn];
int R[Maxn][Maxn], C[Maxn][Maxn];
int dist[Maxn], par[Maxn];
vector <int> res[2];

int addEdge(int a, int b, int cap, int cost)
{
	neigh[a].push_back(b); neigh[b].push_back(a);
	R[a][b] = cap; R[b][a] = 0;
	C[a][b] = cost; C[b][a] = -cost;
}

bool getFlow(int &add)
{
	fill(dist, dist + N, Inf); dist[0] = 0;
	priority_queue <ii> Q; Q.push(ii(-dist[0], 0));
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (R[v][u] && d + C[v][u] < dist[u]) {
				dist[u] = d + C[v][u]; par[u] = v;
				Q.push(ii(-dist[u], u));
			}
		}
	}
	int v = N - 1;
	add = dist[v];
	if (add >= Inf) return false;
	while (v) {
		int u = par[v];
		R[u][v]--; R[v][u]++;
		v = u;
	}
	return true;
}

int main()
{
	scanf("%d %d %d", &n, &p, &s); N = 1 + n + 2 + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mxa = max(mxa, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		mxb = max(mxb, b[i]);
	}
	for (int i = 1; i <= n; i++) {
		addEdge(0, i, 1, 0);
		addEdge(i, N - 3, 1, mxa - a[i]);
		addEdge(i, N - 2, 1, mxb - b[i]);
	}
	addEdge(N - 3, N - 1, p, 0);
	addEdge(N - 2, N - 1, s, 0);
	int tot = 0, add;
	while (getFlow(add)) tot += add;
	for (int i = 1; i <= n; i++)
		if (R[N - 3][i] > 0) res[0].push_back(i);
		else if (R[N - 2][i] > 0) res[1].push_back(i);
	printf("%d\n", p * mxa + s * mxb - tot);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < res[i].size(); j++)
			printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
	return 0;
}