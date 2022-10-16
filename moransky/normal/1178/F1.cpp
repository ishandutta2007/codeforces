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

const int P = 998244353, N = 505;

int n, m, c[N], pos[N], f[N][N];

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

int dp(int l, int r) {
	if (l > r) return 1;
	if (~f[l][r]) return f[l][r];
	int &v = f[l][r];
	int p = l;
	for (int i = l + 1; i <= r; i++)
		if (c[i] < c[p]) p = i;
	int vl = 0, vr = 0;
	for (int i = p; i >= l; i--) add(vl, 1ll * dp(l, i - 1) * dp(i, p - 1) % P);
	for (int i = p; i <= r; i++) add(vr, 1ll * dp(i + 1, r) * dp(p + 1, i) % P);
	v = 1ll * vl * vr % P;
	return v;
}

int main() {
	memset(f, -1, sizeof f);
	read(n), read(m);
	for (int i = 1; i <= m; i++) read(c[i]), pos[c[i]] = i;
	printf("%d\n", dp(1, n));
    return 0;
}