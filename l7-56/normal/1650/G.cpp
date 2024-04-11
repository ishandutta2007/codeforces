#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 2e5 + 10, maxm = 1e6 + 10, inf = 1e9 + 10, mod = 1e9 + 7;
int n,m,s,t,dep[maxn];
struct Edge {
	int v, nxt;
}e[maxm];
int h[maxn], cnt_e;
void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }

void bfs() {
	queue <int> q;
	q.push(s), dep[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v;
			if (dep[v]) continue;
			q.push(v), dep[v] = dep[u] + 1;
		}
	}
}

int cs[maxn],ct[maxn];
vector <int> a[maxn];

void work() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	cnt_e = 0;
	for (int i = 1; i <= n; ++i) h[i] = dep[i] = cs[i] = ct[i] = 0, a[i].clear();
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	bfs();
	for (int i = 1; i <= n; ++i) a[dep[i]].push_back(i);
	cs[s] = 1;
	for (int i = 1; i < dep[t]; ++i)
		for (int u : a[i])
			for (int j = h[u]; j; j = e[j].nxt) {
				int v = e[j].v;
				if (dep[v] != dep[u] + 1) continue;
				cs[v] = (cs[v] + cs[u]) % mod;
			}
	ct[t] = 1;
	for (int i = dep[t]; i > 1; --i)
		for (int u : a[i])
			for (int j = h[u]; j; j = e[j].nxt) {
				int v = e[j].v;
				if (dep[v] != dep[u] - 1) continue;
				ct[v] = (ct[v] + ct[u]) % mod;
			}
	int ans = cs[t];
	for (int i = 1; i <= dep[t]; ++i)
		for (int u : a[i])
			for (int j = h[u]; j; j = e[j].nxt) {
				int v = e[j].v;
				if (dep[u] != dep[v]) continue;
				ans = (ans + 1ll * cs[u] * ct[v] % mod) % mod;
			}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}