#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

mt19937 rd(time(0));

const int maxn = 1e5 + 10, maxm = 2e5 + 10, inf = 1e9;
int n,m;
struct Edge {
	int v, nxt;
} e[maxm];
int h[maxn], cnt_e;
void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }

int dfn[maxn],id[maxn],idx,ins[maxn],tree[maxm];
bool check(int u) {
	id[dfn[u] = ++idx] = u;
	ins[u] = 1;
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (!dfn[v]) {
			if (check(v)) return 1;
			tree[j] = 1;
		}
		else if (!ins[v]) return 1;
	}
	ins[u] = 0;
	return 0;
}

int low[maxn],slow[maxn];
void dfs(int u) {
	low[u] = dfn[u], slow[u] = inf;
	auto upd = [&] (int x) {
		if (low[u] > x) slow[u] = low[u], low[u] = x;
		else if (slow[u] > x) slow[u] = x;
	};
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (tree[j]) dfs(v), upd(low[v]), upd(slow[v]);
		else upd(dfn[v]);
	}
}

int f[maxn];

void work() {
	scanf("%d%d", &n, &m);
	cnt_e = 0;
	for (int i = 1; i <= n; ++i) h[i] = 0;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	for (int T = 100; T--; ) {
		int rt = rd() % n + 1;
		for (int i = 1; i <= n; ++i) ins[i] = dfn[i] = 0;
		for (int i = 1; i <= m; ++i) tree[i] = 0;
		idx = 0;
		if (check(rt)) continue;
		dfs(rt);
		vector <int> ans;
		for (int i = 1; i <= n; ++i) f[i] = 0;
		f[rt] = 1, ans.push_back(rt);
		for (int i = 2; i <= n; ++i) {
			int x = id[i];
			if (slow[x] < dfn[x]) continue;
			f[x] = f[id[low[x]]];
			if (f[x]) ans.push_back(x);
		}
		if ((int) ans.size() * 5 < n) return printf("-1\n"), void();
		sort(ans.begin(), ans.end());
		for (int u : ans) printf("%d ", u);
		printf("\n"); return;
	}
	printf("-1\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}