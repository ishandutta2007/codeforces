#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Inf = 1000000000;
const int Maxn = 100005;

int n, m, d;
vector <int> neigh[Maxn];
bool spec[Maxn];
int h[Maxn][2];
int res;

void Traverse(int v, int p)
{
	h[v][0] = h[v][1] = -Inf;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v); int cand = h[u][0] + 1;
		if (cand > h[v][0]) h[v][1] = h[v][0], h[v][0] = cand;
		else if (h[u][0] > h[v][1]) h[v][1] = cand;
	}
	if (spec[v]) {
		if (h[v][0] < 0) h[v][0] = 0;
		if (h[v][1] < 0) h[v][1] = 0;
	}
}

void Calc(int v, int p, int ft)
{
	if (max(h[v][0], ft) <= d) res++;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (h[v][0] == h[u][0] + 1) Calc(u, v, max(ft, h[v][1]) + 1);
		else Calc(u, v, max(ft, h[v][0]) + 1);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &d);
	while (m--) {
		int s; scanf("%d", &s);
		spec[s] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	Traverse(1, 0);
	Calc(1, 0, -Inf);
	printf("%d\n", res);
	return 0;
}