#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxm = 205;

int n, m;
int N;
int R[Maxm][Maxm];
vector <int> neigh[Maxm];
int flow[Maxm], par[Maxm];
int res;

int getFlow()
{
	fill(flow, flow + N, 0); flow[0] = Inf;
	priority_queue <ii> Q; Q.push(ii(Inf, 0));
	while (!Q.empty()) {
		int v = Q.top().second, f = Q.top().first; Q.pop();
		if (f != flow[v]) continue;
		if (v == N - 1) break;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (min(f, R[v][u]) > flow[u]) {
				flow[u] = min(f, R[v][u]); par[u] = v;
				Q.push(ii(flow[u], u));
			}
		}
	}
	int v = N - 1;
	int res = flow[v];
	if (!res) return 0;
	while (v) {
		int u = par[v];
		R[u][v] -= res; R[v][u] += res;
		v = u;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m); N = 2 * m + 2;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		R[0][a]++; R[m + a][N - 1]++;
	}
	for (int i = 1; i <= m; i++) {
		neigh[0].push_back(i); neigh[i].push_back(0);
		neigh[m + i].push_back(N - 1); neigh[N - 1].push_back(m + i);
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++) if (i != j) {
			neigh[i].push_back(m + j); neigh[m + j].push_back(i);
			R[i][m + j] = Inf;
		}
	int f;
	while ((f = getFlow()) != 0)
		res += f;
	printf("%d\n", res);
	for (int i = 1; i <= m; i++)
		while (R[0][i]--) printf("%d %d\n", i, i);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			while (R[m + j][i]--) printf("%d %d\n", i, j);
	return 0;
}