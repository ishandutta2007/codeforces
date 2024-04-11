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

const int N = 1e5 + 10;
int n, m, x, y, max, final_ans;
int ans[N];
std::vector < int > a[N];

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(x), read(y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= m; i++) {
		std::sort(a[i].begin(), a[i].end());
		int siz = (int)a[i].size();
		int sum = 0;
		for (int j = 1; j <= siz; j++) {
			sum += a[i][siz - j];
			if (sum > 0) ans[j] += sum;
		}
	}
	for (int i = 1; i <= n; i++)
		final_ans = std::max(final_ans, ans[i]);
	print(final_ans, '\n');
}

} signed main() { return ringo::main(), 0; }