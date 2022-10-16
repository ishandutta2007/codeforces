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

const int P = 998244353, N = 505, M = 1e6;

int n, m, c[M], L[N], R[N], f[N][N], cnt[N];

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

struct Node{
	int l, r, v;
	bool operator < (const Node &b) const {
		return l < b.l;
	}
} e[N];

vector<PII> h[N];

vector<int> b[N];

int dp(int l, int r) {
	if (l > r) return 1;
	int mn = 2e9, mx = -2e9, sum = 0;
	for (int i = l; i <= r; i++)
		chkMax(mx, e[i].r), chkMin(mn, e[i].l), sum += cnt[e[i].v];
	if (mx - mn + 1 != sum) {
		return 0;
	}
	if (~f[l][r]) return f[l][r];
	int &v = f[l][r];
	int p = l;
	for (int i = l + 1; i <= r; i++)
		if (e[i].v < e[p].v) p = i;
	int vl = 0, vr = 0;
	for (int i = p; i >= l; i--) add(vl, 1ll * dp(l, i - 1) * dp(i, p - 1) % P);
	int q = p;
	while (q < r && e[q + 1].r <= e[p].r) ++q;
	for (int i = q; i <= r; i++) add(vr, 1ll * dp(i + 1, r) * dp(q + 1, i) % P);
	v = 1ll * vl * vr % P;
	for (PII o: h[p]) v = 1ll * v * dp(o.fi, o.se) % P;
	return v;
}

int main() {
	memset(f, -1, sizeof f);
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(c[i]);
		if (!L[c[i]]) L[c[i]] = i;
		R[c[i]] = i;
		cnt[c[i]]++;
		b[c[i]].pb(i);
	}
	for (int i = 1; i <= n; i++) e[i] = (Node) { L[i], R[i], i };
	sort(e + 1, e + 1 + n);
	for (int p = 1; p <= n; p++) {
		int q = p;
		while (q < n && e[q + 1].r <= e[p].r) ++q;
		int now = p + 1;
		for (int v: b[e[p].v]) {
			if (now > q) break;
			if (e[now].l > v) continue;
			int nL = now;
			while (now < q && e[now + 1].r <= v) {
				++now;
			}
			int nR = now;
			h[p].pb(mp(nL, nR));
			++now;
		}
	}
	printf("%d\n", dp(1, n));
    return 0;
}