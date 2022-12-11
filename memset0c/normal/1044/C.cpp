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

const int N = 3e5 + 10;
int n, ans, minX, maxX, minY, maxY;
int x[N], y[N], t[4];

template < class T > inline T abs(const T &x) {
	if (x < 0) return -x;
	else return x;
}

void solve(int ta, int tb, int tc, int td) {
	int a = std::min(ta, tc);
	int b = std::min(tb, td);
	int c = std::max(ta, tc);
	int d = std::max(tb, td);
	for (int i = 1; i <= n; i++)
		ans = std::max( ans,
			(abs(std::max(c, x[i]) - std::min(a, x[i])) +
			abs(std::max(d, y[i]) - std::min(b, y[i]))) << 1ll
		);
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(x[i]), read(y[i]);
	minX = maxX = minY = maxY = 1;
	for (int i = 1; i <= n; i++) {
		if (x[i] < x[minX]) minX = i;
		if (x[i] > x[maxX]) maxX = i;
		if (y[i] < y[minY]) minY = i;
		if (y[i] > y[maxY]) maxY = i;
	}
	t[0] = minX, t[1] = maxX, t[2] = minY, t[3] = maxY;
	int flag = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (t[i] == t[j] && i != j) flag = true;
			else solve(x[t[i]], y[t[i]], x[t[j]], y[t[j]]);
		}
	if (!flag) print(ans, " \n"[n == 3]);
	ans = (x[maxX] - x[minX] + y[maxY] - y[minY]) << 1;
	for (int i = flag ? 3 : 4; i <= n; i++)
		print(ans, " \n"[i == n]);
}

} signed main() { return ringo::main(), 0; }