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

const int N = 2e5 + 10, M = 5e5 + 10, inf = 1e18;
int n, m, s, e, u, v, w, ans, flow, flag;
int a[N], pre[N], dep[N], gap[N], cur[N];
int tot = 2, hed[N], to[M], val[M], nxt[M];

inline void add_simple_edge(int u, int v, int w) { nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++; }
inline void add_edge(int u, int v, int w) { add_simple_edge(u, v, w), add_simple_edge(v, u, 0); }

void main() {
	read(n), read(m);
	s = n + m + 1, e = s + 1;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		add_edge(i, e, a[i]);
	}
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w);
		add_edge(i + n, u, inf);
		add_edge(i + n, v, inf);
		add_edge(s, i + n, w);
		ans += w;
	}
    u = s, gap[0] = e;
    while (dep[s] < e) {
        if (u == e) {
            flow = inf;
            for (int i = pre[e]; i; i = pre[to[i ^ 1]])
                flow = std::min(flow, val[i]);
            for (int i = pre[e]; i; i = pre[to[i ^ 1]])
                val[i] -= flow, val[i ^ 1] += flow;
            ans -= flow, u = s;
        }
        flag = 0;
        for (int &i = cur[u]; i; i = nxt[i])
            if (val[i] && dep[u] == dep[to[i]] + 1) {
                u = to[i], pre[to[i]] = i;
                flag = 1; break;
            }
        if (!flag) {
            if (!--gap[dep[u]]) break;
            dep[u] = e;
            for (int i = hed[u]; i; i = nxt[i])
                if (val[i] && dep[u] > dep[to[i]] + 1)
                    dep[u] = dep[to[i]] + 1, cur[u] = i;
            ++gap[dep[u]];
            if (u != s) u = to[pre[u] ^ 1];
        }
    }
    print(ans), putchar('\n');
}

} signed main() { return ringo::main(), 0; }