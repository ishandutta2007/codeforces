#include <bits/stdc++.h>

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

const int N = 1005;

const double eps = 1e-8;

int n, m, a[N], b[N];

void up(double &s, int i) {
	s -= s / a[i];
}

void down(double &s, int i) {
	s -= s / b[i];
}

bool inline check(double x) {
	double s = m + x;
	for (int i = 1; i < n; i++) {
		up(s, i);
		down(s, i + 1);
	}
	up(s, n), down(s, 1);
	return s >= m;
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]);
	double l = 0, r = 1e14;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	if (!check(r)) {
		puts("-1");
	} else printf("%.8lf\n", r);
}