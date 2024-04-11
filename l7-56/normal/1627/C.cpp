#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int n,ans[maxn];
struct Edge {
	int v,id,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add(int x, int y, int z) {
	e[++cnt_e] = {y, z, h[x]};
	h[x] = cnt_e;
}
int deg[maxn];

void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) deg[i] = h[i] = 0;
	cnt_e = 0;
	for (int i = 1; i < n; ++i) {
		int x,y;
		scanf("%d%d", &x, &y);
		add(x, y, i), add(y, x, i);
		deg[x]++, deg[y]++;
	}
	int st = 0, pre = 0, val = 0;
	for (int i = 1; i <= n; ++i)
		if (deg[i] > 2) { printf("-1\n"); return; }
		else if (deg[i] == 1) st = i;
	do {
		for (int j = h[st]; j; j = e[j].nxt) {
			if (e[j].v == pre) continue;
			ans[e[j].id] = val + 2;
			pre = st, st = e[j].v;
			val ^= 1;
			break;
		}
	} while (deg[st] == 2);
	for (int i = 1; i < n; ++i) printf("%d%c", ans[i], " \n"[i == n - 1]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}