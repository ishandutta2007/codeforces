#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n, k;
int a[Maxn];
vector <int> neigh[Maxn];
int cnt[Maxn];
int best[Maxn][2];
int acc[Maxn];
int X;
int res;

void insertBest(int v, int val)
{
	if (val > best[v][0]) best[v][1] = best[v][0], best[v][0] = val;
	else if (val > best[v][1]) best[v][1] = val;
}

int getBest(int v, int val)
{
	return best[v][0] == val? best[v][1]: best[v][0];
}

void countTraverse(int v, int p = 0)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		countTraverse(u, v);
		cnt[v] += cnt[u];
	}
}

void Traverse1(int v, int p = 0)
{
	best[v][0] = best[v][1] = 0; acc[v] = a[v] >= X;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse1(u, v);
	}
	if (acc[v])
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (u == p) continue;
			if (cnt[u] == acc[u] + best[u][0]) acc[v] += cnt[u];
			else insertBest(v, acc[u] + best[u][0]);
		}
}

void Traverse2(int v, int p, int ACC, int BEST)
{
	int cacc = acc[v];
	int cbest = best[v][0];
	int got = ACC + BEST;
	if (n - cnt[v] == got) { cacc += n - cnt[v]; got = 0; }
	else cbest = max(cbest, got);
	if (a[v] >= X) res = max(res, cacc + cbest);
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		if (a[v] >= X) {
			int nacc = cacc, nbest = cbest;
			if (cnt[u] == acc[u] + best[u][0]) nacc -= cnt[u];
			else nbest = max(getBest(v, acc[u] + best[u][0]), got);
			Traverse2(u, v, nacc, nbest);
		} else Traverse2(u, v, 0, 0);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	countTraverse(1);
	int l = 0, r = 1000000;
	int ans;
	while (l <= r) {
		X = l + r >> 1; res = 0;
		Traverse1(1);
		Traverse2(1, 0, 0, 0);
		if (res >= k) { ans = X; l = X + 1; }
		else r = X - 1;
	}
	printf("%d\n", ans);
	return 0;
}