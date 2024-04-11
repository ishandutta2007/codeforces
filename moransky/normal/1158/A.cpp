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

int n, b[N], g[N], m;
 
int main() {
    read(n); read(m);
    LL s = 0, t = 0;
    for (int i = 1; i <= n; i++) read(b[i]), s += b[i];
    for (int i = 1; i <= m; i++) read(g[i]), t += g[i];
    sort(b + 1, b + 1 + n);
	sort(g + 1, g + 1 + m);
	if (b[n] > g[1]) { puts("-1"); return 0; }
	s *= m;
	s += t;
	s -= (m - 1ll) * b[n];
	if (b[n] == g[1]) s -= b[n];
	else s -= b[n - 1];
	print(s);
	return 0;
}