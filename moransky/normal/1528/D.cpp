// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 605, M = N * N, INF = 0x3f3f3f3f;

int n, m, g[N][N], sf[N][N], pr[N][N];

LL d[N];

bool vis[N];

int head[N], numE = 0;

struct E{
	int next, b, c;
} e[M];

void inline add(int u, int v, int w) {
	e[++numE] = (E) { head[u], v, w };
	head[u] = numE;
}

int main() {
	memset(g, 0x3f, sizeof g);
	read(n); read(m);
	for (int i = 1, u, v, w; i <= m; i++) {
		read(u), read(v), read(w), add(u, v, w);
		g[u][v] = min(g[u][v], w - v);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pr[i][j] = sf[i][j] = g[i][j];
			if (j) pr[i][j] = min(pr[i][j], pr[i][j - 1]);
		}
		for (int j = n - 2; j >= 0; j--)
			sf[i][j] = min(sf[i][j], sf[i][j + 1]);
	}
	for (int i = 0; i < n; i++) {
		memset(d, 0x3f, sizeof d);
		memset(vis, 0, sizeof vis);
		d[i] = 0;
		for (int j = 0; j < n; j++) {
			int u = -1;
			if (j == 0) u = i;
			else {
				for (int k = 0; k < n; k++)
					if (!vis[k] && (u == -1 || d[k] < d[u])) u = k;
			}
			vis[u] = 1;
			for (int v = 0; v < n; v++) {
				if (!vis[v]) {
					int w = ((v - d[u]) % n + n) % n;
					if (pr[u][w] != INF) d[v] = min(d[v], d[u] + w + pr[u][w]);//, cout << " nmd" << u << " " << v << " " << pr[u][w] << endl; 
					if (w + 1 < n && sf[u][w + 1] != INF) d[v] = min(d[v], d[u] + w + sf[u][w + 1] + n);
					//d[v] = min(d[v], d[u] + ((v - e[k].b - d[u]) % n + n) % n + e[k].c);
				}
			}
			// for (int k = head[u]; k; k = e[k].next) {
			// 	for (int v = 0; v < n; v++) {
			// 		if (!vis[v]) {

			// 			d[v] = min(d[v], d[u] + ((v - e[k].b - d[u]) % n + n) % n + e[k].c);
			// 		}
			// 	}
			// }
		}
		for (int j = 0; j < n; j++) printf("%lld ", d[j]);
		puts("");
	}
	return 0;
}