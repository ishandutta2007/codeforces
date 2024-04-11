#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef long long LL;

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

const int N = 6e5 + 5;

int n, m, sz[N];

int head[N], numE = 0;

LL G, B;

struct E{
	int next, v, w;
} e[N << 1];

void inline add(int u, int v, int w) {
	e[++numE] = (E) { head[u], v, w };
	head[u] = numE;
}

void inline clear() {
	memset(head, 0, sizeof head);
	G = B = 0;
	numE = 0;
}

void dfs(int u, int fa) {
	sz[u] = 1;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa) continue;
		dfs(v, u);
		if (sz[v] & 1) G += e[i].w;
		B += min(sz[v], n - sz[v]) * (LL)e[i].w;
		sz[u] += sz[v];
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		clear();
		read(m); n = 2 * m;
		for (int i = 1, u, v, w; i < n; i++) {
			read(u); read(v); read(w);
			add(u, v, w), add(v, u, w);
		}
		dfs(1, 0);
		printf("%lld %lld\n", G, B);
	}	
	return 0;
}