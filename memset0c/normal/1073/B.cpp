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

const int N = 2e5 + 10;
int n, a[N], b[N], c[N], mrk[N];

void main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), c[a[i]] = i;
    for (int i = 1; i <= n; i++) read(b[i]);
    for (int i = 1; i <= n; i++)
        if (!mrk[c[b[i]]]) {
            int cnt = 0;
            for (int j = c[b[i]]; !mrk[j] && j; j--)
                mrk[j] = 1, ++cnt;
            print(cnt, " \n"[i == n]);
        } else {
            print(0, " \n"[i == n]);
        }
}

} signed main() { return ringo::main(), 0; }