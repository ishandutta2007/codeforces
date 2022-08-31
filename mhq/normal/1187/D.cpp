#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int b[maxN];
int t[4 * maxN];
int a[maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = min(t[v + v], t[v + v + 1]);
}
void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(v + v, tl, tm, pos, val);
    else upd(v + v + 1, tm + 1, tr, pos, val);
    t[v] = min(t[v + v], t[v + v + 1]);
}
const int INF = (int)1e9 + 100;
int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (tl == l && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(v + v, tl, tm, l, min(r, tm)), get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        set < pair < int, int > > s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s.insert(make_pair(a[i], i));
        }
        bool ok = true;
        build(1, 1, n);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (!ok) continue;
            auto it = s.lower_bound(make_pair(b[i], -1));
            if (it == s.end() || ((it -> first) != b[i])) {
                ok = false;
                continue;
            }
            int ind = (it -> second);
            s.erase(it);
            if (b[i] != get(1, 1, n, 1, ind)) {
                ok = false;
            }
            upd(1, 1, n, ind, INF);
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}