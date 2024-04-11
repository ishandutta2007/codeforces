#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct point {
    int x, w;

    point() {}

    point(int x, int w) : x(x), w(w) {}
};

#define int ll

struct MaxTree {
    int n;
    vector<int> mx;

    MaxTree(int n) : n(n), mx(2 * n, LONG_LONG_MAX) {}

    void set(int i, int x) {
        mx[i + n] = min(mx[i + n], x);
        i += n;
        for (i /= 2; i > 0; i /= 2) mx[i] = ::min(mx[2 * i], mx[2 * i + 1]);
    }

    int get(int l, int r) {
        int res = LONG_LONG_MAX;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = min(res, mx[l++]);
            if (r & 1) res = min(res, mx[--r]);
        }
        return res;
    }
};

struct query {
    int l, r, i;

    query(int l, int r, int i) : l(l), r(r), i(i) {}

    query() {}
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<point> p(n);
    for (auto &[x, w]: p) cin >> x >> w;
    vector<int> stack;
    vector<vector<int>> pairs(n);
    for (int i = 0; i < n; ++i) {
        while (stack.size() && p[stack.back()].w >= p[i].w) {
            pairs[stack.back()].push_back(i);
            stack.pop_back();
        }
        if (stack.size()) {
            pairs[stack.back()].push_back(i);
        }
        stack.push_back(i);
    }
    vector<query> qu(q);
    for (auto&[l, r, i]: qu) cin >> l >> r;
    for (auto&[l, r, i]: qu)--l;
    for (int i = 0; i < q; ++i) qu[i].i = i;
    sort(qu.begin(), qu.end(), [](auto u, auto v) { return u.l > v.l; });
    MaxTree ans(n);
    vector<int> ansq(q);
    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int r: pairs[i]) {
            ans.set(r, abs(p[r].x - p[i].x) * 1LL * (p[r].w + p[i].w));
        }
        while (qu.size() > cur && qu[cur].l == i) ansq[qu[cur].i] = ans.get(0, qu[cur].r),cur++;
    }
    for (int &x: ansq) cout << x << ' ';
}