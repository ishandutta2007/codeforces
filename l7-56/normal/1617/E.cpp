#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 2e5 + 10, maxt = 1e7 + 10;
int a[maxn], n, tot = 1, dep[maxt], ed[maxt];
unordered_map <int, int> Id;
vector <int> son[maxt];

void ins(int u, int nw) {
	int k = 0;
	while ((1 << k) < nw) ++k;
	int nxt = (1 << k) - nw;
	auto it = Id.find(nxt);
	if (it != Id.end()) {
		son[it -> second].push_back(u);
		return;
	}
	Id[nxt] = ++tot;
	son[tot].push_back(u);
	ins(tot, nxt);
}

int f[maxt], num[maxt], ans, anx, any;
void dfs(int u) {
	f[u] = 0xafafafaf, num[u] = -1;
	if (ed[u]) f[u] = dep[u], num[u] = ed[u];
	for (int v : son[u]) {
		dep[v] = dep[u] + 1;
		dfs(v);
		if (f[u] - dep[u] + f[v] - dep[u] > ans) ans = f[u] + f[v] - 2 * dep[u], anx = num[u], any = num[v];
		if (f[v] > f[u]) f[u] = f[v], num[u] = num[v];
	}
}

int main() {
	Id[0] = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		auto it = Id.find(a[i]);
		if (it != Id.end()) ed[it -> second] = i;
		else Id[a[i]] = ++tot, ed[tot] = i, ins(tot, a[i]);
	}
	dfs(1);
	printf("%d %d %d\n", anx, any, ans);
	return 0;
}