/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;

#define MAXN 300005

struct edge {
	int next, to;
} e[MAXN * 2];

int head[MAXN], ecnt = 1;

void add(int u, int v) {
	e[++ecnt] = (edge) {head[u], v}; head[u] = ecnt;
	e[++ecnt] = (edge) {head[v], u}; head[v] = ecnt;
}

int n, m, s[MAXN], rt[MAXN], ans = 1;
int vis[MAXN];

vector <int> a[MAXN], b[MAXN];

struct Node {
	int l, r, v;
} t[MAXN * 64];

int tcnt = 0;

void update(int &x, int l, int r, int p) {
	if (!x) x = ++tcnt;
	t[x].v++;
	if (l < r) {
		int mid = (l + r) >> 1;
		if (p <= mid) update(t[x].l, l, mid, p);
		else update(t[x].r, mid + 1, r, p);
	}
}

int query(int x, int l, int r) {
	if (!x) return l;
	int mid = (l + r) >> 1;
	if (t[x].l && t[t[x].l].v == mid - l + 1) return query(t[x].r, mid + 1, r);
	else return query(t[x].l, l, mid);
}

void dfs(int x, int from) {
	for (int i = 0; i < s[x]; i++) {
		int to = a[x][i];
		if (!vis[to]) {
			ans = max(ans, vis[to] = query(rt[x], 1, m));
			for (int j = 0; j < b[to].size(); j++) update(rt[b[to][j]], 1, m, vis[to]); 
		}
	}
	for (int now = head[x]; now; now = e[now].next) {
		if (e[now].to != from) dfs(e[now].to, x);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", s + i);
		for (int j = 0, x; j < s[i]; j++) {
			scanf("%d", &x);
			a[i].push_back(x);
			b[x].push_back(i);
		}
	}
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	dfs(1, -1);
	printf("%d\n", ans);
	for (int i = 1; i <= m; i++) printf("%d ", max(vis[i], 1));
	return 0;
}