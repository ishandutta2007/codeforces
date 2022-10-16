#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105, M = 5005;

int n, m;

int head[N], numE = 0;

int f[N][N][26];

struct E{
	int next, v, w;
} e[M];

inline void add(int u, int v, int w) {
	e[++numE] = (E) { head[u], v, w };
	head[u] = numE;
}

int dp(int x, int y, int k) {
	if (f[x][y][k] != -1) return f[x][y][k];
	int &w = f[x][y][k] = 0;
	for (int i = head[x]; i; i = e[i].next) {
		int v = e[i].v;
		if (e[i].w >= k && !dp(y, v, e[i].w)) return w = 1;
	}
	return w;
}

int main() {
	memset(f, -1, sizeof f);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		char c[2]; scanf("%d%d%s", &u, &v, c);
		add(u, v, c[0] - 'a');
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			printf(dp(i, j, 0) ? "A" : "B");
		puts("");
	}
}