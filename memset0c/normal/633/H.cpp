// =================================
//   author: memset0
//   date: 2018.12.27 20:26:57
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define pb push_back
#define rep(i, l, r) for (register int i = l; i <= r; i++)

namespace ringo {
typedef long long ll;
typedef unsigned long long ull;

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
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

const int N = 3e4 + 10;
int n, m, u, p, a[N], l[N], r[N], f[N], max[N], id[N], ans[N], cnt[N];
inline bool cmp(int x, int y) { return a[x] < a[y]; }

void main() {
	read(n), read(p);
	for (int i = 1; i <= n; i++) read(a[i]), id[i] = i;
	read(m);
	for (int i = 1; i <= m; i++) read(l[i]), read(r[i]);
	std::sort(id + 1, id + n + 1, cmp);
	memset(max, -1, sizeof(max));
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % p;
	for (int i = 1; i <= n; i++) {
		int u = a[id[i]], v = u % p;
		for (int j = 1; j <= m; j++)
			if (u != max[j] && l[j] <= id[i] && id[i] <= r[j]) {
				max[j] = u, ++cnt[j];
				ans[j] = (ans[j] + v * f[cnt[j]]) % p;
			}
	}
	for (int i = 1; i <= m; i++) print(ans[i], '\n');
}

} signed main() { return ringo::main(), 0; }