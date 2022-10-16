#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 200005;

int n, K, cnt[N];

LL ans = 0;

int head[N], numE = 0;

struct E{
	int next, v;
} e[N << 1];

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

void dfs(int u, int last) {
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == last) continue;
		dfs(v, u);
		cnt[u] += cnt[v];
		ans += min(cnt[v], 2 * K - cnt[v]);
	}
}

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1, x; i <= 2 * K; i++)
		scanf("%d", &x), cnt[x]++;
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}