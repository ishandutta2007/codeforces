#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 2 * (int)1e4 + 100;
vector < pair < ll, ll > > cht[4 * maxN];
struct pt{
    ll x, y;
    pt(ll _x, ll _y) {
        x = _x;
        y = _y;
    }
    pt() {}
};
vector < pt > all[4 * maxN];
bool del(const pt& x, const pt& y, const pt& z) {
    return (y.y - x.y) * (x.x - z.x) <= (z.y - x.y) * (x.x - y.x);
}
void add(ll x, ll y, vector < pt >& vec) {
    pt nw(x, y);
    while (vec.size() >= 2 && del(vec[vec.size() - 1], vec[vec.size() - 2], nw)) {
        vec.pop_back();
    }
    vec.push_back(nw);
}
ll get(const pt& a, ll y) {
    return (a.x * y + a.y);
}
const ll INF = 2 * (ll)1e18;
ll get(ll x, vector < pt >& vec) {
    if (vec.empty()) return -INF;
    int l = 0;
    int r = vec.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (get(vec[m], x) > get(vec[m + 1], x)) {
            r = m;
        }
        else l = m;
    }
    return max(get(vec[r], x), get(vec[l], x));
}
void add(int v, int tl, int tr, int l, int r, pair < ll, ll >& who) {
    if (tl == l &&  tr == r) {
        cht[v].push_back(who);
        return;
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) {
        add(v + v, tl, tm, l, r, who);
    }
    else if (l > tm) {
        add(v + v + 1, tm + 1, tr, l, r, who);
    }
    else {
        add(v + v, tl, tm, l, tm, who);
        add(v + v + 1, tm + 1, tr, tm + 1, r, who);
    }
}
void ch() {
    for (int i = 1; i <= 4 * n; i++) {
        cht[i].clear();
        all[i].clear();
    }
}
void build(int v, int tl, int tr) {
    sort(cht[v].begin(), cht[v].end());
    reverse(cht[v].begin(), cht[v].end());
    for (auto t : cht[v]) {
        add(-t.first, -t.second, all[v]);
    }
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        build(v + v, tl, tm);
        build(v + v + 1, tm + 1, tr);
    }
}
ll get(int v, int tl, int tr, int pos, ll val) {
    ll f1 = -get(val, all[v]);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm) f1 = min(f1, get(v + v, tl, tm, pos, val));
        else f1 = min(f1, get(v + v + 1, tm + 1, tr, pos, val));
    }
    return f1;
}


ll dp[maxN];
int a[maxN];
int nxt[maxN];
ll coefs[maxN];

vector < pt > lines[4 * maxN];
pair < ll, ll > ss[4 * maxN];
void build2(int v, int tl, int tr) {
    vector < pair < ll, ll > > all;
    for (int i = tl; i <= tr; i++) {
        all.push_back(ss[i]);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (auto it : all) {
        add(-it.first, -it.second, lines[v]);
    }
    int tm = (tl + tr) / 2;
    if (tl != tr) {
        build2(v + v, tl, tm);
        build2(v + v + 1, tm + 1, tr);
    }
}
ll get_val(int v, int tl, int tr, int l, int r, ll val) {
    if (tl == l && tr == r) {
        return -get(val, lines[v]);
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) return get_val(v + v, tl, tm, l, r, val);
    else if (l > tm) return get_val(v + v + 1, tm + 1, tr, l, r, val);
    else {
        return min(get_val(v + v, tl, tm, l, tm, val), get_val(v + v + 1, tm + 1, tr, tm + 1, r, val));
    }
}
int en[maxN];
void solve() {
    vector < pair < int, int > > st;
    st.push_back(make_pair(1e9, 0));
    for (int i = 1; i <= 4 * n; i++) lines[i].clear();
    for (int i = 1; i <= n; i++) {
        ss[i] = make_pair(-(i - 1), dp[i - 1]);
    }
    build2(1, 1, n);
    for (int i = 1; i <= n; i++) {
        while (make_pair(a[i], i) > st.back()) {
            st.pop_back();
        }
        nxt[i] = st.back().second;
        st.push_back(make_pair(a[i], i));
    }
    for (int i = 1; i <= n; i++) {
        coefs[i] = get_val(1, 1, n, nxt[i] + 1, i, a[i]);
    }
    ch();
    st.clear();
    st.push_back(make_pair(1e9, 0));
    //cout << " Here" << endl;
    for (int i = 1; i <= n; i++) {
        while (make_pair(a[i], i) > st.back()) {
            en[st.back().second] = i - 1;
            st  .pop_back();
        }
        st.push_back(make_pair(a[i], i));
    }
    while (!st.empty()) {
        en[st.back().second] = n;
        st.pop_back();
    }
    //cout << " Here" << endl;
    for (int i = 1; i <= n; i++) {
        pair < ll, ll > tt = make_pair(a[i], coefs[i]);
        add(1, 1, n, i, en[i], tt);
    }
    build(1, 1, n);
    dp[0] = 1e9;
    for (int i = 1; i <= n; i++) {
        dp[i] = get(1, 1, n, i, i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = (ll)1e9;
    }
    for (int i = 0; i < k; i++) {
        solve();
    }
    cout << dp[n];
    return 0;
}