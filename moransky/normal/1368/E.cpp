// xtqqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, m, d[N], t;

vector<int> g[N];

bool st[N], er[N];

int main() {
	int T; read(T);
	while (T--) {
		t = 0;
		read(n), read(m);
		for (int i = 1; i <= m; i++) {
			int u, v; read(u), read(v);
			g[v].pb(u);
		}
		for (int i = 1; i <= n; i++) {
			bool ok = 0;
			for (int v: g[i])
				if (st[v]) ok = 1;
			if (ok) d[++t] = i, er[i] = 1;
			else {
				bool o = 0;
				for (int v: g[i]) {
					if (!er[v]) o = 1;
				}
				st[i] = o;
			}
		}
		printf("%d\n", t);
		for (int i = 1; i <= t; i++) printf("%d ", d[i]); puts("");
		for (int i = 1; i <= n; i++) g[i].clear(), st[i] = 0, er[i] = 0;
	}
    return 0;
}