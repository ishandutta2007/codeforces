#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int maxN = 3e5 + 10;
int lazy[4 * maxN];
pair < int, int > t[4 * maxN];
int a[maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(1e9, -tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}
void upd(int v, int by) {
    lazy[v] += by;
    t[v].first += by;
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
    int tm = (tl + tr) /  2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    merge(v);
}
void ch(int v, int tl, int tr, int pos, int val) {
    push(v, tl, tr);
    if (tl == tr) {
        t[v] = make_pair(val, -pos);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm) ch(2 * v, tl, tm, pos, val);
    else ch(2 * v + 1, tm + 1, tr, pos, val);
    merge(v);
}
bool good[maxN];
vector < int > pos[maxN];
vector < int > query[maxN];
int x[maxN], y[maxN];
int ans[maxN];
int when[maxN];
struct Fenwick {
    vector<ll> f;
    int n;

    Fenwick(int _n) {
        n = _n;
        f.resize(_n + 1);
    }

    void upd(int pos, int v) {
        while (pos <= n) {
            f[pos] += v;
            pos = (pos | (pos - 1)) + 1;
        }
    }

    ll get(int r) {
        ll ans = 0;
        while (r > 0) {
            ans += f[r];
            r &= (r - 1);
        }
        return ans;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    memset(when, -1, sizeof when);
    for (int i = n; i >= 1; i--) {
        if (a[i] <= i) {
            ch(1, 1, n, i, i - a[i]);
        }
        while (true) {
            push(1, 1, n);
            auto it = t[1];
            assert(it.first >= 0);
            if (it.first == 0) {
                int ps = -it.second;
                when[ps] = i;
                ch(1, 1, n, ps, 1e9);
                upd(1, 1, n, ps + 1, n, -1);
            }
            else {
                break;
            }
        }
    }
    Fenwick f(n + 1);
    for (int i = 1; i <= n; i++) {
        if (when[i] != -1) {
            pos[when[i] - 1].emplace_back(i);
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i];
        query[x[i]].emplace_back(i);
    }
    for (int i = n; i >= 0; i--) {
        for (int c : pos[i]) {
            f.upd(c, +1);
        }
        for (int id : query[i]) {
            ans[id] = f.get(n - y[id]);
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}