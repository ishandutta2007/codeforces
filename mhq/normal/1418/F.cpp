#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 2e5 + 10;
vector < int > his_divs[maxN];

struct SegmentTree {
    int n;
    int merge(int x, int y) {
        return max(x, y);
    }
    vector<int> t;
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = 0;
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
    SegmentTree(int n) {
        t.resize(4 * n + 2);
        build(1, 1, n);
    }
    void upd(int v, int tl, int tr, int pos, int x) {
        if (tl == tr) {
            t[v] = x;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) upd(2 * v, tl, tm, pos, x);
        else upd(2 * v + 1, tm + 1, tr, pos, x);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        if (r <= tm) return get(2 * v, tl, tm, l, r);
        else if (l > tm) return get(2 * v + 1, tm + 1, tr, l, r);
        else {
            return merge(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm + 1, tr, tm + 1, r));
        }
    }
};
#define y1 niceround
ll x2[maxN], y1[maxN], y2[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    ll l, r;
    cin >> l >> r;
    for (int b = 1; b <= n; b++) {
        for (int c = b; c <= m; c += b) {
            his_divs[c].emplace_back(b);
        }
    }
    for (int i = 1; i <= m; i++) {
        sort(his_divs[i].begin(), his_divs[i].end());
    }
    SegmentTree sg(m);
    const int INF = 1e9;
    for (int i = 1; i <= m; i++) {
        if (his_divs[i].empty()) {
            sg.upd(1, 1, m, i, -INF);
        }
        else {
            sg.upd(1, 1, m, i, his_divs[i].back());
        }
    }



    memset(x2, -1, sizeof x2);
    for (int d = 1; d <= n; d++) {
        if (d != 1) {
            int lst = (n / (d - 1));
            for (int c = lst; c > n / d; c--) {
                for (int v = c; v <= m; v += c) {
                    assert(!his_divs[v].empty() && his_divs[v].back() == c);
                    his_divs[v].pop_back();
                    if (his_divs[v].empty()) {
                        sg.upd(1, 1, m, v, -INF);
                    }
                    else {
                        sg.upd(1, 1, m, v, his_divs[v].back());
                    }
                }
            }
        }
        for (int x1 = d; x1 <= n; x1 += d) {
            ll lower = ((l + x1 - 1) / x1);
            ll upper = min((ll)m, r / x1);
            if (lower > upper) continue;
            int l2 = x1 / d + 1;
            int p = sg.get(1, 1, m, (int)lower, (int)upper);
            if (p >= l2) {
                assert(p <= n / d);
                ll cy = (lower + p - 1) / p;
                y1[x1] = p * cy;
                x2[x1] = d * p;
                y2[x1] = (x1 / d) * cy;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (x2[i] == -1) {
            cout << -1 << '\n';
        }
        else {
            cout << i << " " << y1[i] << " " << x2[i] << " " << y2[i] << '\n';
            assert(i < x2[i] && x2[i] <= n);
            assert(m >= y1[i] && y1[i] > y2[i]);
            assert(i * y1[i] == x2[i] * y2[i]);
        }
    }
    return 0;
}