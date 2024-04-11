#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 100005;
const int Maxm = 20;

int n, m;
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
ll cnt[Maxn], dsum[Maxn];
ll totcnt[Maxn], totdsum[Maxn];

void Traverse(int v)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] == u) continue;
		P[u][0] = v; L[u] = L[v] + 1;
		Traverse(u);
		cnt[v] += cnt[u]; dsum[v] += dsum[u] + cnt[u];
	}
}

void Traverse2(int v, ll parcnt, ll pardsum) 
{
	totcnt[v] = cnt[v] + parcnt; totdsum[v] = dsum[v] + pardsum;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] == u) continue;
		ll newparcnt = parcnt + cnt[v] - cnt[u];
		ll newpardsum = pardsum + dsum[v] - dsum[u] - cnt[u] + newparcnt;
		Traverse2(u, newparcnt, newpardsum);
	}
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i]) a = P[a][i], b = P[b][i];
	return P[a][0];
}

int goUp(int a, int b)
{
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) > L[b]) a = P[a][i];
	return a;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	Traverse2(1, 0, 0);
	while (m--) {
		int u, v; scanf("%d %d", &u, &v);
		int lca = getLCA(u, v);
		ll ucnt, udsum;
		if (lca != u) {
			ucnt = cnt[u], udsum = dsum[u];
		} else {
			int lst = goUp(v, u);
			ucnt = totcnt[u] - cnt[lst], udsum = totdsum[u] - dsum[lst] - cnt[lst];
		}
		ll vcnt, vdsum;
		if (lca != v) {
			vcnt = cnt[v], vdsum = dsum[v];
		} else {
			int lst = goUp(u, v);
			vcnt = totcnt[v] - cnt[lst], vdsum = totdsum[v] - dsum[lst] - cnt[lst];
		}
		ld res = ld(udsum) / ld(ucnt) + ld(vdsum) / ld(vcnt) + 1.0l + ld(L[u]) + ld(L[v]) - ld(2 * L[lca]);
		printf("%.10lf\n", double(res));
	}
	return 0;
}