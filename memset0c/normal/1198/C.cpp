// =================================
//   author: memset0
//   date: 2019.07.31 00:16:54
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for (int i = (l), i##edge = (r); i <= i##edge; ++i)
#define for_each(i, a) for (size_t i = 0, i##edge = a.size(); i < i##edge; ++i)
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

const int N = 5e5 + 10;
int T, n, m, len, vis[N], ans[N];
struct edge { edge* nxt; int to, w; } base[N << 1], *p = base, *hed[N];

inline void add_edge(int u, int v, int w) { *++p = (edge){ hed[u], v, w }, hed[u] = p; }

inline void modify(int u) {
    int v = -1, w = -1;
    for (edge* it = hed[u]; it; it = it->nxt)
        if (vis[it->to]) {
            v = it->to, w = it->w;
            break;
        }
    if (v == -1) vis[u] = 1;
    else vis[v] = 0, ans[++len] = w;
}

int main() {
	read(T);
    while (T--) {
		read(n), read(m);
        p = base, len = 0;
        for (int i = 1; i <= 3 * n; i++) vis[i] = 0, hed[i] = 0;
        for (int i = 1, u, v; i <= m; i++) {
			read(u), read(v);
			add_edge(u, v, i), add_edge(v, u, i);
		}
        for (int i = 1; i <= 3 * n; i++) modify(i);
        if (len >= n) {
            puts("Matching");
            for (int i = 1; i <= n; i++) print(ans[i], " \n"[i == n]);
        } else {
            puts("IndSet");
            int cnt = 0;
            for (int i = 1; i <= n * 3; ++i)
                if (vis[i]) {
                    cnt++;
                    print(i, " \n"[cnt == n]);
                    if (cnt == n) break;
                }
        }
    }
    return 0;
}

} signed main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}