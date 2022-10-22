#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
bool cyc[Maxn];
int tk[Maxn];
int par[Maxn];

bool Traverse(int v, int p)
{
	if (tk[v] == 1) {
		cyc[p] = true;
		int u = p;
		do {
			u = par[u];
			cyc[u] = true;
		} while (u != v);
		return true;
	}
	if (tk[v] == 2) return false;
	tk[v] = 1;
	par[v] = p;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (Traverse(u, v)) return true;
	}
	tk[v] = 2;
	return false;
}

int Count(int v, int p)
{
	int res = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p || cyc[u]) continue;
		res += Count(u, v);
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			neigh[i].clear();
			cyc[i] = false;
			tk[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].push_back(b);
			neigh[b].push_back(a);
		}
		Traverse(1, 0);
		ll res = ll(n) * (n - 1) / 2;
		ll sum = 0;
		for (int i = 1; i <= n; i++) if (cyc[i]) {
			ll got = Count(i, 0);
			res += sum * got;
			sum += got;
		}
		printf("%I64d\n", res);
	}
    return 0;
}