#include <bits/stdc++.h>
using namespace std;

#define N 2011111

int n, node;
vector <int> E[N];
char s[N / 4];
bool ans;
int dep[N];
bool vis[2];

void dfs(int x, int fa) {
	if (E[x].size() >= 4) ans = 1;
	else if (E[x].size() == 3) {
		int tot = 0;
		for (auto v : E[x]) tot += E[v].size() > 1;
		if (tot >= 2) ans = 1;
		if (vis[dep[x]]) ans = 1;
		vis[dep[x]] = 1;
	}
	for (auto v : E[x]) if (v != fa) dep[v] = dep[x] ^ 1, dfs(v, x);
}

void work() {
	scanf("%d", &n);
	node = n;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'W') {
			E[i].push_back(++node);
			E[node].push_back(i);
			node += 2;
			E[node - 2].push_back(node - 1);
			E[node - 1].push_back(node - 2);
			E[node - 2].push_back(node);
			E[node - 0].push_back(node - 2);
		}
	}
	vis[0] = vis[1] = 0;
	ans = 0;
	dfs(1, -1);
	if (ans) puts("White");
	else puts("Draw");
	for (int i = 1; i <= node; i++) E[i].clear();
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
}