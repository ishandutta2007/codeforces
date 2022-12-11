#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 1e2 + 10;

int n, m, cnt[N];

void main() {
	read(n);
    for (int i = 1; i <= n; i++) {
		read(m);
        for (int j = 1, x; j <= m; j++)
			cnt[read(x), x]++;
    }
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == n)
			printf("%d ", i);
    }
	puts("");
}

} signed main() { return ringo::main(), 0; }