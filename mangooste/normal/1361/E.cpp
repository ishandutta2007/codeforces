#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vec<vec<int>> g;
vec<int> used;
int timer;
vec<int> dep;
bool ok;
vec<char> on_way;
vec<int> sum;
vec<pr<int>> max_up;
vec<char> dp;

inline void clear_all() {
    g.clear();
    used.clear();
    timer = 0;
    dep.clear();
    on_way.clear();
    sum.clear();
    max_up.clear();
    dp.clear();
}

inline void resize_all() {
    g.resize(n);
    used.resize(n);
    dep.resize(n);
    on_way.resize(n);
    sum.resize(n);
    max_up.resize(n, {n, -1});
    dp.resize(n);
}

void dfs_check(int v) {
    on_way[v] = 1;
    used[v] = timer;
    for (auto u : g[v]) {
        if (!ok)
            break;
        if (used[u] != timer) {
            dep[u] = dep[v] + 1;
            dfs_check(u);
        } else
            ok &= on_way[u];
    }
    on_way[v] = 0;
}

void init(int v) {
    used[v] = timer;
    for (auto u : g[v])
        if (used[u] != timer) {
            init(u);
            sum[v] += sum[u];
            assert(max_up[u].second != -1);
            max_up[v] = min(max_up[v], max_up[u]);
        } else
            max_up[v] = min(max_up[v], pr<int>{dep[u], u});
}

void solve(int v) {
    if (sum[v] >= 2)
        dp[v] = 0;
    else
        dp[v] = dp[max_up[v].second];
    used[v] = timer;
    for (auto u : g[v])
        if (used[u] != timer)
            solve(u);
}

void solve() {
    clear_all();
    cin >> n >> m;
    resize_all();
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
    }

    vec<int> ord(n);
    iota(all(ord), 0);
    shuffle(all(ord), rng);
    ord.resize(min(n, 30));

    for (auto c : ord) {
        ok = true;
        timer++;
        dep[c] = 0;
        dfs_check(c);
        if (!ok)
            continue;

        for (int i = 0; i < n; i++)
            for (auto j : g[i])
                if (dep[j] < dep[i]) {
                    sum[i]++;
                    sum[j]--;
                }
        timer++;
        init(c);

        dp[c] = 1;
        timer++;
        used[c] = timer;
        for (auto v : g[c])
            solve(v);

        vec<int> ans;
        for (int i = 0; i < n; i++)
            if (dp[i])
                ans.push_back(i);
        if (len(ans) * 5 >= n) {
            for (auto x : ans)
                cout << x + 1 << ' ';
            cout << '\n';
        } else
            cout << "-1\n";
        return;
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}