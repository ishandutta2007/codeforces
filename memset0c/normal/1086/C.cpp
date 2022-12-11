// =================================
//   author: memset0
//   date: 2018.12.23 22:04:52
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
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

const int N = 1e6 + 10;
int T, k, n, pro[26], tpro[26];
bool find, vis[26], tvis[26];
char s[N], a[N], b[N];

int link(int x, int y) {
	if (~pro[x] && pro[x] == y) return 1;
	if (vis[y]) return -1;
	if (~pro[x] && pro[x] != y) return -1;
	pro[x] = y, vis[y] = 1; return 1;
}

void solve1(int u) {
	for (int i = u; i <= n; i++) {
		for (int c = a[i] + 1; c < k; c++)
			if (~link(s[i], c)) {
				find = true;
				return;
			}
		int ret = link(s[i], a[i]);
		if (ret == -1) { find = false; return; }
	}
	find = true; return;
}

void solve2(int u) {
	for (int i = u; i <= n; i++) {
		for (int c = 0; c < b[i]; c++)
			if (~link(s[i], c)) {
				find = true;
				return;
			}
		int ret = link(s[i], b[i]);
		if (ret == -1) { find = false; return; }
	}
	find = true; return;
}

void main() {
	for (read(T); T--; ) {
		memset(vis, 0, sizeof(vis));
		memset(pro, -1, sizeof(pro));
		scanf("%d%s%s%s", &k, s + 1, a + 1, b + 1);
		n = strlen(s + 1);
		for (int i = 1; i <= n; i++) a[i] -= 'a', b[i] -= 'a', s[i] -= 'a';
		find = true;
		for (int i = 1; i <= n; i++)
			if (a[i] == b[i]) {
				int ret = link(s[i], a[i]);
				if (ret == -1) {
					find = false;
					break;
				}
			} else {
				bool flag = false;
				for (int c = a[i] + 1; c < b[i]; c++)
					if (~link(s[i], c)) {
						find = flag = true;
					}
				if (flag) break;
				for (int i = 0; i < k; i++)
					tvis[i] = vis[i], tpro[i] = pro[i];
				if (~link(s[i], a[i])) { solve1(i + 1); if (find) break; }
				for (int i = 0; i < k; i++)
					vis[i] = tvis[i], pro[i] = tpro[i];
				if (~link(s[i], b[i])) { solve2(i + 1); if (find) break; }
				find = false; break;
			}
		if (find) {
			for (int i = 0; i < k; i++)
				if (-1 == pro[i]) {
					for (int j = 0; j < k; j++)
						if (~link(i, j))
							break;
					if (pro[i] == -1) find = false;
				}
		}
		if (find) {
			puts("YES");
			for (int i = 0; i < k; i++)
				putchar(pro[i] + 'a');
			putchar('\n');
		} else puts("NO");
	}
}

} signed main() { return ringo::main(), 0; }