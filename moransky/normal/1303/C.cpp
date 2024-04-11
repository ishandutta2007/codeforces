#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 26, S = 205;
int n, d[N], ans[N], tot;
bool g[N][N];
char s[S];
bool vis[N];
bool ok;
void dfs(int u) {
	vis[u] = true;
	ans[tot++] = u;
	for (int v = 0; v < N; v++) {
		if (g[u][v]) {
			if (vis[v]) {
				ok = false;
				return ;
			} else {
				g[u][v] = g[v][u] = false;
				dfs(v);
			}
		} 
	}
}
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(vis, false, sizeof vis);
		memset(g, false, sizeof g);
		memset(d, 0, sizeof d);
		tot = 0;
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for (int i = 1; i < n; i++) {
			if (!g[s[i] - 'a'][s[i + 1] - 'a']) {
				g[s[i] - 'a'][s[i + 1] - 'a'] = g[s[i + 1] - 'a'][s[i] - 'a'] = true;
				d[s[i] - 'a']++, d[s[i + 1] - 'a']++;
			}
		}
		ok = true;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (d[i] > 2) {
				ok = false; break;
			}
		}
		for (int i = 0; i < N; i++) {
			if (d[i] == 1 && !vis[i]) {
				dfs(i);
			}
		}
		for (int i = 0; i < N; i++)
			if (d[i] && !vis[i]) { ok = false; break; }
		if (ok) {
			puts("YES");
			for (int i = 0; i < tot; i++) putchar(ans[i] + 'a');
			for (int i = 0; i < N; i++)
				if (!vis[i]) putchar('a' + i);
			puts("");
		} else puts("NO");
	}
	return 0;
}