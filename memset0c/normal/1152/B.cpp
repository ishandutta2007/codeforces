// =================================
//   author: memset0
//   date: 2019.05.06 16:41:09
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
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

const int N = 8400000;
int n, l, r, q[N], opr[N], lst[N];

inline bool check(int x) {
	for (int i = 0; i <= 24; i++)
		if (x == ((1 << i) - 1))
			return true;
	return false;
}

void main() {
	read(n);
	if (check(n)) { puts("0"); return; }
	l = r = 0, q[0] = n, lst[n] = -1;
	while (l <= r) {
		int u = q[l++];
		// printf(">>> %d\n", u);
		for (int i = 0; i <= 23; i++) {
			int v = (u ^ ((1 << i) - 1)) + 1;
			if (lst[v] || v > (1 << 23)) continue;
			lst[v] = u, opr[v] = i;
			if (check(v)) {
				std::vector<int> ans;
				for (int i = v; i != n; ) {
					ans.push_back(opr[i]);
					i = lst[i];
				}
				std::reverse(ans.begin(), ans.end());
				print(ans.size() << 1, '\n');
				for (auto x : ans) print(x, ' ');
				return;
			}
			q[++r] = v;
		}
	}
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}