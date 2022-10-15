#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }
#define answerExit(answer) { cout << (answer) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}


template<typename T, typename U>
struct SegmentTree {
    int n;
    T neutral;
    U unite;
    vector<T> data;

    template<typename I>
    SegmentTree(int sz, T neutral, U unite, I init) : n(2 << __lg(max(1, sz - 1))), neutral(neutral), unite(unite),
                                                      data(2 * n) {
        for (int i = 0; i < sz; ++i) data[i + n] = init(i);
        for (int i = n - 1; i > 0; --i) data[i] = unite(data[2 * i], data[2 * i + 1]);
    }

    SegmentTree(int sz, T neutral, U unite) : n(2 << __lg(max(1, sz - 1))), neutral(neutral), unite(unite),
                                              data(2 * n, neutral) {}

    template<typename C>
    void set(int i, C x) {
        data[i += n] = x;
        for (i /= 2; i > 0; i /= 2) data[i] = unite(data[2 * i], data[2 * i + 1]);
    }

    T get(int l, int r) {
        T leftRes = neutral, rightRes = neutral;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) leftRes = unite(leftRes, data[l++]);
            if (r & 1) rightRes = unite(data[--r], rightRes);
        }
        return unite(leftRes, rightRes);
    }

    template<typename C>
    int lastTrue(int l, C ok) {
        if (l == n) return n;
        T cur = neutral;
        l += n;
        do {
            l >>= __builtin_ctz(l);
            T with1 = unite(cur, data[l]);
            if (ok(with1)) {
                cur = with1;
                ++l;
            } else {
                while (l < n) {
                    T with2 = unite(cur, data[2 * l]);
                    if (ok(with2)) {
                        cur = with2;
                        l = 2 * l + 1;
                    } else {
                        l = 2 * l;
                    }
                }
                return l - n;
            }
        } while (l & (l - 1));
        return n;
    }

    template<typename C>
    int firstTrue(int r, C ok) {
        if (r == 0) return 0;
        T cur = neutral;
        r += n;
        do {
            r >>= __builtin_ctz(r);
            T with1 = unite(data[--r], cur);
            if (ok(with1)) {
                cur = with1;
            } else {
                while (r < n) {
                    T with2 = unite(data[2 * r + 1], cur);
                    if (ok(with2)) {
                        cur = with2;
                        r = 2 * r;
                    } else {
                        r = 2 * r + 1;
                    }
                }
                return r - n + 1;
            }
        } while (r & (r - 1));
        return 0;
    }
};

struct query {
    int l, r, idx, low, high;
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> size(n, 1);
    vector<vector<int>> children(n);
    SegmentTree color(n, pair{n, -1},
                      [](auto p, auto q) { return pair{min(p.first, q.first), max(p.second, q.second)}; },
                      [](int i) { return pair{i, i}; });
    vector<vector<pair<int, int>>> segments(m);
    for (int i = 0; i < m; ++i) {
        auto recolor = [&](auto recolor, int cur, int c) -> void {
            color.set(cur, pair{c, c});
            int l = color.firstTrue(cur, [&](auto p) { return p == pair{c, c}; });
            int r = color.lastTrue(cur, [&](auto p) { return p == pair{c, c}; });
            segments[i].emplace_back(l, r);
            for (int nxt: children[cur]) recolor(recolor, nxt, c);
        };
        int u, v;
        cin >> u >> v;
        --u, --v;
        int cu = color.get(u, u + 1).first;
        int cv = color.get(v, v + 1).first;
        if (cu == cv) continue;
        if (size[cu] > size[cv]) {
            swap(cu, cv);
            swap(u, v);
        }
        size[cv] += size[cu];
        children[cv].push_back(cu);
        recolor(recolor, cu, cv);
    }
    vector<query> qs(q);
    vector<vector<query>> buckets(m);
    vector<int> ans(q);
    for (int j = 0; j < q; ++j) {
        cin >> qs[j].l >> qs[j].r;
        qs[j].idx = j;
        qs[j].low = -1, qs[j].high = m;
        buckets[(qs[j].low + qs[j].high) / 2].emplace_back(qs[j]);
    }
    while (true) {
        vector<vector<query>> newBuckets(m);
        bool end = true;
        SegmentTree mt(n, 0, [](auto p, auto q) { return max(p, q); }, [](int i) { return i + 1; });
        for (int i = 0; i < m; ++i) {
            for (auto qr: buckets[i]) {
                if (mt.get(0, qr.l) >= qr.r) {
                    qr.high = i;
                } else {
                    qr.low = i;
                }
                if (qr.high - qr.low > 1) {
                    end = false;
                    newBuckets[(qr.low + qr.high) / 2].emplace_back(qr);
                } else {
                    ans[qr.idx] = qr.high;
                }
            }
            for (auto[l, r]: segments[i]) mt.set(l, r);
        }
        if (end) break;
        buckets = newBuckets;
    }
    for (int x: ans) cout << x << ' ';
    cout << '\n';
}