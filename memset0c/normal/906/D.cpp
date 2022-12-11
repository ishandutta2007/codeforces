// =================================
//   author: memset0
//   date: 2019.02.07 15:40:11
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
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

const int N = 5e5 + 10, L = 60;
int n, m, lim, end, rit, lst, c_pri, a[N], mod[L], ans[L];
bool flag[L];

struct node {
    int l, r, mid, fst;
} p[N << 2];

inline int phi(int x) {
	int ans = 1;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) {
			x /= i, ans *= i - 1;
			while (x % i == 0) x /= i, ans *= i;
		}
	if (x != 1) ans *= x - 1;
	// printf("phi(%d) = %d\n", now, ans);
	return ans;
}

inline void push(ll x) {
    while (~end)
        if (x >= mod[end + 1]) flag[end--] = 1;
        else break;
}

inline int fpow(int a, int b, int p) {
    int s = 1; a %= p;
    for (; b; b >>= 1, a = (ll)a * a % p)
        if (b & 1) s = (ll)s * a % p;
    return s;
}

inline int fpow(int a, int b) {
    int s = 1; push(a), a %= mod[0];
    while (b) {
        if (b & 1) push((ll)s * a), s = (ll)s * a % mod[0];
        b >>= 1; if (b) push((ll)a * a), a = (ll)a * a % mod[0];
    } return s;
}

void build(int l, int r, int u = 1) {
    p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
    if (l == r) { p[u].fst = a[l] == 1 ? l : n + 2; return; }
    build(l, p[u].mid, u << 1), build(p[u].mid + 1, r, u << 1 | 1);
    p[u].fst = std::min(p[u << 1].fst, p[u << 1 | 1].fst);
}

inline int query(int k) { return a[k]; }

int query_fst(int l, int r, int u = 1) {
    if (p[u].l == l && p[u].r == r) return p[u].fst;
    if (r <= p[u].mid) return query_fst(l, r, u << 1);
    if (l > p[u].mid) return query_fst(l, r, u << 1 | 1);
    return std::min(query_fst(l, p[u].mid, u << 1), query_fst(p[u].mid + 1, r, u << 1 | 1));
}

int solve(int l, int r, int p, int lim) {
    memset(flag, 0, sizeof(flag));
    rit = query_fst(l, r) - 1, lst = 1;
    if (rit == n + 1) rit = r;
    if (rit < l) return query(l) % mod[0];
    r = rit, end = lim;
    while (rit >= l) {
        if (flag[0]) break;
        end = std::min(end, rit - l - 1);
        lst = fpow(query(rit--), lst);
    }

    if (l + lim < r) ans[lim] = 1;
    else lim = r - l, ans[lim] = query(r);
    ans[lim] %= mod[lim];
    for (int i = lim - 1; i >= 0; i--) {
        ans[i] = fpow(query(l + i), ans[i + 1] + (flag[i] ? mod[i + 1] : 0), mod[i]);
    }
    return ans[0] % mod[0];
}

void main() {
    read(n); int p; read(p);
    for (int i = 1; i <= n; i++) read(a[i]);
    build(1, n);
    mod[lim = 0] = p;
    for (int i = 1; mod[i - 1] != 1; i++)
        mod[i] = phi(mod[i - 1]), ++lim;
    mod[lim + 1] = 1;
	read(m);
    for (int i = 1, l, r; i <= m; i++) {
        read(l), read(r);
        print(solve(l, r, p, lim), '\n');
    }
}

} signed main() { return ringo::main(), 0; }