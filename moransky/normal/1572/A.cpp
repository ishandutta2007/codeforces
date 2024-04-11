// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
const int N = 2e5 + 5, INF = 1e9;

int n, in[N], q[N], f[N];

vector<int> g[N];

void inline clear() {
	for (int i = 1; i <= n; i++) in[i] = 0, g[i].clear();
}

int inline work() {
	int hh = 1, tt = 0, ans = -1;
	for (int i = 1; i <= n; i++) f[i] = -INF;
	for (int i = 1; i <= n; i++) if (!in[i]) q[++tt] = i, f[i] = 0;
	while (hh <= tt) {
		int u = q[hh++];
		chkMax(ans, f[u]);
		for (int v: g[u]) {
			chkMax(f[v], f[u] + (v < u ? 1 : 0));
			if (--in[v] == 0) q[++tt] = v;
		}
	}
	if (tt != n) return -1;
	return ans + 1;
}

int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) {
			int k; read(k), in[i] = k;
			while (k--) {
				int x; read(x);
				g[x].pb(i);
			}
		}
		printf("%d\n", work());
		clear();
	}
    return 0;
}