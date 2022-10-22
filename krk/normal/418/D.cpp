#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxk = 20;
const int Inf = 1000000000;

struct st {
	int nd;
	int val[2][Maxk];
	st(int nd = 0): nd(nd) {
		fill((int*)val, (int*)val + 2 * Maxk, -Inf);
	}
};

int n;
vector <int> neigh[Maxn];
int bot[Maxn][3], top[Maxn];
int cnt[Maxn], L[Maxn], P[Maxn];
vector <st> chains[Maxn];
int curc, cid[Maxn], cno[Maxn], cp[Maxn];
int m;

void Add(int arr[], int val)
{
	if (val > arr[0]) arr[2] = arr[1], arr[1] = arr[0], arr[0] = val;
	else if (val > arr[1]) arr[2] = arr[1], arr[1] = val;
	else if (val > arr[2]) arr[2] = val;
}

int Get(int arr[], int got)
{
	if (arr[0] == got) return arr[1];
	return arr[0];
}

int Get(int arr[], int g1, int g2)
{
	if (g1 < g2) swap(g1, g2);
	if (arr[0] == g1)
		return arr[1] == g2? arr[2]: arr[1];
	return arr[0];
}

void Traverse1(int v, int p)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse1(u, v);
		Add(bot[v], bot[u][0] + 1);
	}
}

void Traverse2(int v, int p, int add = 0)
{
	top[v] = add;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse2(u, v, max(add, Get(bot[v], bot[u][0] + 1)) + 1);
	}
}

void Traverse3(int v)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v] == u) continue;
		P[u] = v; L[u] = L[v] + 1; 
		Traverse3(u); cnt[v] += cnt[u];
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v] == u) continue;
		if (cnt[u] > cnt[v] / 2) {
			cid[v] = cid[u]; cno[v] = cno[u] + 1; cp[cid[v]] = v;
			int my = Get(bot[v], bot[u][0] + 1);
			st S(v); S.val[0][0] = my - L[v]; S.val[1][0] = my + L[v];
			chains[cid[v]].push_back(S);
			return;
		}
	}
	cid[v] = curc++; cno[v] = 0; cp[cid[v]] = v;
	st S(v); S.val[0][0] = -L[v]; S.val[1][0] = L[v];
	chains[cid[v]].push_back(S);
}

void Precompute(int c)
{
	for (int t = 0; t < 2; t++)
		for (int j = 1; j < Maxk; j++)
			for (int i = 0; i + (1 << j) <= chains[c].size(); i++)
				chains[c][i].val[t][j] = max(chains[c][i].val[t][j - 1], chains[c][i + (1 << j - 1)].val[t][j - 1]);
}

int Get(int c, int t, int l, int r)
{
	int res = -Inf;
	if (l > r) return res;
	for (int i = Maxk - 1; i >= 0; i--)
		if (l + (1 << i) <= r + 1) { res = max(res, chains[c][l].val[t][i]); l += 1 << i; }
	return res;
}

int getLCA(int a, int b)
{
	while (cid[a] != cid[b])
		if (L[cp[cid[a]]] >= L[cp[cid[b]]]) a = P[cp[cid[a]]];
		else b = P[cp[cid[b]]];
	return L[a] >= L[b]? b: a;
}

int calcDown(int a, int b, int lvl)
{
	if (a == b) return -Inf;
	int res = -Inf;
	while (cid[a] != cid[b]) {
		res = max(res, Get(cid[a], 0, cno[a] + 1, cno[cp[cid[a]]]));
		int v = cp[cid[a]];
		if (P[v] != b) res = max(res, Get(bot[P[v]], bot[v][0] + 1) - L[P[v]]);
		a = P[v];
	}
	if (a != b) res = max(res, Get(cid[a], 0, cno[a] + 1, cno[b] - 1));
	return res + lvl;
}

int calcUp(int a, int b, int bef, int lv)
{
	if (a == b) return -Inf;
	int res = Get(bot[a], bot[bef][0] + 1) + L[a];
	while (cid[a] != cid[b]) {
		res = max(res, Get(cid[a], 1, cno[a] + 1, cno[cp[cid[a]]]));
		int v = cp[cid[a]];
		if (P[v] != b) res = max(res, Get(bot[P[v]], bot[v][0] + 1) + L[P[v]]);
		a = P[v];
	}
	if (a != b) res = max(res, Get(cid[a], 1, cno[a] + 1, cno[b] - 1));
	return res - 2 * L[b] + lv;
}

int Climb(int a, int b)
{
	while (cid[a] != cid[b] && P[a] != b) {
		a = cp[cid[a]];
		if (P[a] != b) a = P[a];
	} 
	if (P[a] != b)
		return chains[cid[b]][cno[b] - 1].nd;
	return a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse1(1, 0);
	Traverse2(1, 0);
	Traverse3(1);
	for (int i = 0; i < curc; i++)
		Precompute(i);
	scanf("%d", &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		if (L[a] < L[b]) swap(a, b);

		int lca = getLCA(a, b);
		int dist = L[a] + L[b] - 2 * L[lca];
		int v = a, u;

		int toclimb = (dist - 1) / 2;
		while (L[a] - toclimb < L[cp[cid[v]]]) v = P[cp[cid[v]]]; 
		toclimb = L[v] - (L[a] - toclimb);
		v = chains[cid[v]][cno[v] + toclimb].nd;
		u = P[v];

		int res = max(bot[a][0], calcDown(a, u, L[a]));
		if (u != lca) res = max(res, Get(bot[u], bot[v][0] + 1) + L[u] - 2 * L[lca] + L[b]);
		res = max(res, calcUp(u, lca, v, L[b]));
		res = max(res, calcDown(b, lca, L[b]));
		res = max(res, top[lca] + L[b] - L[lca]);

		if (b != lca) {
			res = max(res, bot[b][0]);
			int na = Climb(a, lca), nb = Climb(b, lca);
			res = max(res, Get(bot[lca], bot[na][0] + 1, bot[nb][0] + 1) + L[b] - L[lca]);
		} else {
			int na = Climb(a, lca);
			res = max(res, Get(bot[lca], bot[na][0] + 1) + L[b] - L[lca]);
		}

		printf("%d\n", res);
	}
	return 0;
}