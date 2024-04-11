#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 4e5 + 10;
int n,m,fa[maxn];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) { fa[get(x)] = get(y); }
#define opp(x) ((x) <= n ? (x) + n : (x) - n)
struct Edge {
	int v,nxt;
}e[maxn];
int h[maxn],od[maxn],cnt_e;
void add(int x, int y) { e[++cnt_e] = {x, h[y]}, h[y] = cnt_e, od[x]++; }

int x[maxn],idx,vis[maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * 2; ++i) fa[i] = i;
	while (m--) {
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);
		merge(a, opp(b)), merge(opp(a), b);
		if (op == 1) add(opp(a), b), add(opp(b), a);
		else add(a, opp(b)), add(b, opp(a));
	}
	for (int i = 1; i <= n; ++i) if (get(i) == get(opp(i))) return printf("NO\n"), 0;

	queue <int> q;
	for (int i = 1; i <= n * 2; ++i)
		if (od[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		x[u] = ++idx;
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v;
			if (--od[v] == 0) q.push(v);
		}
	}
	for (int i = 1; i <= n * 2; ++i) if (!x[i]) return printf("NO\n"), 0;

	printf("YES\n");
	for (int i = 1; i <= n; ++i) {
		int f1 = get(i), f2 = get(opp(i));
		if (!vis[f1] && !vis[f2]) vis[f1] = 1;
		if (vis[f1]) printf("L %d\n", x[i]);
		else printf("R %d\n", x[opp(i)]);
	}
	return 0;
}