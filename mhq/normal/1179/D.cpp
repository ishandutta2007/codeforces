#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 5 * (int)1e5 + 100;
vector < int > g[maxN];
vector < int > ng[maxN];
ll sz[maxN];
struct pt{
    ll x, y;
    pt(ll _x, ll _y) {
        x = _x;
        y = _y;
    }
};
bool del(const pt& x, const pt& y, const pt& z) {
    return ((ld)y.y - x.y) * (x.x - z.x) <= ((ld)z.y - x.y) * (x.x - y.x);
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
const ll INF = (ll)1e18;
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
void dfs(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        ng[v].push_back(to);
        sz[v] += sz[to];
    }
}
ll f[maxN];
ll c2(int x) {
    return (1LL * x * (x - 1)) / 2;
}
void count_f(int v) {
    if (g[v].empty()) {
        f[v] = 0;
        return;
    }
    f[v] = INF;
    for (int to : g[v]) {
        count_f(to);
        f[v] = min(f[v], f[to] + c2(sz[v] - sz[to]));
    }
}
ll best = INF;
vector < pt >  vec;
void solve(int v) {
    for (int to : g[v]) {
        solve(to);
        best = min(best, 2 * c2(n - sz[to]) + 2 * f[to]);
    }
    vector < pair < ll, ll > > all(g[v].size());
    ll coef = (1LL * n * (n - 1));
    for (int to : g[v]) {
        ll cur = 2 * f[to];
        cur += (1LL * sz[to] * sz[to]);
        cur -= (1LL * (2LL * n - 1) * sz[to]);
        all.emplace_back(-sz[to], -cur);
    }
    sort(all.begin(), all.end());
    vec.clear();
    ll now = INF;
    for (auto it : all) {
        ll cur = -(get(-2 * it.first, vec) + it.second);
        now = min(now, cur + coef);
        add(it.first, it.second, vec);
    }
    best = min(best, now);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        g[i] = ng[i];
    }
    count_f(1);
    solve(1);
    best /= 2;
    cout << (1LL * n * (n - 1)) - best;
    return 0;
}