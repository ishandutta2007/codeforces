#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
vector <int> g[nax];
int parent[nax];
int dep[nax];
pair <int ,int> dfs(int node, int par) {
    vector <pair <int, int>> s;
    s.emplace_back(0, node);
    parent[node] = par;
    for (int to : g[node]) {
        if (to != par) {
            auto p = dfs(to, node);
            s.push_back(p);
        }
    }
    sort(s.rbegin(), s.rend());
    for (int i = 1 ; i < s.size() ; ++ i)
        dep[s[i].second] = s[i].first;
    s[0].first += 1;
    return s[0];
}
bool used[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto p = dfs(1, 0);
    dep[p.second] = p.first;
    int cnt = 0;
    sort(dep + 1, dep + 1 + n, greater<int>());

    int64_t ans = -1e15;
    for (int r = 1 ; r <= k ;  ++ r) {
        cnt += dep[r];
        int64_t opt_b = min(n -  cnt, n / 2);
        ans = max(ans, int64_t(n - r - opt_b) * (r - opt_b));
    }


    cout << ans << '\n';
}
/**
    Ugly quote of the day.
    "Well, what's good problem?
    Many types of problem can be classified as good.
    But one of such types is the one that can make you smile or laugh even in the worst day of your life."
*/