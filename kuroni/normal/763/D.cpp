#include <bits/stdc++.h>
using namespace std;

const int N = 100005, BS = 100003;
const long long SD = 133769420;

int n, u, v;
long long pw[N], f[N], g[N], ph[N];
pair<int, int> ans = {0, 0};
vector<int> adj[N];
mt19937_64 mt(SD);
map<long long, long long> per;
map<long long, int> cnt;

void add(long long u, int tmp) {
    if ((cnt[u] += tmp) == 0) {
        cnt.erase(u);
    }
}

long long assign(long long u) {
    if (per.count(u) == 0) {
        per[u] = mt();
    }
    return per[u];
}

long long DFS_1(int u, int p = 0) {
    vector<long long> ve;
    for (int v : adj[u]) {
        if (v != p) {
            ve.push_back(DFS_1(v, u));
        }
    }
    sort(ve.begin(), ve.end());
    for (long long v : ve) {
        (f[u] *= BS) += v;
    }
    return f[u] = assign(f[u]);
}

void DFS_2(int u, int p = 0) {
    vector<pair<long long, int>> ve;
    for (int v : adj[u]) {
        ve.push_back({v == p ? ph[u] : f[v], v});
    }
    sort(ve.begin(), ve.end());
    long long suf = 0, pre = 0;
    int m = ve.size();
    for (auto [h, _] : ve) {
        (suf *= BS) += h;
    }
    g[u] = assign(suf);
    for (int i = 0; i < m; i++) {
        auto [h, v] = ve[i];
        suf -= pw[m - i - 1] * h;
        if (v != p) {
            ph[v] = assign(pre * pw[m - i - 1] + suf);
            DFS_2(v, u);
        }
        (pre *= BS) += h;
    }
}

void DFS_3(int u, int p = 0) {
    ans = max(ans, {cnt.size(), -u});
    // cout << u << ": " << cnt.size() << '\n';
    for (int v : adj[u]) {
        if (v != p) {
            add(g[u], -1); add(f[v], -1);
            add(ph[v], 1); add(g[v], 1);
            DFS_3(v, u);
            add(g[u], 1); add(f[v], 1);
            add(ph[v], -1); add(g[v], -1);
        }
    }
}

void init() {
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * BS;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS_1(1);
    DFS_2(1);
    for (int i = 1; i <= n; i++) {
        // cout << i << " -> " << f[i] << " " << g[i] << " " << ph[i] << '\n';
        cnt[f[i]]++;
    }
    DFS_3(1);
    cout << -ans.second;
}