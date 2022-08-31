#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1e5 + 10;
int a[maxN];

ll t[4 * maxN];
ll lazy[4 * maxN];


void apply(int v, ll x) {
    t[v] += x;
    lazy[v] += x;
}

void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v] != 0) {
        apply(2 * v, lazy[v]);
        apply(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}

void merge(int v) {
    t[v] = min(t[2 * v], t[2 * v + 1]);
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
    if (tr < l || tl > r) return 1e18;
    if (l <= tl && tr <= r) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void solve() {
    cin >> n >> m;
    const int maxP = 100000;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(1, 1, maxP, 1, a[i], +1);
    }
    vector<vector<int>> groups;
    vector<ll> sm;
    for (int i = 1; i <= m; i++) {
        int sz;
        cin >> sz;
        vector<int> t(sz);
        ll S = 0;
        for (int x = 0; x < sz; x++) {
            cin >> t[x];
            S += t[x];
        }
        groups.emplace_back(t);
        sm.emplace_back(S);
    }
    vector<ll> ari;
    for (int i = 0; i < m; i++) {
        ll s = (sm[i] + groups[i].size() - 1) / groups[i].size();
        assert(s <= maxP);
        upd(1, 1, maxP, 1, s, -1);
        ari.emplace_back(s);
    }
    for (int i = 0; i < m; i++) {
        upd(1, 1, maxP, 1, ari[i], +1);
        for (int c = 0; c < groups[i].size(); c++) {
            ll new_s = (sm[i] - groups[i][c] + groups[i].size() - 2) / (groups[i].size() - 1);
            upd(1, 1, maxP, 1, new_s, -1);
            if (t[1] >= 0) cout << 1;
            else cout << 0;
            upd(1, 1, maxP, 1, new_s, +1);
        }
        upd(1, 1, maxP, 1, ari[i], -1);
    }

    for (int i = 1; i <= n; i++) {
        upd(1, 1, maxP, 1, a[i], -1);
    }
    for (int i = 0; i < m; i++) {
        upd(1, 1, maxP, 1, ari[i], +1);
    }
    cout << '\n';

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