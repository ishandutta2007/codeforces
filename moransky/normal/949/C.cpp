// MoRanSky
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') x = x * 10 + (s ^ 48), s = getchar();
	x *= f;
}

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

const int N = 2e5 + 5;

int n, m, h, a[N], dfn[N], low[N], dfncnt, A[N], B[N], t, w[N], d[N];

vector<int> g[N];

int s[N], top, c[N], cnt;

bool ins[N];

void tarjan(int u) {
	ins[u] = 1, s[++top] = u;
	dfn[u] = low[u] = ++dfncnt;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!dfn[v]) tarjan(v), chkMin(low[u], low[v]);
		else if (ins[v]) chkMin(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++cnt;
		int v;
		do {
			v = s[top--], ins[v] = 0, c[v] = cnt, w[cnt]++;
		} while (v != u);
	}
}

int main() {
	read(n), read(m), read(h);
	for (int i = 1; i <= n; i++) read(a[i]);
	while (m--) {
		int x, y;
		read(x), read(y);
		if ((a[x] + 1) % h == a[y]) g[x].pb(y), A[++t] = x, B[t] = y;
		if ((a[y] + 1) % h == a[x]) g[y].pb(x), A[++t] = y, B[t] = x;
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= t; i++) {
		int x = A[i], y = B[i];
		x = c[x], y = c[y];
		if (x != y) {
			d[x]++;
		}
	}
	int ans = 2e9, p;
	for (int i = 1; i <= cnt; i++) {
		if (d[i] == 0) {
			chkMin(ans, w[i]);
			if (w[i] == ans) p = i;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) if (c[i] == p) printf("%d ", i);
}