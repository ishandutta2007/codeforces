#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
struct Edge {
	int u,v,w;
}e[maxn];
int n,m,ans;
int fa[maxn], siz[maxn];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void unionn(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	fa[x] = y, siz[y] += siz[x];
}

void work() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	ans = (1 << 30) - 1;
	for (int bit = 29; bit >= 0; --bit) {
		int msk = ans ^ (1 << bit);
		for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
		for (int i = 1; i <= m; ++i)
			if ((msk & e[i].w) == e[i].w) unionn(e[i].u, e[i].v);
		if (siz[get(1)] == n) ans = msk;
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}