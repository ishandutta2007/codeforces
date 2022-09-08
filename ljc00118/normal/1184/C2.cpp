#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5, V = 1e7 + 5;

int n, m, ans;

struct Point { int x, y; } p[N];

bool operator <(Point u, Point v) { return u.x < v.x; }

struct SegmentTree {
    int rt, tot, ls[V], rs[V], f[V], g[V];

    inline void pushUp(int u) { f[u] = std::max(f[ls[u]], f[rs[u]]) + g[u]; }
    void modify(int &u, int l, int r, int pl, int pr, int x) {
        if (!u) { u = ++tot; }
        if (l == pl && r == pr) { f[u] += x; g[u] += x; return; }
        int mid = l + r >> 1;
        if (pr <= mid) { modify(ls[u], l, mid, pl, pr, x); }
        else if (pl > mid) { modify(rs[u], mid + 1, r, pl, pr, x); }
        else { modify(ls[u], l, mid, pl, mid, x); modify(rs[u], mid + 1, r, mid + 1, pr, x); }
        pushUp(u);
    }
} smt;

int main() {
    n = read(); m = read();
    for (int i = 1, x, y; i <= n; i++) {
        x = read(); y = read();
        p[i] = (Point) {x + y, x - y};
    }
    std::sort(p + 1, p + n + 1);
    for (int i = 1, j = 1; i <= n; i++) {
        smt.modify(smt.rt, -4e6, 4e6, p[i].y - m, p[i].y + m, 1);
        for (; p[j].x + m + m < p[i].x; j++) { smt.modify(smt.rt, -4e6, 4e6, p[j].y - m, p[j].y + m, -1); }
        ans = std::max(ans, smt.f[smt.rt]);
    }
    printf("%d\n", ans);
    return 0;
}