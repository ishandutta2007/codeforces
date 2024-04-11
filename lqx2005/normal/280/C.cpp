#include <bits/stdc++.h>
#define db double

using namespace std;
const int N = 1e5 + 10;
int n, dep[N];
vector<int> g[N];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for(int &v : g[u]) if(v != fa) dfs(v, u);
	return;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	db ans = 0;
	for(int i = 1; i <= n; i++) {
		db c = n - dep[i];
		c = c / n;
		ans += 1 / (1 - c) / n;
	}
	printf("%.10lf\n", ans);
	return 0;
}