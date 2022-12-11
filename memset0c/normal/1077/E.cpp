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
int n, m, i, tn, ans, sum, a[N], b[N];
std::multiset < int > set;
std::vector < int > rub;

void main() {
	for (read(n), i = 1; i <= n; i++)
		read(a[i]), b[i] = a[i];
	std::sort(b + 1, b + n + 1);
	tn = std::unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++)
		++b[a[i]];
	for (int i = 1; i <= tn; i++)
		set.insert(b[i]);
	for (int i = 1; i <= n; i++) {
		rub.clear(), sum = 0;
		for (int j = 1, l = i; l <= n; l <<= 1, ++j) {
			auto it = set.lower_bound(l);
			if (it == set.end()) break;
			rub.push_back(*it), sum += l;
			set.erase(it);
		}	
		ans = std::max(ans, sum);
		for (auto u : rub) set.insert(u);
	}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }