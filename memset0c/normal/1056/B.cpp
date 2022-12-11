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

const int N = 1005;

int n, m;
ll ans, cnt[N];

void main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
		cnt[i * i % m] += n / m;
    for (int i = n / m * m + 1; i <= n; i++)
		cnt[1ll * i * i % m]++;
    for (int i = 0; i < m; i++)
		ans += cnt[i] * cnt[i ? m - i : 0];
    std::cout << ans << std::endl;
}

} signed main() { return ringo::main(), 0; }