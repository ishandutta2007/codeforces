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

int n;

int a[N], b[N];
int c[N], d[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), c[i - 1] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i++) read(b[i]), d[i - 1] = b[i] - b[i - 1];
	sort(c + 1, c + n);
	sort(d + 1, d + n);
	if (a[1] != b[1]) {
		puts("No"); return 0;
	}
	for (int i = 1; i < n; i++) {
		if (d[i] != c[i]) { puts("No"); return 0; }
	}
	puts("Yes");
	return 0;
}