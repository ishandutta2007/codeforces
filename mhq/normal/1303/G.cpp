#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return 1.0 * (x->b - y->b)*(z->m - y->m) >= 1.0 * (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};
int n;
const int maxN = 15 * 10000 + 10;
vector < int > g[maxN];
int a[maxN];
bool used[maxN];
int sz[maxN];
int sb[maxN];
void find_cen(int v, int p, vector < int >& ord) {
    ord.push_back(v);
    sz[v] = 1;
    sb[v] = 0;
    for (int to : g[v]) {
        if (used[to] || to == p) continue;
        find_cen(to, v, ord);
        sb[v] = max(sb[v], sz[to]);
        sz[v] += sz[to];
    }
}
ll valFrom[maxN];
ll valTo[maxN];
ll sum[maxN];
int h[maxN];
void dfs(int v, int p) {
    for (int to : g[v]) {
        if (used[to] || to == p) continue;
        h[to] = h[v] + 1;
        valFrom[to] = valFrom[v] + 1LL * h[to] * a[to];
        valTo[to] = valTo[v] + sum[v];
        sum[to] = sum[v] + a[to];
        dfs(to, v);
    }
}
ll ans = 0;
void solve(int root) {
   // cout << root << endl;
    vector < int > ord;
    find_cen(root, -1, ord);
    int c = -1;
    int n = ord.size();
    for (int v : ord) {
        if (2 * sb[v] <= n && 2 * (n - sz[v]) <= n) {
            c = v;
            break;
        }
    }
    assert(c != -1);
    valFrom[c] = h[c] = sum[c] = valTo[c] = 0;
    sum[c] = a[c];
    dfs(c, -1);
    vector < vector < int > > vert;
    HullDynamic lc1, lc2;
  //  cout << c << " TUT" << endl;
    for (int to : g[c]) {
        if (used[to]) continue;
        vector < int > gg;
        find_cen(to, c, gg);
        for (int p : gg) {
            ans = max(ans, valFrom[p] + sum[p]);
            ans = max(ans, valTo[p] + sum[p]);
            if (!vert.empty()) {
                ans = max(ans, lc1.eval(sum[p] - a[c]) + valFrom[p] + sum[p]);
            }
        }
        vert.push_back(gg);
        for (int p : gg) {
            lc1.insert_line(h[p], valTo[p] + sum[p] - a[c]);
        }
    }
    vert.clear();
    for (int it = g[c].size() - 1; it >= 0; it--) {
        int to = g[c][it];
        if (used[to]) continue;
        vector < int > gg;
        find_cen(to, c, gg);
        for (int p : gg) {
            ans = max(ans, valFrom[p] + sum[p]);
            ans = max(ans, valTo[p] + sum[p]);
            if (!vert.empty()) {
                ans = max(ans, lc2.eval(sum[p] - a[c]) + valFrom[p] + sum[p]);
            }
        }
        vert.push_back(gg);
        for (int p : gg) {
            lc2.insert_line(h[p], valTo[p] + sum[p] - a[c]);
        }
    }

    used[c] = true;
    for (int to : g[c]) {
        if (!used[to]) solve(to);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    solve(1);
    cout << ans;
    return 0;
}