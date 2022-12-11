// =================================
//   author: memset0
//   date: 2019.05.26 23:54:01
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
ll ans;
char s[N];

void main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for (int l = 1; l <= n; l++) {
		bool flag = false;
		for (int r = l + 2; r <= n; r++) {
			for (int k = 1; r - (k << 1) >= l; k++) {
				if (s[r] == s[r - k] && s[r - k] == s[r - (k << 1)]) {
					flag = true;
					break;
				}
			}
			if (flag == true) {
				ans += n - r + 1;
				break;
			}
		}
	}
	print(ans, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}