#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, k;
vector <int> neigh[Maxn];
int L[Maxn];
int has[Maxn];
int cnt[Maxn];
ll res;

void Traverse(int v, int p = 0)
{
	cnt[v] = has[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		L[u] = L[v] + 1;
		Traverse(u, v);
		cnt[v] += cnt[u];
	}
}

void Traverse2(int v, int p = 0, int tk = 0)
{
	int mx = has[v], bi = v;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (cnt[u] > mx) { mx = cnt[u]; bi = u; }
	}
	if (mx - tk <= cnt[v] - mx) res -= ll(cnt[v] - tk) * L[v];
	else {
		res -= 2ll * ll(cnt[v] - mx) * L[v];
		tk += cnt[v] - mx;
		Traverse2(bi, v, tk);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 2 * k; i++) {
		int v; scanf("%d", &v);
		has[v]++;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	Traverse2(1);
	for (int i = 1; i <= n; i++)
		res += ll(has[i]) * L[i];
	printf("%I64d\n", res);
	return 0;
}