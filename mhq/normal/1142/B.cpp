#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
int n, m, q;
const int maxN = 2 * (int)1e5 + 100;
int p[maxN];
int a[maxN];
vector < int > all[maxN];
int nxt[maxN];
int l[maxN], r[maxN];
int nxt_pos[maxN];
int ansR[maxN];
int ansL[maxN];
bool ok[maxN];
int prv[maxN];
void solve1() {
    int best = 1;
    for (int i = 1; i <= n; i++) {
        if (all[i].size() < all[best].size()) {
            best = i;
        }
    }
    for (auto t : all[best]) {
        int x = best;
        ansR[t] = ansL[t] = 1;
        int need = nxt[best];
        for (int j = t + 1; j <= m; j++) {
            ansR[j] = ansR[j - 1];
            if (a[j] == need) {
                need = nxt[a[j]];
                ansR[j]++;
            }
        }
        need = prv[best];
        for (int j = t - 1; j >= 1; j--) {
            ansL[j] = ansL[j + 1];
            if (a[j] == need) {
                need = prv[a[j]];
                ansL[j]++;
            }
        }
        for (int i = 1; i <= q; i++) {
            if (ok[i]) continue;
            if (t < l[i] || t > r[i]) continue;
            if (ansR[r[i]] + ansL[l[i]] - 1 >= n) ok[i] = true;
        }
    }
    for (int i = 1; i <= q; i++) cout << ok[i];
    cout << '\n';
}
int ans[maxN];
int t[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = ans[tl];
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = min(t[v + v], t[v + v + 1]);
}
int get(int v, int tl, int tr, int l, int r) {
    assert(tl <= tr);
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(v + v, tl, tm, l, r);
    else if (l > tm) return get(v + v + 1, tm + 1, tr, l, r);
    else return min(get(v + v, tl, tm, l, tm), get(v + v + 1, tm + 1, tr, tm + 1, r));
}
vector < int > link[maxN];
vector < pair < int, int > > byR[maxN];
const int LOG = 20;
int up[maxN][LOG];
void solve2() {
    for (int i = m; i >= 1; i--) {
        up[i][0] = nxt_pos[i];
        for (int j = 0; j + 1 < LOG; j++) {
            up[i][j + 1] = up[up[i][j]][j];
        }
        int cur = i;
        int t = n - 1;
        for (int j = LOG - 1; j >= 0; j--) {
            if (t >= (1 << j)) {
                t -= (1 << j);
                cur = up[cur][j];
            }
        }
        if (cur == 0) ans[i] = (int)1e9;
        else ans[i] = cur;
    }
    build(1, 1, m);
    for (int i = 1; i <= q; i++) {
        if (get(1, 1, m, l[i], r[i]) <= r[i]) cout << 1;
        else cout << 0;
    }
}
signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        nxt[p[i]] = p[i % n + 1];
        prv[p[i]] = p[(i + 2 * n - 2) % n + 1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        all[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        nxt_pos[i] = 0;
        if (all[nxt[a[i]]].empty() || all[nxt[a[i]]].back() <= i) continue;
        int ind = upper_bound(all[nxt[a[i]]].begin(), all[nxt[a[i]]].end(), i) - all[nxt[a[i]]].begin();
        nxt_pos[i] = all[nxt[a[i]]][ind];
        link[nxt_pos[i]].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        byR[r[i]].emplace_back(l[i], i);
    }
    solve2();
    return 0;
}