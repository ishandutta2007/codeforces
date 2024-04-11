#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 3e5 + 10;
int n;
struct Edge {
	int v,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add(int x, int y) {
	e[++cnt_e] = {y, h[x]};
	h[x] = cnt_e;
}

int d,dep[maxn],mx[maxn],f[maxn];
void dfs(int u, int pre) {
	dep[u] = dep[pre] + 1;
	mx[u] = dep[u];
	int smx = dep[u];
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre) continue;
		dfs(v, u);
		if (mx[v] > mx[u]) smx = mx[u], mx[u] = mx[v];
		else if (mx[v] > smx) smx = mx[v];
	}
	f[smx] = max(f[smx], mx[u] + smx - dep[u] * 2);
}

void work() {
	scanf("%d", &n);
	cnt_e = 0;
	for (int i = 1; i <= n; ++i) f[i] = h[i] = mx[i] = 0;
	for (int i = 1; i < n; ++i) {
		int u,v;
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	dfs(1, 0);
	d = mx[1] - 1;
	for (int i = n - 1; i >= 1; --i)
		f[i] = max(f[i], f[i + 1]);
	// for (int i = 1; i <= n; ++i) printf("%d%c", f[i], " \n"[i == n]);
	for (int i = 1, ans = 0; i <= n; ++i) {
		while (ans < d && (f[ans + 2] + 1) / 2 + i > ans) ++ans;
		printf("%d%c", ans, " \n"[i == n]);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}