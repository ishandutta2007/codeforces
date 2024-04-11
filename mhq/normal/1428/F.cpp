#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 5e5 + 10;
int tp[maxN];
struct SegmentTree {
    int n;
    vector<ll> t;
    vector<ll> lazy;
    vector<int> len;

    void push(int v, int tl, int tr) {
        if (tl != tr && lazy[v] != 0) {
            apply(2 * v, lazy[v]);
            apply(2 * v + 1, lazy[v]);
        }
        lazy[v] = 0;
    }

    void apply(int v, ll x) {
        t[v] += len[v] * x;
        lazy[v] += x;
    }

    void merge(int v) {
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    void build(int v, int tl, int tr) {
        len[v] = tr - tl + 1;
        if (tl == tr) {
            t[v] = 0;
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        merge(v);
    }

    explicit SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n + 2);
        lazy.resize(4 * n + 2);
        len.resize(4 * n + 2);
        build(1, 1, n);
    }

    void upd(int v, int tl, int tr, int l, int r, ll x) {
        if (tr < l || tl > r) return;
        if (l <= tl && tr <= r) {
            apply(v, x);
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        upd(2 * v, tl, tm, l, r, x);
        upd(2 * v + 1, tm + 1, tr, l, r, x);
        merge(v);
    }

    ll get(int v, int tl, int tr, int l, int r) {
        if (tr < l || tl > r) return 0;
        if (l <= tl && tr <= r) {
            return t[v];
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
    }
};
int f[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') tp[i + 1] = 1;
        else tp[i + 1] = 0;
    }
    ll ans = 0;
    SegmentTree st(n);
    vector<pair<int,int>> all;
    for (int i = 1; i <= n; i++) {
        if (tp[i] == 0) {
            ans += st.get(1, 1, n, 1, i);
            f[i] = 0;
        }
        else {
            f[i] = f[i - 1] + 1;
            st.upd(1, 1, n, i - f[i] + 1, i, +1);
            while (!all.empty() && all.back().first < f[i]) all.pop_back();
            if (all.empty()) {
                st.upd(1, 1, n, 1, i - f[i], +1);
            }
            else {
                int ind = all.back().second;
                assert(f[ind] >= f[i]);
                st.upd(1, 1, n, ind - f[i] + 2, i - f[i], +1);
                while (!all.empty() && all.back().first <= f[i]) all.pop_back();
            }
            all.emplace_back(f[i], i);
            ll p = st.get(1, 1, n, 1, i);
            ans += p;
        }
    }
    cout << ans;
    return 0;
}