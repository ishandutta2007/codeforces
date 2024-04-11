#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;
int n, r;
vector<int> adj[maxn];
int dad[maxn];
int a[maxn];
long long ans = 0;
int f[maxn];

void dfs(int u) {
    vector<int> vec;
    for (auto v: adj[u]) {
        if (v == dad[u]) continue;
        dad[v] = u;
        dfs(v);
        vec.push_back(f[v]);
    }
    sort(vec.begin(), vec.end());
    if (u == r) {
        if (vec.size() == 1) {
            ans += a[u];
            ans += a[u] - vec[vec.size() - 1];
        }
        else {
            ans += a[u] - vec[vec.size() - 1];
            ans += a[u] - vec[vec.size() - 2];
        }
    }
    else {
        f[u] = vec.empty() ? 0 : vec.back();
        ans += max(0, a[u] - f[u]);
        f[u] = max(a[u], f[u]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) if (a[i] > a[r]) r = i;
    dfs(r);
    cout << ans << endl;
    return 0;
}