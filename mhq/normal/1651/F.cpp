#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int n, q;
ll c[maxN], r[maxN];
ll t[maxN];
ll h[maxN];
ll mn_start[4 * maxN];
ll mx_start[4 * maxN];
const ll INF = 2e9;
vector<pair<ll,ll>> all[4 * maxN];
vector<ll> cords[4 * maxN];

bool not_bad[4 * maxN];
ll ti[maxN];
ll delta[maxN];
void build(int v, int tl, int tr) {
    mn_start[v] = -INF;
    mx_start[v] = -INF;
    not_bad[v] = true;
    vector<pair<ll,int>> f;
    f.emplace_back(0, -1);
    ll s_all = 0;
    for (int i = tl; i <= tr; i++) {
        f.emplace_back((c[i] + r[i] - 1) / r[i], i);
        s_all += r[i];
    }
    sort(f.begin(), f.end());
    cords[v].resize(f.size());
    for (int z = 0; z < f.size(); z++) cords[v][z] = f[z].first;
//    all[v].resize(f.size());
    ll cur = 0;
    for (int z = 0; z < f.size(); z++) {
        if (z > 0) {
            s_all -= r[f[z].second];
            cur += c[f[z].second];
        }
        all[v].emplace_back(make_pair(cur, s_all));
    }
    int tm = (tl + tr) / 2;
    if (tl != tr) {
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
    }
}
void push(int v, int tl, int tr) {
    if (tl != tr) {
        mn_start[2 * v] = max(mn_start[2 * v], mn_start[v]);
        mx_start[2 * v] = max(mx_start[2 * v], mn_start[v]);
        mn_start[2 * v + 1] = max(mn_start[2 * v + 1], mn_start[v]);
        mx_start[2 * v + 1] = max(mx_start[2 * v + 1], mn_start[v]);
    }
}
void merge(int v) {
    mn_start[v] = min(mn_start[2 * v], mn_start[2 * v + 1]);
    mx_start[v] = max(mx_start[2 * v], mx_start[2 * v + 1]);
    not_bad[v] = (not_bad[2 * v] & not_bad[2 * v + 1]);
}
void go(int v, int tl, int tr, ll t, ll& h) {
    if (tl == tr) {
        ll s;
        if (!not_bad[v]) {
            s = min((t - ti[tl]) * r[tl] + (delta[tl]), c[tl]);
        }
        else {
            s = min((t - mn_start[v]) * r[tl], c[tl]);
        }
        if (s >= h) {
            not_bad[v] = false;
            delta[tl] = s - h;
            ti[tl] = t;
            h = 0;
        }
        else {
            h -= s;
            not_bad[v] = true;
            mn_start[v] = mx_start[v] = t;
        }
        return;
    }
    if (mn_start[v] == mx_start[v] && not_bad[v]) {
        auto res = lower_bound(cords[v].begin(), cords[v].end(), (t - mn_start[v]) + 1) - cords[v].begin();
        res--;
        ll cur_h = all[v][res].first + (t - mn_start[v]) * all[v][res].second;
        if (cur_h <= h) {
            h -= cur_h;
            mn_start[v] = mx_start[v] = t;
            return;
        }
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    go(2 * v, tl, tm, t, h);
    if (h != 0) {
        go(2 * v + 1, tm + 1, tr, t, h);
    }
    merge(v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> r[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    ll ans = 0;
    while (q--) {
        ll t, h;
        cin >> t >> h;
        go(1, 1, n, t, h);
//        cout << h << endl;
//        cout << t << " " << h << " ? " << endl;
        ans += h;
    }
    cout << ans << '\n';
    return 0;
}