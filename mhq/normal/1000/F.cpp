#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 5 * (int)1e5 + 10;
int nxt[maxN];
int prv[maxN], a[maxN], cnt[maxN], ans[maxN];
vector < pair < int, int > > que[maxN];
pair < int, int > t[4 * maxN];
void build(int v, int l, int r) {
    int mid = (l + r) / 2;
    t[v] = make_pair(maxN, 0);
    if (l == r) return;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
}
void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = make_pair(val, pos);
        return ;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(2 * v, tl, tm, pos, val);
    else upd(2 * v + 1, tm + 1, tr, pos, val);
    if (t[2 * v].first <= t[2 * v + 1].first) t[v] = t[2 * v];
    else t[v] = t[2 * v + 1];
}
pair < int, int > get_min(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get_min(2 * v, tl, tm, l, r);
    if (l > tm) return get_min(2 * v + 1, tm + 1, tr, l, r);
    pair < int, int > mn1 = get_min(2 * v, tl, tm, l, tm);
    pair < int, int > mn2 = get_min(2 * v + 1, tm + 1, tr, tm + 1, r);
    if (mn1.first < mn2.first) return mn1;
    else return mn2;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < maxN; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        prv[i] = cnt[a[i]];
        cnt[a[i]] = i;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        que[r].push_back(make_pair(l, i));
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        upd(1, 1, n, i, prv[i]);
        if (prv[i] != 0) upd(1, 1, n, prv[i], maxN);
        for (int j = 0; j < que[i].size(); j++) {
            pair < int, int > tt = get_min(1, 1, n, que[i][j].first, i);
            if (que[i][j].first > tt.first) ans[que[i][j].second] = a[tt.second];
            else ans[que[i][j].second] = 0;
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}