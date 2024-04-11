#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 100;
int lazy[4 * maxN];
const int T0 = 0;
const int T1 = 1;
const int TX = 2;
const int TN = 3;
int n;
int rtp[maxN];
int a[maxN];
int id[maxN];
int tp[maxN];
int q;
vector < pair < int, int > > all;
const int INF = (int)1e5 + 112412;
void upd(int& mod1, int mod2) {
    if (mod1 == TN) {
        mod1 = mod2;
        return ;
    }
    if (mod2 == T0 || mod2 == T1) {
        mod1 = mod2;
        return ;
    }
    if (mod1 == TX && mod2 == TX) {
        mod1 = TN;
        return ;
    }
    if (mod2 == TX) {
        mod1 = T0 + T1 - mod1;
        return ;
    }
    if (mod2 == TN) {
        return ;
    }
}
void push(int v, int l, int r) {
    if (l != r) {
        upd(lazy[v + v], lazy[v]);
        upd(lazy[v + v + 1], lazy[v]);
        lazy[v] = TN;
    }
}
void build(int v, int tl, int tr) {
    lazy[v] = TN;
    if (tl == tr) {
        if (tp[tl]) lazy[v] = T1;
        else lazy[v] = T0;
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
}
void upd(int v, int tl, int tr, int l, int r, int MOD) {
    push(v, tl, tr);
    if (l > r) return ;
    if (tl == l && tr == r) {
        upd(lazy[v], MOD);
        push(v, tl, tr);
        return ;
    }
    int tm = (tl + tr) / 2;
    upd(v + v, tl, tm, l, min(tm, r), MOD);
    upd(v + v + 1, tm + 1, tr, max(l, tm + 1), r, MOD);
}
int ans[maxN];
void scan(int v, int tl, int tr) {
    if (tl == tr) {
        ans[tl] = lazy[v];
        assert(lazy[v] == T0 || lazy[v] == T1);
        return ;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    scan(v + v, tl, tm);
    scan(v + v + 1, tm + 1, tr);
}
void go(int x) {
    auto ind = lower_bound(all.begin(), all.end(), make_pair(x + 1, -10 * INF)) - all.begin();
    if (ind == all.size()) return ;
    if (all[ind].second < 0) {
        int rind = id[-(all[ind].second + n)];
        if (rind + 1 <= n) upd(1, 1, n, rind + 1, n, T0);
        upd(1, 1, n, 1, rind, TX);
    }
    else {
        int rind = id[all[ind].second];
        upd(1, 1, n, rind, n, T0);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 0) rtp[i] = 1;
        else {
            a[i] = -a[i];
            rtp[i] = 0;
        }
        all.push_back(make_pair(a[i], i));
        all.push_back(make_pair(-a[i], -i - n));
    }
    sort(all.begin(), all.end());
    int sz = 1;
    for (int i = 0; i < all.size(); i++) {
        if (all[i].second >= 1) {
            id[all[i].second] = sz;
            tp[sz] = rtp[all[i].second];
            sz++;
        }
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        char c;
        cin >> c;
        int x;
        cin >> x;
        if (c == '<') {
            go(-INF);
            x = -x;
            go(x);
            go(-INF);
        }
        else {
            go(x);
        }
    }
    scan(1, 1, n);
    for (int i = 1; i <= n; i++) {
        if (ans[id[i]]) cout << a[i] << " ";
        else cout << -a[i] << " ";
    }
    return 0;
}