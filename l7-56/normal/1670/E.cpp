#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int n, p, ansn[maxn], anse[maxn], tot;
struct Edge {
	int v, id, nxt;
} e[maxn << 1];
int h[maxn], cnt_e;
void add(int x, int i, int y) { e[++cnt_e] = {y, i, h[x]}, h[x] = cnt_e; }

void dfs(int u, int pre, int col) {
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v, i = e[j].id;
		if (v == pre) continue;
		anse[i] = ++tot, ansn[v] = n ^ tot;
		if (col) swap(anse[i], ansn[v]);
		dfs(v, u, col ^ 1);
	}
}

void work() {
	scanf("%d", &p), n = 1 << p;
	cnt_e = 0;
	for (int i = 1; i <= n; ++i) h[i] = 0;
	for (int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		add(x, i, y), add(y, i, x);
	}
	tot = 0, ansn[1] = n, dfs(1, 0, 1);
	printf("1\n");
	for (int i = 1; i <= n; ++i) printf("%d%c", ansn[i], " \n"[i == n]);
	for (int i = 1; i < n; ++i) printf("%d%c", anse[i], " \n"[i == n - 1]);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}