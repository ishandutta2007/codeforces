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

const int N = 2e5 + 10, M = 1e6 + 10;
int n, i, sum;
int a[N], cnt[M];
std::vector < int > ans;

bool check() {
	if (sum & 1) return false;
	if ((sum >> 1) > 1e6) return false;
	return (bool)cnt[sum >> 1];
}

void main() {
	for (read(n), i = 1; i <= n; i++)
		read(a[i]), sum += a[i], ++cnt[a[i]];
	for (int i = 1; i <= n; i++) {
		sum -= a[i], --cnt[a[i]];
		if (check()) ans.push_back(i);
		sum += a[i], ++cnt[a[i]];
	}
	print(ans.size(), '\n');
	for (auto i : ans) print(i, ' ');
	putchar('\n');
}

} signed main() { return ringo::main(), 0; }