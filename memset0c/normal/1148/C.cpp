// =================================
//   author: memset0
//   date: 2019.06.01 22:36:30
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; char c = getchar(); bool f = 0;
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
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 3e5 + 10;
int n, m, a[N], p[N], b[N];
std::vector<std::pair<int, int>> ans;

inline void swap(int i, int j) {
	// printf(">> %d %d\n", i, j, a[i], a[j]);
	// print(a, 1, n);
	std::swap(p[a[i]], p[a[j]]);
	std::swap(a[i], a[j]);
	ans.push_back(std::make_pair(i, j));
	// print(a, 1, n);
}

inline void move(int i, int j) {
	if (i > j) std::swap(i, j);
	if (j - i >= m) {
		swap(i, j);
		return;
	}
	if (i <= m && j <= m) {
		// swap(i, j);
		swap(i, n), swap(j, n), swap(i, n);
	} else if (i > m && j > m) {
		// swap(i, j);
		swap(1, j), swap(1, i), swap(1, j);
	} else {
		if (i > m && j <= m) std::swap(i, j);
		// swap(i, j);
		int a = i == 1 ? 2 : 1;
		int b = j == n ? n - 1 : n;
		swap(i, b), swap(j, a), swap(a, b), swap(i, b), swap(j, a);
	}
}

void main() {
	read(n), m = n >> 1;
	for (int i = 1; i <= n; i++) read(a[i]), p[a[i]] = i;
	// for (int i = 1; i <= n; i++) b[i] = a[i];
	for (int i = 1; i <= n; i++) {
		// printf("move %d %d\n", i, p[i]);
		// print(a, 1, n);
		if (i != p[i]) move(i, p[i]);
		// print(a, 1, n);
	}
	print(ans.size(), '\n');
	for (auto it : ans) {
		print(it.first, ' ');
		print(it.second, '\n');
		// std::swap(b[it.first], b[it.second]);
	}
	// print(b, 1, n);
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}