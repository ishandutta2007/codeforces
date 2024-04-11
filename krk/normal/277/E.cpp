#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <ld, int> di;

const ld Inf = 1e30l;
const int Maxn = 805;
const ld eps = 1e-10l;

int n;
int x[Maxn], y[Maxn];
int N;
int R[Maxn][Maxn];
ld C[Maxn][Maxn];
vector <int> neigh[Maxn];
ld dist[Maxn];
bool flow[Maxn];
int par[Maxn];
int mf;
ld tc;

bool getFlow(ld &cost)
{
	fill(dist, dist + N, Inf); dist[0] = 0.0l;
	fill(flow, flow + N, false); flow[0] = true;
	priority_queue <di> Q; Q.push(di(-dist[0], 0));
	while (!Q.empty()) {
		int v = Q.top().second; ld d = -Q.top().first; Q.pop();
		if (d > dist[v] + eps) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (R[v][u] && d + C[v][u] + eps < dist[u]) {
				dist[u] = d + C[v][u]; flow[u] = true; par[u] = v;
				Q.push(di(-dist[u], u));
			}
		}
	}
	if (!flow[N - 1]) return false;
	cost = dist[N - 1];
	int v = N - 1;
	while (v) {
		int u = par[v];
		R[u][v]--; R[v][u]++;
		v = u;
	}
	return true;
}

ld Len(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

int main()
{
	scanf("%d", &n); N = 2 + 2 * n;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		R[0][i] = 1; neigh[0].push_back(i); neigh[i].push_back(0);
		R[n + i][N - 1] = 2; neigh[n + i].push_back(N - 1); neigh[N - 1].push_back(n + i);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (y[i] < y[j]) {
			R[i][n + j] = 1; C[i][n + j] = Len(x[i] - x[j], y[i] - y[j]); C[n + j][i] = -C[i][n + j];
			neigh[i].push_back(n + j); neigh[n + j].push_back(i);
		}
	ld cost;
	while (getFlow(cost)) { mf++; tc += cost; }
	if (mf < n - 1) printf("-1\n");
	else cout << fixed << setprecision(15) << tc << endl;
	return 0;
}