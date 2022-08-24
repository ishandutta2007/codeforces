#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int h[maxN];
int n, m;
int l[maxN], r[maxN], w[maxN];
int lo[maxN], ri[maxN];
struct node{
    int pref, suf, mx, len;
    node() {
        pref = suf = mx = 0;
        len = 1;
    }
};
node merge(node a, node b) {
    node c;
    c.len = a.len + b.len;
    c.pref = a.pref;
    if (a.pref == a.len) c.pref += b.pref;
    c.suf = b.suf;
    if (b.suf == b.len) c.suf += a.suf;
    c.mx = max({a.mx, b.mx, a.suf + b.pref});
    return c;
}
node t[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = node();
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}
void upd(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v].pref = t[v].suf = t[v].mx = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(2 * v, tl, tm, pos);
    else upd(2 * v + 1, tm + 1, tr, pos);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}
node get(int v, int tl, int tr, int l, int r) {
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(2 * v, tl, tm, l, r);
    else if (l > tm) return get(2 * v + 1, tm + 1, tr, l, r);
    else return merge(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm + 1, tr, tm + 1, r));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        all.emplace_back(h[i], i);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> w[i];
        lo[i] = 0;
        ri[i] = 1e9 + 2;
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int iter = 0; iter < 40; iter++) {
        vector < pair < int, int > > que;
        for (int i = 1; i <= m; i++) {
            if (ri[i] - lo[i] > 1) {
                que.emplace_back((lo[i] + ri[i]) / 2, i);
            }
        }
        sort(que.begin(), que.end());
        reverse(que.begin(), que.end());
        int li = 0;
        build(1, 1, n);
        for (auto it : que) {
            while (li < all.size() && all[li].first >= it.first) {
                upd(1, 1, n, all[li].second);
                li++;
            }
            int id = it.second;
            bool ok = (get(1, 1, n, l[id], r[id]).mx >= w[id]);
            if (ok) lo[id] = it.first;
            else ri[id] = it.first;
        }
    }
    for (int i = 1; i <= m; i++) cout << lo[i] << '\n';
    return 0;
}