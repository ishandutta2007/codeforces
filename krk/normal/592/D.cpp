#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200000;
const int Inf = 1000000000;

int n, m;
vector <int> neigh[Maxn];
int was[Maxn];
int dp[Maxn];
int best[Maxn][2];
int res = Inf, bind;

void Insert(int best[], int val)
{
	if (val < best[0]) best[1] = best[0], best[0] = val;
	else if (val < best[1]) best[1] = val;
}

int Get(int best[], int val)
{
	if (best[0] == val) return best[1];
	return best[0];
}

void Traverse(int v, int p = 0)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		 int u = neigh[v][i];
		 if (u == p) continue;
		 Traverse(u, v);
		 was[v] += was[u];
		 if (was[u]) {
		 	dp[v] += 2 + dp[u];
		 	Insert(best[v], best[u][0] - 1);
		 }
	}
}

void Solve(int v, int p = 0, int add = 0, int bes = 0, int w = 0)
{
	int cand = dp[v] + add + min(best[v][0], bes);
	if (cand < res || cand == res && v < bind) { res = cand; bind = v; }
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || !was[u]) continue;
		int nadd = add + dp[v] - dp[u];
		int nbes = min(bes, Get(best[v], best[u][0] - 1)) - 1;
		int nw = w + was[v] - was[u];
		if (!nw) nadd = 0, nbes = 0;
		Solve(u, v, nadd, nbes, nw);
	} 
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	while (m--) {
		int v; scanf("%d", &v);
		was[v] = 1;
	}
	Traverse(1);
	Solve(1);
	printf("%d\n", bind);
	printf("%d\n", res);
	return 0;
}