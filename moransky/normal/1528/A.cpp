// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;

#define pb push_back

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n, L[N], R[N];

LL f[N][2];

vector<int> g[N];

void dfs(int u, int fa) {
	f[u][1] = 0, f[u][0] = 0;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		f[u][1] += max(f[v][1] + abs(R[v] - R[u]), f[v][0] + abs(L[v] - R[u]));
		f[u][0] += max(f[v][1] + abs(R[v] - L[u]), f[v][0] + abs(L[v] - L[u]));
	} 
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) read(L[i]), read(R[i]);
		for (int i = 1, u, v; i < n; i++){
			scanf("%d%d", &u, &v); 
			g[u].pb(v), g[v].pb(u);
		}
		dfs(1, 0);
		printf("%lld\n", max(f[1][0], f[1][1]));
		for (int i = 1; i <= n; i++) g[i].clear();
	}
	return 0;
}