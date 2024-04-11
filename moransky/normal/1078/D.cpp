#include <iostream>
#include <cstdio>
#include <cstring>
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

const int N = 6e5 + 5, S = 20;

int n, a[N], R[N][S], L[N][S], Log[N], m;

int st[2][N][S];

int inline c1(int x, int y) {
	return x + a[x] > y + a[y] ? x : y;
}

int inline c2(int x, int y) {
	return x - a[x] < y - a[y] ? x : y;
}

void inline ST_prework() {
	Log[0] = -1;
	for (int i = 1; i <= m; i++) {
		Log[i] = Log[i >> 1] + 1;
		st[0][i][0] = st[1][i][0] = i;
	}
	for (int j = 1; j < S; j++) {
		for (int i = 1; i + (1 << j) - 1 <= m; i++) {
			st[0][i][j] = c1(st[0][i][j - 1], st[0][i + (1 << (j - 1))][j - 1]);
			st[1][i][j] = c2(st[1][i][j - 1], st[1][i + (1 << (j - 1))][j - 1]);
		}
	}
}

int inline query1(int l, int r) {
	int k = Log[r - l + 1];
	return c1(st[0][l][k], st[0][r - (1 << k) + 1][k]);
}

int inline query2(int l, int r) {
	int k = Log[r - l + 1];
	return c2(st[1][l][k], st[1][r - (1 << k) + 1][k]);
}

int inline rt(int p, int k) {
	--k;
	int q = p;
	for (int i = 0; i < S; i++) {
		if (k >> i & 1) {
			int np = c1(R[p][i], R[q][i]), nq = c2(L[p][i], L[q][i]);
			p = np, q = nq;
		}
	}
	return p + a[p];
}

int inline lt(int p, int k) {
	--k; int q = p;
	for (int i = 0; i < S; i++)
		if (k >> i & 1) {
			int np = c2(L[p][i], L[q][i]), nq = c1(R[p][i], R[q][i]);
			p = np, q = nq;
		}
	return p - a[p];
}

int inline bg(int x) {
	if (x < 1) x = 1;
	if (x > m) x = m;
	return x;
}

int main() {
    read(n); m = 6 * n;
    for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	for (int i = n + 1; i <= m; i++) a[i] = a[i - n];
	if (n == 1) {
		puts("0"); return 0;
	}
	ST_prework();
	for (int i = 1; i <= m; i++) {
		R[i][0] = query1(max(1, i - a[i]), min(m, i + a[i]));
		L[i][0] = query2(max(1, i - a[i]), min(m, i + a[i]));
	}
	for (int j = 1; j < S; j++) {
		for (int i = 1; i <= m; i++) {
			R[i][j] = c1(R[R[i][j - 1]][j - 1], R[L[i][j - 1]][j - 1]);
			L[i][j] = c2(L[R[i][j - 1]][j - 1], L[L[i][j - 1]][j - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (rt(i + 2 * n, mid) + 1 >= lt(i + 3 * n, mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d ", r);
	}
}