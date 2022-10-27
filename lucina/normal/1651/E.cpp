#include<bits/stdc++.h>
using namespace std;
const int nax = 3050;
int n;
array <int, 2> g[nax];
int64_t ans, ans2;
inline bool in_range(int l, int r, int x) {
    return x >= l && x <= r;
}
int c2(int x) {
    return x * (x + 1) / 2;
}
int calc_bound(int x) {
    if (x > n) x -= n;
    return (n - x + 1) * x;
}
int calc_bound(int l, int r) {
    if (l > n) assert(r > n), l -= n, r -= n;
    return c2(n) - c2(r - l - 1) - c2(l - 1) - c2(n - r);
}
int calc_bound_no_ban(int l, int r) {
    if (l > n) assert(r > n), l -= n, r -= n;
    return (n - r + 1) * l;
}
int calc_bound(int l, int r, int ban1, int ban2) {
    if (l > n) l -= n, r -= n, ban1 -= n, ban2 -= n;
    if (in_range(l, r, ban1) || in_range(l, r, ban2)) return 0;
    int lft_bound = 1, rgt_bound = n;
    if (ban1 < l) lft_bound = max(lft_bound, ban1 + 1);
    if (ban2 < l) lft_bound = max(lft_bound, ban2 + 1);
    if (ban1 > r) rgt_bound = min(rgt_bound, ban1 - 1);
    if (ban2 > r) rgt_bound = min(rgt_bound, ban2 - 1);
    return (l - lft_bound + 1) * (rgt_bound - r + 1);
}

/**
    for every vertex, we're going to do dfs...
    to understand how many ranges, this vertex is the end point of odd component

    x1 -> y1 -> x2
    it gonna end at x2 <->
    let's range represent other sides be [l, r]

    x_other is not in range [l, r]
    x2 other is not in range [l, r]
    and the range in this side
    is at least contain all x', keep min and max
*/

inline int go(int x, int from) {
    return g[x][0] ^ g[x][1] ^ from;
}

int64_t dfs(int x, int to) {
    int other = go(x, to);
    int cur = x, from = other;
    int lu = 2 * n + 1, ru = 0;
    int ld = 2 * n + 1, rd = 0;
    ld = min(ld, cur); rd = max(rd, cur);
    int ban1 = other, ban2;
    int64_t ans = 0;
    while (true) {
        int lst_cur = cur;
        cur = go(cur, from);
        from = lst_cur;
        lu = min(lu, cur); ru = max(ru, cur);
        lst_cur = cur;
        cur = go(cur, from);
        from = lst_cur;
        if (cur == x) break;
        ld = min(ld, cur); rd = max(rd, cur);
        ban2 = go(cur, from);
        int64_t f = calc_bound(lu, ru, ban1, ban2);
        ans += f * calc_bound_no_ban(ld, rd);
    }
    return ans;
}


int main() {
    cin >> n;
    for (int i = 1 ; i <= 2 * n ; ++ i) {
        int u, v;
        cin >> u >> v;
        (g[u][0] ? g[u][1] : g[u][0]) = v;
        (g[v][0] ? g[v][1] : g[v][0]) = u;
    }
    for (int i = 1 ; i <= 2 * n ; ++ i) {
        if (g[i][0] > g[i][1]) swap(g[i][0], g[i][1]);
        ans += 1ll * calc_bound(i) * calc_bound(g[i][0], g[i][1]);
    }
    for (int i = 1 ; i <= 2 * n ; ++ i) {
        ans2 += dfs(i, g[i][0]);
        ans2 += dfs(i, g[i][1]);
    }

    cout << (ans - (ans2 / 2)) / 2 << '\n';
}