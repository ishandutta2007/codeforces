// =================================
//   author: memset0
//   date: 2019.06.28 16:18:24
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 1e5 + 10;
int n, min, max, sum, b[N], c[N];
double a[N];

void main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
    for (int i = 1; i <= n; i++) {
        min = floor(a[i]);
        max = ceil(a[i]);
        b[i] = min, sum += min;
        if (min != max) c[i] = 1;
    }
    for (int i = 1; i <= n && sum; i++)
        if (c[i]) sum++, b[i]++;
    for (int i = 1; i <= n; i++) print(b[i], '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}