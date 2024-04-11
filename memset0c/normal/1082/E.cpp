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

const int N = 5e5 + 10;
int n, m, col, cnt, ans, len;
int a[N], c[N], d[N], s[N], stp[N], lst[N], mrk[N];

std::vector < std::pair < int, int > > b;

void main() {
	read(n), read(col);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++) {
		++len;
		if (a[i] == col) ++cnt;
		if (a[i] != a[i + 1] || i == n) {
			b.push_back(std::make_pair(a[i], len));
			len = 0;
		}
	}
	int m = (int)b.size();
	for (int i = 0; i < m; i++) {
		c[i + 1] = b[i].first;
		d[i + 1] = b[i].second;
	}
	for (int i = 1; i <= m; i++) {
		lst[i] = mrk[c[i]];
		mrk[c[i]] = i;
		s[i] = s[i - 1] + (c[i] == col ? d[i] : 0);
	}
	ans = cnt;
	for (int i = 1; i <= m; i++)
		if (c[i] != col) {
			if (lst[i]) {
				stp[i] = stp[lst[i]] + d[lst[i]] - (s[i] - s[lst[i]]);
				stp[i] = std::max(stp[i], (int)0);
				ans = std::max(ans, cnt + stp[i] + d[i]);
			}
			ans = std::max(ans, cnt + d[i]);
			// printf("[%d] %d %d : %d %d\n", i, c[i], d[i], stp[i], lst[i]);
		}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }