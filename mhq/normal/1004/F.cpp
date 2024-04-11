#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
int x;
struct node{
    vector < pair < int, int > > suf, pref;
    ll cnt;
    node(int a) {
        suf.emplace_back(a, 1);
        pref.emplace_back(a, 1);
        cnt = 0;
        if (a >= x) cnt++;
    }
    node() {
        cnt = 0;
    }
};
node merge(const node& a, const node& b) {
    node c;
    c.pref = a.pref;
    int lst = c.pref.back().first;
    for (int i = 0; i < b.pref.size(); i++) {
        int val = lst | b.pref[i].first;
        if (val != c.pref.back().first) c.pref.emplace_back(val, b.pref[i].second);
        else c.pref.back().second += b.pref[i].second;
    }
    c.suf = b.suf;
    lst = c.suf.back().first;
    for (int i = 0; i < a.suf.size(); i++) {
        int val = lst | a.suf[i].first;
        if (val != c.suf.back().first) c.suf.emplace_back(val, a.suf[i].second);
        else c.suf.back().second += a.suf[i].second;
    }
    // merge ans
    c.cnt = a.cnt + b.cnt;
    int r = (int)b.pref.size() - 1;
    int tot = 0;
    for (auto& it : a.suf) {
        // [b.size(), r)
        while (r >= 0 && ((it.first | b.pref[r].first) >= x)) {
            tot += b.pref[r].second;
            r--;
        }
        c.cnt += 1LL * it.second * tot;
    }
    return c;
}
const int maxN = (int)1e5 + 100;
int a[maxN];
node t[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = node(a[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}
void upd(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = node(a[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(2 * v, tl, tm, pos);
    else upd(2 * v + 1, tm + 1, tr, pos);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}
node get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(2 * v, tl, tm, l, r);
    else if (l > tm) return get(2 * v + 1, tm + 1, tr, l, r);
    else return merge(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm + 1, tr, tm + 1, r));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int pos, y;
            cin >> pos >> y;
            a[pos] = y;
            upd(1, 1, n, pos);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r).cnt << '\n';
        }
    }
    return 0;
}