#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, q;
const int maxN = 3e5 + 228;
int p[maxN];
const int LOG = 20;
pair<int,int> up[LOG][maxN];
int lg[maxN];
vector<int> edge[maxN];
int l[maxN], r[maxN];
int a[maxN];
int get_mx(int l, int r) {
    int k = lg[r - l + 1];
    auto res = max(up[k][l], up[k][r - (1 << k) + 1]);
    return res.second;
}
int go(int l, int r) {
    int c = get_mx(l, r);
    if (l < c) {
        int x = go(l, c - 1);
        edge[c].emplace_back(x);
    }
    if (c < r) {
        int x = go(c + 1, r);
        edge[c].emplace_back(x);
    }
    return c;
}
bool OK = true;
int K = 0;
const int INF = 1e7 + 10;
int dfs(int x) {
    int mx = -INF;
    if (a[x] != 0) {
        mx = a[x];
        if (r[x] <= a[x]) {
            OK = false;
        }
        r[x] = a[x];
    }
    else {
        K++;
    }
    for (int to : edge[x]) {
        r[to] = r[x];
        int f = dfs(to);
        mx = max(mx, f);
    }
    if (a[x] != 0) {
        l[x] = a[x];
    }
    else {
        l[x] = mx;
    }
    return l[x];
}
int s[maxN];
int val[maxN];
const int maxP = 3 * maxN;
vector<int> upd[maxP];
pair<int,int> t[4 * maxP];
int lazy[4 * maxP];
void build(int v, int tl, int tr) {
    lazy[v] = 0;
    if (tl == tr) {
        t[v] = {0, tl};
        return;
    }
    int tm = (tl + tr) / 2;
    build(2  * v, tl, tm);
    build(2  * v + 1, tm + 1, tr);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
void apply(int v, int x) {
    t[v].first += x;
    lazy[v] += x;
}
void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v]) {
        apply(2 * v, lazy[v]);
        apply(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}
void updV(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
        apply(v, x);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    updV(2 * v, tl, tm, l, r, x);
    updV(2 * v + 1, tm + 1, tr, l, r, x);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

void solve() {
    cin >> n >> q;
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        up[0][i] = {p[i], i};
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int k = 0; k + 1 < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            if ((i + (1 << (k + 1))) - 1 <= n) {
                up[k + 1][i] = max(up[k][i], up[k][i + (1 << k)]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        edge[i].clear();
    }

    int root = go(1, n);
    r[root] = INF;

    OK = true;
    K = 0;
    dfs(root);
    assert(K >= 2);
    vector<int> all_vals;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            all_vals.emplace_back(l[i]);
            all_vals.emplace_back(r[i]);
        }
    }
    for (int i = 0; i < (K - 1); i++) {
        cin >> s[i];
        all_vals.emplace_back(s[i]);
    }
    for (int i = 1; i <= q; i++) {
        cin >> val[i];
        all_vals.emplace_back(val[i]);
    }
    sort(all_vals.begin(), all_vals.end());
    all_vals.erase(unique(all_vals.begin(), all_vals.end()), all_vals.end());
    int T = all_vals.size();
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            l[i] = lower_bound(all_vals.begin(), all_vals.end(), l[i]) - all_vals.begin() + 1;
            r[i] = lower_bound(all_vals.begin(), all_vals.end(), r[i]) - all_vals.begin() + 1;
        }
    }
    for (int i = 0; i < (K - 1); i++) {
        s[i] = lower_bound(all_vals.begin(), all_vals.end(), s[i]) - all_vals.begin() + 1;
    }
    for (int i = 1; i <= q; i++) {
        val[i] = lower_bound(all_vals.begin(), all_vals.end(), val[i]) - all_vals.begin() + 1;
    }
    if (!OK) {
        for (int i = 1; i <= q; i++) {
            cout << "NO\n";
        }
        return;
    }
    //[L .. R]
    //[L <= l[i] && r[i] <= R]
    for (int i = 1; i <= T; i++) upd[i].clear();
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            upd[r[i]].emplace_back(l[i]);
        }
    }
    for (int i = 0; i < (K - 1); i++) {
        upd[s[i]].emplace_back(~s[i]);
    }
    build(1, 1, T);
    int L = 1;
    int R = T;
    for (int i = 1; i <= T; i++) {
        for (int x : upd[i]) {
            if (x > 0) {
                updV(1, 1, T, 1, x, +1);
            }
            else {
                updV(1, 1, T, 1, ~x, -1);
            }
        }
        if (t[1].first > 1) {
            L = T + 1;
            break;
        }
        else if (t[1].first == 1) {
            L = max(L, t[1].second);
            R = min(R, i);
        }
    }
    for (int i = 1; i <= q; i++) {
        if (L <= val[i] && val[i] <= R) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}