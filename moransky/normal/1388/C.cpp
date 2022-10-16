#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 100005;

int n, m, p[N], h[N], sz[N];

int head[N], numE = 0;
bool ok = true;

struct E{
	int next, v;
} e[N << 1];

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

void inline clear() {
	memset(head, 0, sizeof head);
	numE = 0;
	ok = true;
	memset(sz, 0, sizeof sz);
}

void dfs(int u, int last) {
	sz[u] = p[u];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == last) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

void dfs2(int u, int last, int g, int b) {
	if (g < 0 || b < 0) {
		ok = false;
		return;
	}
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == last) continue;
		if ((sz[v] - h[v]) < 0 || ((sz[v] - h[v]) % 2 == 1)) {
			ok = false;
			return;
		}
		int bv = (sz[v] - h[v]) / 2, gv = bv + h[v];
		if (gv < 0 || bv < 0) {
			ok = false;
			return;
		}
		if (b < bv) {
			int k = bv - b;
			if (g - k < 0) {
				ok = false;
				return;
			}
			g -= k, b += k;
		}
		if (g < gv) {
			ok = false;
			return;
		}
		g -= gv, b -= bv;
		dfs2(v, u, gv, bv);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", p + i);
		for (int i = 1; i <= n; i++) scanf("%d", h + i);
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v);
			add(u, v); add(v, u);
		}
		dfs(1, 0);
		if ((m - h[1]) < 0 || ((m - h[1]) % 2 == 1)) {
			ok = false;
		} else {
			dfs2(1, 0, (m - h[1]) / 2 + h[1], (m - h[1]) / 2);
		}
		puts(ok ? "YES" : "NO");
	}	
	return 0;
}