#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N = 2e5 + 4;
vec<pair<int, int>> g[N];
int n, par[N], root, where;
ar<int, 3> edge;
bool used[N], on_way[N];
ll deapest[N], dp[N];
vec<int> path;
ll at_least, ans, cur_ans;
ll sum_up[N], sum_down[N], suf_max[N], cur_max;
ll suf_max2[N];

void dfs(int v) {
    used[v] = 1;
    for (auto [u, w] : g[v]) {
        if (u == par[v]) continue;
        if (used[u]) {
            edge = {v, u, w};
            continue;
        }
        par[u] = v;
        dfs(u);
    }
}

inline ll get_down(vec<ll> down) {
    if (len(down) == 0) return 0;
    if (len(down) == 1) return down[0];
    sort(all(down));
    return down.end()[-1] + down.end()[-2];
}

void init(int v) {
    vec<ll> down;
    down.reserve(len(g[v]));
    for (auto [u, w] : g[v]) {
        if (u == par[v]) continue;
        par[u] = v;
        init(u);
        dp[v] = max(dp[v], dp[u]);
        deapest[v] = max(deapest[v], deapest[u] + w);
        down.push_back(deapest[u] + w);
    }
    dp[v] = max(dp[v], get_down(down));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int v, u, w;
        cin >> v >> u >> w, v--, u--;
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }
    dfs(0);
    g[edge[0]].erase(find(all(g[edge[0]]), pair<int, int>{edge[1], edge[2]}));
    g[edge[1]].erase(find(all(g[edge[1]]), pair<int, int>{edge[0], edge[2]}));
    root = edge[0];
    where = edge[1];
    par[root] = -1;
    init(root);
    ans = dp[root];
    for (int i = where; i != -1; i = par[i]) {
        on_way[i] = 1;
        path.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (!on_way[i]) at_least = max(at_least, dp[i]);
    }
    for (auto v : path) {
        vec<ll> down;
        deapest[v] = 0;
        for (auto [u, w] : g[v]) {
            if (u == par[v] || on_way[u]) continue;
            down.push_back(deapest[u] + w);
            deapest[v] = max(deapest[v], deapest[u] + w);
        }
        at_least = max(at_least, get_down(down));
    }
    for (int i = len(path) - 2; i >= 0; i--) {
        sum_up[i] = sum_up[i + 1];
        for (auto [u, w] : g[path[i + 1]]) {
            if (on_way[u] && u != par[path[i + 1]]) sum_up[i] += w;
        }
    }
    for (int i = 1; i < len(path); i++) {
        sum_down[i] = sum_down[i - 1];
        for (auto [u, w] : g[path[i]]) {
            if (on_way[u] && u != par[path[i]]) sum_down[i] += w;
        }
    }
    for (int i = len(path) - 1; i >= 0; i--) {
        if (i != len(path) - 1) suf_max[i] = suf_max[i + 1];
        suf_max[i] = max(suf_max[i], cur_max + deapest[path[i]] + sum_up[i]);
        cur_max = max(cur_max, deapest[path[i]] - sum_up[i]);
    }
    for (int i = len(path) - 1; i > 0; i--) {
        suf_max2[i] = max(suf_max2[i + 1], deapest[path[i]] + sum_up[i]);
    }
    cur_ans = at_least;
    cur_max = 0;
    for (int i = 0; i < len(path) - 1; i++) {
        cur_max = max(cur_max, deapest[path[i]] + sum_down[i]);
        cur_ans = max(cur_ans, dp[path[i]]);
        ans = min(ans, max({cur_ans, edge[2] + cur_max + suf_max2[i + 1], suf_max[i + 1]}));
    }
    cout << ans << '\n';
}