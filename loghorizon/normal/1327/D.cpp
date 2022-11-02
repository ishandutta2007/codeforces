#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200005;

int n, p[N], c[N], a[N], b[N], d[N], ans = n, tot;

bool vis[N];
void dfs(int u) {
	b[++tot] = u;
	vis[u] = true;
	if (!vis[p[u]]) dfs(p[u]);
}

bool judge(int l, int r, int k) {
	for (int i = l; i <= r; i += k)
		if (c[b[i]] != c[b[l]]) return false;
	return true;
}

bool inline check(int x) {
	for (int i = 1; i <= x; i++) {
		if (judge(i, tot, x)) return true;
	}
	return false;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = n;
		for (int i = 1; i <= n; i++) scanf("%d", p + i), a[i] = p[i], vis[i] = false;
		for (int i = 1; i <= n; i++) scanf("%d", c + i);
		for (int i = 1; i <= n; i++) {
			if (p[i] == i) {
				ans = 1;
				break;
			}
			if (!vis[i]) {
				tot = 0;
				dfs(i);
				for (int d = 1; d * d <= tot; d++) {
					if (tot % d == 0) {
						if (check(d)) {
							ans = min(ans, d);
						}
						if (d != tot / d && check(tot / d)) {
							ans = min(ans, tot / d);
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}