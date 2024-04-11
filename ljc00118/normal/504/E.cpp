#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 3e5 + 5, md1 = 998244353, md2 = 98765431, base1 = 101, base2 = 103;

struct info {
    int h1, h2;
    info (int a = 0, int b = 0) : h1(a), h2(b) {}
} s[N], rs[N], pw[N];

info operator + (const info a, const info b) {
    return info((a.h1 + b.h1) % md1, (a.h2 + b.h2) % md2);
}

info operator - (const info a, const info b) {
    return info((a.h1 - b.h1 + md1) % md1, (a.h2 - b.h2 + md2) % md2);
}

info operator * (const info a, const info b) {
    return info(1ll * a.h1 * b.h1 % md1, 1ll * a.h2 * b.h2 % md2);
}

bool operator == (const info a, const info b) {
    return (a.h1 == b.h1 && a.h2 == b.h2);
}

vector <int> adj[N];
int fa[N], d[N], tops[N], pre[N], top[N], siz[N], wson[N];
char c[N];
int n, m, dfn;

void dfs1(int u) {
	siz[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[u]) continue;
        fa[v] = u; d[v] = d[u] + 1;
        dfs1(v); siz[u] += siz[v];
        if (siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    tops[u] = ++dfn; pre[dfn] = u; top[u] = tp;
    if (wson[u]) dfs2(wson[u], tp);
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}

vector <pii> getpath(int u, int v) {
    vector <pii> pu, pv;
    while (top[u] != top[v]) {
        if (d[top[u]] > d[top[v]]) {
            pu.push_back(make_pair(tops[u], tops[top[u]]));
            u = fa[top[u]];
        } else {
            pv.push_back(make_pair(tops[top[v]], tops[v]));
            v = fa[top[v]];
        }
    }
    pu.push_back(make_pair(tops[u], tops[v]));
    for (int i = (int)pv.size() - 1; i >= 0; i--) pu.push_back(pv[i]);
    return pu;
}

info gethash(int l, int r) {
    if (l <= r) {
        return s[r] - s[l - 1] * pw[r - l + 1];
    } else {
        return rs[r] - rs[l + 1] * pw[l - r + 1];
    }
}

int getlen(pii a) {
    return abs(a.first - a.second) + 1;
}

int main() {
    read(n); scanf("%s", c + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1); dfs2(1, 1);
    pw[0] = info(1, 1);
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * info(base1, base2);
        s[i] = s[i - 1] * info(base1, base2) + info(c[pre[i]], c[pre[i]]);
    }
    for (int i = n; i >= 1; i--) rs[i] = rs[i + 1] * info(base1, base2) + info(c[pre[i]], c[pre[i]]);
    read(m);
    for (int _ = 1; _ <= m; _++) {
        int a, b, c, d, ans = 0;
        read(a); read(b); read(c); read(d);
        vector <pii> p1 = getpath(a, b), p2 = getpath(c, d);
        int q1 = 0, q2 = 0, l1 = 0, l2 = 0;
        // fprintf(stderr, "p1.size() = %d, p2.size() = %d\n", (int)p1.size(), (int)p2.size());
        // for (int i = 0; i < (int)p1.size(); i++) fprintf(stderr, "{%d, %d}, ", p1[i].first, p1[i].second);
        // fprintf(stderr, "\n");
        // for (int i = 0; i < (int)p2.size(); i++) fprintf(stderr, "{%d, %d}, ", p2[i].first, p2[i].second);
        // fprintf(stderr, "\n");
        if (p1.size() > 40 || p2.size() > 40) print(p1.size(), ' '), print(p2.size(), '\n');
        while (q1 < (int)p1.size() && q2 < (int)p2.size()) {
            int len = min(getlen(p1[q1]) - l1, getlen(p2[q2]) - l2);
            info h1, h2;
            if (p1[q1].first <= p1[q1].second) h1 = gethash(p1[q1].first + l1, p1[q1].first + l1 + len - 1);
            else h1 = gethash(p1[q1].first - l1, p1[q1].first - l1 - len + 1);
            if (p2[q2].first <= p2[q2].second) h2 = gethash(p2[q2].first + l2, p2[q2].first + l2 + len - 1);
            else h2 = gethash(p2[q2].first - l2, p2[q2].first - l2 - len + 1);
            if (h1 == h2) {
                l1 += len; l2 += len; ans += len;
                if (l1 == getlen(p1[q1])) ++q1, l1 = 0;
                if (l2 == getlen(p2[q2])) ++q2, l2 = 0;
            } else {
                int l = 1, r = len - 1, res = 0;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (p1[q1].first <= p1[q1].second) h1 = gethash(p1[q1].first + l1, p1[q1].first + l1 + mid - 1);
                    else h1 = gethash(p1[q1].first - l1, p1[q1].first - l1 - mid + 1);
                    if (p2[q2].first <= p2[q2].second) h2 = gethash(p2[q2].first + l2, p2[q2].first + l2 + mid - 1);
                    else h2 = gethash(p2[q2].first - l2, p2[q2].first - l2 - mid + 1);
                    if (h1 == h2) res = mid, l = mid + 1;
                    else r = mid - 1;
                }
                ans += res; break;
            }
        }
        print(ans, '\n');
    }
    return 0;
}