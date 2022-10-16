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

const int N = 1e5 + 5;

int n, k, a[N], d, t, ans[N];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		d = gcd(d, a[i]);
	}
	d = gcd(d, k);
	for (int i = 0; i < k; i++)
		if (i % d == 0) ans[++t] = i;
	printf("%d\n", t);
	for (int i = 1; i <= t; i++) printf("%d ", ans[i]);
}