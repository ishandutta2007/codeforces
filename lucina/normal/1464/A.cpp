#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, m;
vector <pair <int, int>> g[nax];
pair <int, int> a[nax];
int b[nax];
int f[nax];
bool vis[nax];
vector <int> found;
vector <int> sigh[nax];

void dfs(int nod) {
    vis[nod] = true;

    for (auto sighh : sigh[nod]) {
        found.push_back(sighh);
    }

    for (auto [foo, bar] : g[nod]) {
        if (!vis[foo]) {
            dfs(foo);
        }
    }
}

void solve() {
    cin >> n >> m;

    fill(b + 1, b + 1 + n, 0);
    fill(f + 1, f + 1 + n, 0);
    fill(vis + 1, vis + 1 + n, false);

    for (int i = 1 ; i <= n ; ++ i) {
        g[i].clear();
        sigh[i].clear();
    }

    for (int i = 1 ; i <= m ; ++ i) {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
        f[x] += 1;
        f[y] += 1;
        if (x == y) continue;
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
        sigh[x].push_back(i);
        sigh[y].push_back(i);
    }

    int ans = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (vis[i]) continue;
        found.clear();
        dfs(i);
        sort(found.begin(), found.end());
        found.erase(unique(found.begin(), found.end()), found.end());
        bool at_least = false;
        for (int j : found) {
            if (f[a[j].first] <= 1 || f[a[j].second] <= 1) {
                at_least = true;
            }
        }
        if (found.empty()) continue;
      //  cout << "FOUND SIZE " << found.size() << '\n';
        if (at_least) ans += found.size();
        else ans += found.size() + 1;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/