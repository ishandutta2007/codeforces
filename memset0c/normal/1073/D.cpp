#include <bits/stdc++.h>
#define int long long
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
int n, a[N];
ll t, s, c, ans;

void main() {
    read(n), read(t);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    c = n + 1;
    while (c) {
        s = c = 0;
        for (int i = 1; i <= n; i++)
            if (t >= a[i]) {
                t -= a[i];
                s += a[i];
                ++c, ++ans;
            }
        if (!c) break;
        ans += t / s * c, t %= s;
    }
    print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }