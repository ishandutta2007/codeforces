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
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
 
const int N = 2e5 + 5, L = 18;

int n, a[N];

LL c[N], s[N];

void inline add(int x, LL k) {
	for (; x <= n; x += x & -x) c[x] += k;
}

int inline find(LL x) {
	int p = 0;
	for (int i = L - 1; ~i; i--) {
		if (p + (1 << i) <= n && c[p + (1 << i)] <= x) {
			p += 1 << i;
			x -= c[p];
		}
	}
	return p + 1;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) 
		add(i, i), read(s[i]);
	for (int i = n; i; i--) {
		a[i] = find(s[i]);
		add(a[i], -a[i]);
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}