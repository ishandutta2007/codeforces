#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n, q;
vector <int> neigh[Maxn];
int par[Maxn];
int cnt[Maxn], mx[Maxn]; 
int res[Maxn];

void Traverse(int v, int p = 0)
{
	cnt[v] = 1; mx[v] = 0; int bi = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		cnt[v] += cnt[u];
		if (cnt[u] > mx[v]) { mx[v] = cnt[u]; bi = u; }
	}
	if (mx[v] <= cnt[v] / 2) res[v] = v;
	else {
		res[v] = res[bi];
		while (2 * mx[res[v]] > cnt[v] || 2 * cnt[res[v]] < cnt[v])
			res[v] = par[res[v]];
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &par[i]);
		neigh[par[i]].push_back(i);
	}
	Traverse(1);
	while (q--) {
		int v; scanf("%d", &v);
		printf("%d\n", res[v]);
	}
	return 0;
}