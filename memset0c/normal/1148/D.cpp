// =================================
//   author: memset0
//   date: 2019.06.01 23:39:25
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
int n;
std::vector<int> f, g;
std::vector<std::pair<int, std::pair<int, int>>> a, b;

bool cmp(std::pair<int, std::pair<int, int>> u, std::pair<int, std::pair<int, int>> v) {
    return u.second.second > v.second.second;
}

std::vector<int> solve(std::vector<std::pair<int, std::pair<int, int>>> a) {
    std::vector<int> ans;
    std::sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < (int) a.size(); i++) { ans.push_back(a[i].first); }
    return ans;
}

void main() {
	read(n);
    for (int i = 1, x, y; i <= n; i++) {
		read(x), read(y);
        (x < y) ? a.push_back({i, {x, y}}) : b.push_back({i, {y, x}});
    }
    f = solve(a); g = solve(b);
    if (f.size() > g.size()) {
        print(f.size(), '\n'), print(f, 0, f.size() - 1);
    } else {
		std::reverse(g.begin(), g.end());
        print(g.size(), '\n'), print(g, 0, g.size() - 1);
    }
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}