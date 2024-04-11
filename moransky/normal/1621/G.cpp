// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5, P = 1e9 + 7;

int n, a[N], c[N], f[N], g[N], d[N], t, suf[N];

bool vis[N];

void inline add(int x, int y) {
	for (; x <= n; x += x & -x) (c[x] += y) %= P;
}

int inline ask(int x) {
	int res = 0;
	for (; x; x -= x & -x) (res += c[x]) %= P;
	return res;
}

void inline clr(int x) {
	for (; x <= n; x += x & -x) c[x] = 0;
}

bool inline cmp(PII x, PII y) {
	if (x.fi != y.fi) return x.fi > y.fi;
	return x.se < y.se;
}

PII e[N];

int main() {
	int T; read(T);
	while (T--) {
		read(n); t = 0;
		for (int i = 1; i <= n; i++) read(a[i]), c[i] = 0, d[++t] = a[i];
		sort(d + 1, d + 1 + t);
		t = unique(d + 1, d + 1 + t) - d - 1;
		for (int i = 1; i <= n; i++) a[i] = lower_bound(d + 1, d + 1 + t, a[i]) - d;
		
		
		for (int i = 1; i <= n; i++) {
			f[i] = (1 + ask(a[i] - 1)) % P;
			add(a[i], f[i]);
		}
		for (int i = 1; i <= n; i++) c[i] = 0;
		for (int i = n; i; i--) {
			g[i] = (1ll + ask(n) - ask(a[i]) + P) % P;
			add(a[i], g[i]);
		}
		
		for (int i = 1; i <= n; i++) c[i] = 0;
		int mx = -2e9;
		for (int i = n; i; i--) {
			vis[i] = chkMax(mx, a[i]);
			e[i] = mp(a[i], i); 
			suf[i] = mx;
		}
		sort(e + 1, e + 1 + n, cmp);
		vector<int> b;
		for (int i = 1; i <= n; i++) {
			int u = e[i].se;
			if (vis[u]) {
				while (b.size()) clr(b.back()), b.pop_back();
				b.pb(u);
				add(u, 1);
			} else {
				int v = (ask(n) - ask(u) + P) % P;
				b.pb(u);
				g[u] = (g[u] - v + P) % P;
				add(u, v);
			}
		}
		for (int i = 1; i <= n; i++) c[i] = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (suf[i] > a[i]) {
				ans = (ans + 1ll * f[i] * g[i]) % P;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}