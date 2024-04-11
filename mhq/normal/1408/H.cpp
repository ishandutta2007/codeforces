#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
struct ST {
    vector<int> t;
    vector<int> lazy;
    int n;
    ST(int _n) {
        n = _n;
        t.resize(4 * (n + 2));
        lazy.resize(4 * (n + 2));
        build(1, 0, n);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = tl;
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    void upd(int v, int by) {
        lazy[v] += by;
        t[v] += by;
    }

    void merge(int v) {
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    void push(int v, int tl, int tr) {
        if (tl != tr && lazy[v] != 0) {
            upd(2 * v, lazy[v]);
            upd(2 * v + 1, lazy[v]);
        }
        lazy[v] = 0;
    }

    void upd(int v, int tl, int tr, int l, int r, int by) {
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            upd(v, by);
            push(v, tl, tr);
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        upd(2 * v, tl, tm, l, r, by);
        upd(2 * v + 1, tm + 1, tr, l, r, by);
        merge(v);
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> by(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        by[a[i]].emplace_back(i);
    }
    int zer = by[0].size();
    if (zer % 2 == 1) {
        by[0].erase(by[0].begin() + zer / 2);
        zer--;
    }
    assert(by[0].size() % 2 == 0);
    vector<int> zeroes = by[0];
    if (zeroes.empty()) {
        cout << 0 << '\n';
        return;
    }
    vector<pair<int,int>> all;
    for (int i = 1; i <= n; i++) {
        int L = 0;
        int R = 0;
        for (int pos : by[i]) {
            if (pos < zeroes[0] || pos > zeroes.back()) continue;
            int f1 = lower_bound(zeroes.begin(), zeroes.end(), pos) - zeroes.begin();
            if (f1 <= zer / 2 - 1) {
                L = max(L, f1);
            }
            else {
                R = max(R, zer - f1);
            }
        }
        all.emplace_back(L, R);
    }
    sort(all.begin(), all.end());
    ST T(zer / 2);
    int ans = min(zer / 2, (int)all.size());
    for (auto& it : all) {
        T.upd(1, 0, zer / 2, it.second, zer / 2, -1);
        ans = min(ans, it.first + (int)all.size() + T.t[1]);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}