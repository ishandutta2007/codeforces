#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m, k;
vector <int> g[nax];
vector <int> new_g[nax];
vector <pair <int, int>> edges;
int deg[nax];
bool del[nax];
bool vis[nax];
vector <pair <int, int>> connect;

void solve() {
    cin >> n >> m >> k;


    for (int i = 1 ; i <= m ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); 
        edges.emplace_back(u, v);
        ++ deg[u];
        ++ deg[v];
        connect.push_back(minmax(u, v));
    } 
    if (k > 500) return cout << "-1\n", void();
sort(connect.begin(),connect.end());
    set <pair <int, int>> setik;

    for (int i = 1 ; i <= n ; ++ i) {
        setik.emplace(deg[i], i);
    }

    auto my_erase = [&](int x, int y) -> void {
        setik.erase(make_pair(x, y));
    };

    while (!setik.empty() && setik.begin()->first < k) {
        auto [u, v] = *setik.begin();
        setik.erase(setik.begin());

        for (int to : g[v]) {
            if (del[to]) continue;
            my_erase(deg[to], to);
            -- deg[to];
            if (deg[to] > 0) setik.emplace(deg[to], to);
            else del[to] = true;
        }
        del[v] = true;
    }

    if (!setik.empty()) {
        for (auto &[u, v] : edges) {
            if (del[u] || del[v]) continue;
            new_g[u].push_back(v);
            new_g[v].push_back(u);
        }

        vector <int> ans;

        function <void(int)> dfs = [&](int node) -> void {
            vis[node] = true;
            ans.push_back(node);
            for (int to : new_g[node]) {
                if (!vis[to]) dfs(to);
            }
        };

        for (int i = 1 ; i <= n;  ++ i) {
            if (!del[i]) {
                dfs(i);
                break;
            }
        }
        cout << "1 " << ans.size() << '\n';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
        return ;
    }

    setik.clear();
    for (int i = 1 ; i <= n ; ++ i)
        deg[i] = 0, del[i] = false;
    for (auto& [u, v] : edges) ++ deg[u], ++ deg[v];
    for (int i = 1 ; i <= n ; ++ i) setik.emplace(deg[i], i);

    vector <int> bar;

    while (true) {
        while (!setik.empty() && setik.begin()->first < k - 1) {
            auto [u, v] = *setik.begin();
            setik.erase(setik.begin());
            for (int to : g[v]) {
                if (del[to]) continue;
                my_erase(deg[to], to);
                -- deg[to];
                if (deg[to] > 0) setik.emplace(deg[to], to);
                else del[to] = true;
            }
            del[v] = true;
        }
        if (setik.empty()) break;
        assert(setik.begin()->first == k - 1);
        auto [u, v] = *setik.begin();
        bar.clear();
        for (int to : g[v]) {
            if (!del[to]) bar.push_back(to);
        }
        bar.push_back(v);

            ///check clique
        for (int node : bar)
            if (deg[node] < k - 1) {
                goto non_clique;
            }

        for (int i = 0 ; i < bar.size() ; ++ i)
        for (int j = i + 1 ; j < bar.size();  ++ j) {
             pair<int,int> foo = minmax(bar[i],bar[j]);
            if (!binary_search(connect.begin(),connect.end() ,foo)) {
                    goto non_clique;
                }
            }
        cout << "2\n";
        for (int i : bar) cout << i << ' ';
        cout << '\n';
        return;

        non_clique:;

        setik.erase(setik.begin());
        for (int to : g[v]) {
            if (del[to]) continue;
            my_erase(deg[to], to);
            -- deg[to];
            if (deg[to] > 0) setik.emplace(deg[to], to);
            else del[to] = true;
        }
        del[v] = true;
    }

    cout << -1 << '\n';
}

int main() {

    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();

        for (int i = 1 ; i <= n ; ++ i) {
            deg[i] = 0;
            g[i].clear();
            new_g[i].clear();
            del[i] = false;
            vis[i] = false;
        }
        connect.clear();
        edges.clear();
    }
}