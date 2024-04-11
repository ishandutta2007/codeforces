// =================================
//   author: memset0
//   date: 2019.05.07 15:02:42
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

const int N = 2e5 + 10;
int n, m, cnt;
std::vector<int> G[N];

namespace bit {
    int s[N << 2];
    inline void modify(int k, int w) {
        // printf("bit::modify %d %d\n", k, w);
        for (; k < (N << 2); k += k & -k) s[k] += w;
    }
    inline int query(int k) {
        int ans = 0;
        for (; k; k -= k & -k) ans += s[k];
        return ans;
    }
}

namespace lct {
    int tag, fa[N], ch[N][2], col[N], cfl[N], rev[N], siz[N];
    inline int getSon(int x) { return ch[fa[x]][1] == x; }
    inline int isRoot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    inline void maintain(int x) {
        siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
    }
    inline void pushupCol(int x, int c) { col[x] = cfl[x] = c; }
    inline void pushupRev(int x) { rev[x] ^= 1, std::swap(ch[x][0], ch[x][1]); }
    inline void pushdown(int x) {
        if (rev[x]) pushupRev(ch[x][0]), pushupRev(ch[x][1]), rev[x] = 0;
        if (cfl[x]) pushupCol(ch[x][0], cfl[x]), pushupCol(ch[x][1], cfl[x]), cfl[x] = 0;
    }
    inline void cleanUp(int x) { if (!isRoot(x)) cleanUp(fa[x]); pushdown(x); }
    inline void rotate(int x) {
        if (!x || !fa[x]) return;
        int f = fa[x], ff = fa[f], fs = getSon(x), ffs = getSon(f), y = ch[x][fs ^ 1];
        if (!isRoot(f)) ch[ff][ffs] = x; ch[x][fs ^ 1] = f, ch[f][fs] = y;
        fa[y] = f, fa[f] = x, fa[x] = ff, maintain(f), maintain(x);
    }
    inline void splay(int x) {
        cleanUp(x);
        for (int f = fa[x]; !isRoot(x); rotate(x), f = fa[x])
            if (!isRoot(f)) rotate(getSon(x) == getSon(f) ? f : x);
    }
    inline void access(int x, int c) {
        for (int y = 0; x; y = x, x = fa[x]) {
            splay(x);
            bit::modify(col[x], -siz[ch[x][0]] - 1);
            bit::modify(c, siz[ch[x][0]] + 1);
            ch[x][1] = y, maintain(x);
        }
    }
    inline void makeRoot(int x, int c) {
        access(x, c), splay(x), pushupCol(x, c), pushupRev(x);
    }
    void build(int u) {
        siz[u] = 1;
        for (auto v : G[u]) if (v != fa[u])
            fa[v] = u, build(v);
    }
}

void dp() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    static int ind[N];
    for (int i = 1; i <= n; i++)
        if ((ind[i] = G[i].size()) == 1) q.push(i);
    while (q.size()) {
        int u = q.top(); q.pop();
        lct::col[u] = ++cnt, bit::modify(cnt, 1);
        for (auto v : G[u]) if ((--ind[v]) == 1) q.push(v);
    }
}

int query(int x) {
    // printf("S: "); for (int i = 1; i <= (n << 2); i++) print(bit::query(i), ' '); putchar('\n');
    lct::splay(x);
    // printf("query %d => %d %d %d\n", x, lct::col[x], bit::query(lct::col[x] - 1), lct::siz[lct::ch[x][0]] + 1);
    return bit::query(lct::col[x] - 1) + lct::siz[lct::ch[x][1]] + 1;
}

void modify(int x) {
    // printf("modify %d : %d\n", x, cnt);
    lct::makeRoot(x, ++cnt);
    // for (int i = 1; i <= n; i++) print(lct::col[i], " \n"[i == n]);
}

void main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) lct::col[i] = 1;
    for (int u, v, i = 1; i < n; i++) {
        read(u), read(v);
        G[u].push_back(v), G[v].push_back(u);
    }
    dp(), lct::build(n);
    // for (int i = 1; i <= n; i++) print(lct::fa[i], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) printf("getRoot(%d) = %d\n", i, lct::getRoot(i));
    for (int i = 1, u, v, op; i <= m; i++) {
        op = getchar();
        if (op == 'u') read(u), modify(u);
        else if (op == 'w') read(u), print(query(u), '\n');
        else read(u), read(v), print(query(u) < query(v) ? u : v, '\n');
    }
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
    freopen("1.in", "r", stdin);
#endif
    return ringo::main(), 0;
}