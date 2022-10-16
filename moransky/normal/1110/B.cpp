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

const int N = 1e5 + 5;

int n, m, k, b[N], a[N], t;
 
int main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i < n; i++) a[++t] = b[i + 1] - b[i] - 1;
	sort(a + 1, a + 1 + t);
	int ans = n;
	for (int i = 1; i <= n - k; i++) ans += a[i];
	printf("%d\n", ans);
	return 0;
}