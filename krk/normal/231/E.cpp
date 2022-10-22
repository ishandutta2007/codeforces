#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

const int mod = 1000000007;
const int Maxn = 100005;
const int Maxm = 20;

int pw2[Maxn];
int n, m;
vector <int> neigh[Maxn];
int st[Maxn], cyc[Maxn], dif[Maxn];
int L[Maxn], P[Maxn][Maxm];
int k;

void getCycles(int v)
{
	st[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (st[u] == 0) { P[u][0] = v; getCycles(u); }
		else if (st[u] == 1 && u != P[v][0]) {
			dif[u]++;
			cyc[u] = 1; int t = v;
			while (t != u) { cyc[t] = 1; t = P[t][0]; }
		}
	}
	st[v] = 2;
}

void Traverse(int v)
{
	st[v] = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (st[u] == 2) { dif[u] += dif[v]; L[u] = L[v] + 1; P[u][0] = v; Traverse(u); }
	}
}

int getSt(int v, int u)
{
	int res = dif[v] + dif[u];
	if (L[v] < L[u]) swap(v, u);
	int log = 0;
	while (1 << log <= L[v]) log++;
	log--;
	for (int i = log; i >= 0; i--)
		if (L[v] - (1 << i) >= L[u])
			v = P[v][i];
	int lca;
	if (v == u) lca = v;
	else {
		for (int i = log; i >= 0; i--)
			if (P[v][i] != P[u][i])
				v = P[v][i], u = P[u][i];
		lca = P[v][0];
	}
	return res - 2 * dif[lca] + cyc[lca];
}

int main()
{
	pw2[0] = 1;
	for (int i = 1; i < Maxn; i++) pw2[i] = 2 * pw2[i - 1] % mod;
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	getCycles(1); Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	scanf("%d", &k);
	while (k--) {
		int x, y; scanf("%d %d", &x, &y);
		printf("%d\n", pw2[getSt(x, y)]);
	}
	return 0;
}