// Skyqwq
#include <iostream>
#include <cstdio>

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

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2e5 + 5, L = 18;

int n, m, q, p[N], a[N], nxt[N][L], cnt[N], pos[N], R[N];
int f[N][L], Log[N];

void inline buildST() {
	Log[0] = -1;
	for (int i = 1; i <= m; i++) {
		f[i][0] = R[i];
		Log[i] = Log[i >> 1] + 1;
	}
	for (int j = 1; j < L; j++) {
		for (int i = 1; i + (1 << j) - 1 <= m; i++) {
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int inline get(int l, int r) {
	int k = Log[r - l + 1];
	return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
	read(n), read(m), read(q);
	for (int i = 0; i < n; i++) read(p[i]), pos[p[i]] = i;
	for (int i = 1; i <= m; i++) read(a[i]);
	for (int i = m; i; i--) {
		int v = p[(pos[a[i]] + 1) % n];
		nxt[i][0] = cnt[v];
		cnt[a[i]] = i;
	}
	for (int j = 1; j < L; j++)
		for (int i = 1; i <= m; i++) {
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
		}
	int b = n - 1;
	for (int i = 1; i <= m; i++) {
		int p = i;
		for (int j = 0; j < L; j++) {
			if (b >> j & 1) p = nxt[p][j];
		}
		if (!p) p = 1e9;
		R[i] = p;
	}
	buildST();
	while (q--) {
		int l, r; read(l), read(r);
		putchar(get(l, r) <= r ? '1' : '0');
	}
	return 0;
}