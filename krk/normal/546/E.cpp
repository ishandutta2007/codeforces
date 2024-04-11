#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;
const int Inf = 1000000000;

int n, m;
vector <int> neigh[Maxn];
int R[Maxn][Maxn];
int suma, sumb;
int res;
int flow[Maxn], par[Maxn];

void Add(int a, int b, int c)
{
	R[a][b] = c;
	neigh[a].push_back(b); neigh[b].push_back(a);
}

int getFlow()
{
	fill(flow, flow + Maxn, 0); flow[0] = Inf;
	priority_queue <ii> Q; Q.push(ii(flow[0], 0));
	while (!Q.empty()) {
		int f = Q.top().first, v = Q.top().second; Q.pop();
		if (f != flow[v]) continue;
		if (v == Maxn - 1) break;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (min(f, R[v][u]) > flow[u]) {
				flow[u] = min(f, R[v][u]); par[u] = v;
				Q.push(ii(flow[u], u));
			}
		}
	}
	int v = Maxn - 1;
	int res = flow[v];
	if (res == 0) return 0;
	while (v) {
		int u = par[v];
		R[u][v] -= res; R[v][u] += res;
		v = u;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a); suma += a;
		Add(0, i, a);
		Add(i, n + i, Inf);
	}
	for (int i = 1; i <= n; i++) {
		int b; scanf("%d", &b); sumb += b;
		Add(n + i, Maxn - 1, b);
	}
	if (suma != sumb) { printf("NO\n"); return 0; }
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		Add(a, n + b, Inf);
		Add(b, n + a, Inf);
	}
	int f;
	while ((f = getFlow()) != 0)
		res += f;
	if (res == suma) {
		printf("YES\n");
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				int num;
				if (R[i][n + j] == 0 && R[n + j][i] == 0 || R[i][n + j] >= Inf) num = 0;
				else num = Inf - R[i][n + j];
				printf("%d%c", num, j + 1 <= n? ' ': '\n');
			}
	} else printf("NO\n");
	return 0;
}