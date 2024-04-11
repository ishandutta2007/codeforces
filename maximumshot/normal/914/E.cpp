#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int LOG = 20;

vector<ll> fast(int n, vector<pii> edges, string s) {
    vector<int> used(n + 1), sz(n + 1), w(n + 1);
    vector<ll> push(n + 1), dp(n + 1);
    vector<ll> res(n + 1);
    for (int v = 1; v <= n; v++)
        w[v] = 1 << (s[v - 1] - 'a');
    vector<vector<int>> g(n + 1);
    for (auto [u, v] : edges)
        g[u].push_back(v), g[v].push_back(u);
    function<void(int, int)> dfs = [&](int v, int par) {
        sz[v] = 1;
        push[v] = 0;
        for (int to : g[v]) {
            if (used[to] || to == par)
                continue;
            dfs(to, v);
            sz[v] += sz[to];
        }
    };
    function<void(int, int, int, int&)> go = [&](int v, int par, int Size, int& centroid) {
        int mx = Size - sz[v];
        for (int to : g[v]) {
            if (used[to] || to == par)
                continue;
            go(to, v, Size, centroid);
            if (centroid != -1)
                return;
            mx = max(mx, sz[to]);
        }
        if (mx <= Size / 2)
            centroid = v;
    };
    function<void(int, int, int, int, int, vector<int>&, vector<int>&)> update_son =
            [&](int v, int par, int x, int mc, int centroid, vector<int>& cnt, vector<int>& total) {
        for (int i = -1; i < LOG; i++) {
            int y = x ^ mc;
            if (i >= 0)
                y ^= 1 << i;
            int cc = cnt[y];
            res[centroid] += cc;
            total[y]++;
            push[v] += cc;
        }
        for (int to : g[v]) {
            if (used[to] || to == par)
                continue;
            update_son(to, v, x ^ w[to], mc, centroid, cnt, total);
        }
    };
    function<void(int, int, int, vector<int>&, vector<int>&)> update_push =
            [&](int v, int par, int y, vector<int>& total, vector<int>& cnt) {
        push[v] -= total[y];
        cnt[y]++;
        for (int to : g[v]) {
            if (to == par || used[to])
                continue;
            update_push(to, v, y ^ w[to], total, cnt);
        }
    };
    function<void(int, int, int, vector<int>&)> update_res = [&](int v, int par, int y, vector<int>& total) {
        dp[v] = 1ll * total[y] + 1ll * push[v];
        for (int to : g[v]) {
            if (to == par || used[to])
                continue;
            update_res(to, v, y ^ w[to], total);
            dp[v] += dp[to];
        }
        res[v] += dp[v];
    };
    function<void(int, int, int, int, vector<int>&, vector<int>&)> clear = [&](int v, int par, int x, int mc, vector<int>& total, vector<int>& cnt) {
        for (int i = -1; i < LOG; i++) {
            int y = x ^ mc;
            if (i >= 0)
                y ^= 1 << i;
            total[y] = 0;
        }
        cnt[x] = 0;
        for (int to : g[v]) {
            if (to == par || used[to])
                continue;
            clear(to, v, x ^ w[to], mc, total, cnt);
        }
    };
    vector<int> cnt(1 << LOG), total(1 << LOG);
    function<void(int)> work = [&](int v) {
        dfs(v, -1);
        int Size = sz[v];
        int centroid = -1;
        go(v, -1, Size, centroid);
        used[centroid] = 1;
        cnt[w[centroid]]++;
        res[centroid]++;
        for (int to : g[centroid]) {
            if (used[to])
                continue;
            update_son(to, centroid, w[centroid] ^ w[to], w[centroid], centroid, cnt, total);
            update_push(to, centroid, w[centroid] ^ w[to], total, cnt);
        }
        for (int to : g[centroid]) {
            if (used[to])
                continue;
            update_res(to, centroid, w[centroid] ^ w[to], total);
        }
        for (int to : g[centroid]) {
            if (used[to])
                continue;
            clear(to, centroid, w[centroid] ^ w[to], w[centroid], total, cnt);
        }
        cnt[w[centroid]] = 0;
        for (int to : g[centroid]) {
            if (used[to])
                continue;
            work(to);
        }
    };
    work(1);
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<pii> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i].first >> edges[i].second;
    string s;
    cin >> s;
    vector<ll> fs = fast(n, edges, s);
    for (int v = 1; v <= n; v++)
        cout << fs[v] << " ";
    cout << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}