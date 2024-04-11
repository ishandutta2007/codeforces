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

const int N = 2e5 + 5;

int n, q, a[N], hh, tt, mx, t;

int X[N], Y[N];

int main() {
	read(n); read(q);
	for (int i = 1; i <= n; i++) read(a[i]), chkMax(mx, a[i]);
	hh = 1, tt = n;
	while (a[hh] != mx) {
		++t;
		int A = a[hh], B = a[hh + 1];
		X[t] = A, Y[t] = B;
		if (A < B) swap(A, B);
		a[++hh] = A, a[++tt] = B;
	}
	while (q--) {
		LL x; read(x);
		if (x <= t) {
			printf("%d %d\n", X[x], Y[x]);
		} else {
			printf("%d %d\n", mx, a[hh + 1 + ((x - t - 1) % (n - 1))]);
		}
	}
}