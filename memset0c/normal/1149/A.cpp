// =================================
//   author: memset0
//   date: 2019.04.29 22:48:12
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 2e5 + 10;
int n, a[N], cnt[N];

void main() {
	read(n);
    for (int i = 1; i <= n; i++) {
		read(a[i]), cnt[a[i]]++;
    }
    if (cnt[2]) {
        cnt[2]--;
        printf("2 ");
        if (cnt[1]) { cnt[1]--; printf("1 "); }
        while (cnt[2]--) printf("2 ");
        while (cnt[1]--) printf("1 ");
    } else {
        while (n--) printf("1 ");
    }
	puts("");
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}