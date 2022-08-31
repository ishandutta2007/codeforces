#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxN = 3 * (int)1e5 + 10;
int deg[maxN];
vector < pair < int, int > > g[maxN];
ll w[maxN];
bool del[maxN];
ll ans = 0;
ll dfs(int v, int p) {
    ll mx_val = 0;
    vector < ll > vals;
    for (auto t : g[v]) {
        if (t.first == p) continue;
        int to = t.first;
        ll len = t.second;
        ll mx = dfs(to, v);
        if (mx >= len) vals.push_back(mx - len);
    }
    ll cur = w[v];
    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());
    if (!vals.empty()) {
        cur = w[v] + vals[0];
    }
    ans = max(ans, cur);
    if (vals.size() >= 2) {
        ans = max(ans, w[v] + vals[0] + vals[1]);
    }
    return cur;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        ans = max(ans, w[i]);
    }
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
        deg[a]++;
        deg[b]++;
    }
    dfs(1, -1);
    cout << ans;
    return 0;
}