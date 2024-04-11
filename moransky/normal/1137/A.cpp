// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
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

const int N = 1005;

typedef pair<int, int> PII;

int n, m, a[N][N], t, L1[N][N], L2[N][N], S1[N], S2[N];

PII e[N];

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) read(a[i][j]);
	for (int i = 1; i <= n; i++) {
		t = 0;
		for (int j = 1; j <= m; j++) e[++t] = mp(a[i][j], j);
		sort(e + 1, e + 1 + t);
		int c = 0;
		for (int j = 1; j <= t; j++) {
			if (j == 1 || e[j].fi != e[j - 1].fi) c++;
			L1[i][e[j].se] = c;
		}
		S1[i] = c;
	}
	for (int j = 1; j <= m; j++) {
		t = 0;
		for (int i = 1; i <= n; i++) e[++t] = mp(a[i][j], i);
		sort(e + 1, e + 1 + t);
		int c = 0;
		for (int i = 1; i <= n; i++) {
			if (i == 1 || e[i].fi != e[i - 1].fi) c++;
			L2[e[i].se][j] = c;
		}
		S2[j] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", 1 + max(L1[i][j] - 1, L2[i][j] - 1) + max(S1[i] - L1[i][j], S2[j] - L2[i][j]));
		}
		puts("");
	}
	return 0;
}