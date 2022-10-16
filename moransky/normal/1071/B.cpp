#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2005;

typedef pair<int, int> PII;

int n, k, rk[N][N], f[N][N], mx;

int t, len;

PII e[N << 1], p[N][N];

char s[N][N];

struct E{
	int x, y, rk;
} d[N << 1];

bool inline cmp(E a, E b) {
	if (s[a.x][a.y] != s[b.x][b.y]) return s[a.x][a.y] < s[b.x][b.y];
	return a.rk < b.rk;
}

int main() {
	memset(rk, 0x3f, sizeof rk);
	read(n), read(k);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	rk[n][n] = 1;
	memset(f, 0x3f, sizeof f);
	f[1][1] = s[1][1] != 'a';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i + j == 2) continue;
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + (s[i][j] != 'a');
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (f[i][j] <= k) mx = max(mx, i + j);
		}
	}
	
	for (int i = 1; i + 1 <= mx && i <= n; i++) {
		if (mx - i >= 1 && mx - i <= n) {
			if (f[i][mx - i] <= k) {
				e[++t] = mp(i, mx - i);
			}
		}
	}
	for (int w = 2 * n - 1; w >= mx; w--) {
		if (w == 0) continue;
		len = 0;
		for (int i = max(w - n, 1), j; i <= n && (j = w - i) >= 1; i++) {
			p[i][j] = rk[i][j + 1] < rk[i + 1][j] ? mp(i, j + 1): mp(i + 1, j);
			d[++len] = (E) { i, j, min(rk[i][j + 1], rk[i + 1][j]) };
		}
		sort(d + 1, d + 1 + len, cmp);
		int o = 0;
		for (int i = 1; i <= len; i++) {
			if (i == 1 || !(!cmp(d[i], d[i - 1]) && !cmp(d[i - 1], d[i]))) ++o;
			rk[d[i].x][d[i].y] = o;
		}
	}
	
	
	PII u = mp(-1, -1);
	for (int i = 1; i <= t; i++) {
		int x = e[i].fi, y = e[i].se;
		if (x + 1 <= n) {
			if (u.fi == -1 || rk[u.fi][u.se] > rk[x + 1][y]) {
				u = mp(x + 1, y);
			}
		}
		if (y + 1 <= n) {
			if (u.fi == -1 || rk[u.fi][u.se] > rk[x][y + 1]) {
				u = mp(x, y + 1);
			}
		}
	}
	for (int i = 2; i <= mx; i++) putchar('a');
	if (mx == 2 * n) return 0;
	if (mx == 0) {
		u = mp(1, 1);
	}
	while (1) {
		putchar(s[u.fi][u.se]);
		if (u.fi == n && u.se == n) break;
		u = p[u.fi][u.se];
	}
}