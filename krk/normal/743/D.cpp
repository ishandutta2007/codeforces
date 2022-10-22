#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 1000000000000000000;

int n;
ll a[Maxn];
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
ll L[Maxn], R[Maxn];

void Traverse(int v, int p = 0)
{
	lef[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		a[v] += a[u];
	}
	rig[v] = cur;
	L[rig[v]] = max(L[rig[v]], a[v]);
	R[lef[v]] = max(R[lef[v]], a[v]);
	//printf("L[%d] = %lld\n", rig[v], L[rig[v]]);
	//printf("R[%d] = %lld\n", lef[v], R[lef[v]]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	fill(L, L + Maxn, -Inf); fill(R, R + Maxn, -Inf);
	Traverse(1);
	ll res = -Inf;
	for (int i = 1; i < Maxn; i++)
		L[i] = max(L[i], L[i - 1]);
	for (int i = Maxn - 2; i >= 0; i--)
		R[i] = max(R[i], R[i + 1]);
	for (int i = 0; i + 1 < Maxn; i++) if (L[i] > -Inf && R[i + 1] > -Inf)
		res = max(res, L[i] + R[i + 1]);
	if (res <= -Inf) printf("Impossible\n");
	else printf("%I64d\n", res);
	return 0;
}