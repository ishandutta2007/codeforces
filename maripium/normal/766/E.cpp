#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];
vector<int> g[N];
int f[N][22][2];
long long ans = 0;

bool on(int x,int b) {
	return x >> b & 1;
}

void dfs(int u,int p) {
	for (int i = 0; i < 22; ++i) {
		f[u][i][on(a[u], i)] = 1;
	}
	for (int it = 0; it < g[u].size(); ++it) {
		int v = g[u][it];
		if (v == p) continue;
		dfs(v, u);
		for (int i = 0; i < 22; ++i) {
			int pw = 1 << i;
			ans += 1LL * pw * 1LL * f[u][i][0] * f[v][i][1];
			ans += 1LL * pw * 1LL * f[u][i][1] * f[v][i][0];
			int on = ::on(a[u], i);
			f[u][i][on] += f[v][i][0];
			f[u][i][on ^ 1] += f[v][i][1];
		}
	}
	ans += a[u];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 2; i <= n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, -1); printf("%I64d", ans);
}