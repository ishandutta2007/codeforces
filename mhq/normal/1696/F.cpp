#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 105;
int n;
int d[maxN][maxN][maxN];
vector<vector<int>> groups[maxN];
int id[maxN][maxN];
bool was[maxN][maxN];
int dist[maxN];
vector<int> g[maxN];
bool used[maxN];
void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            used[to] = true;
            dfs(to);
        }
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                char c;
                cin >> c;
                d[i][j][k] = c - '0';
                d[j][i][k] = c - '0';
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        groups[k].clear();
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            bool fnd = false;
            for (int j = 1; j < i; j++) {
                if (d[i][j][k]) {
                    fnd = true;
                    groups[k][id[k][j]].emplace_back(i);
                    id[k][i] = id[k][j];
                    break;
                }
            }
            if (!fnd) {
                id[k][i] = groups[k].size();
                groups[k].emplace_back();
                groups[k][id[k][i]].emplace_back(i);
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        vector<pair<int,int>> edges = {{1, i}};
        queue<pair<int,int>> q;
        q.push({1, i});
        q.push({i, 1});
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                was[x][y] = false;
            }
        }
        was[1][i] = true;
        was[i][1] = true;
        bool OK = true;
        while (!q.empty() && edges.size() <= (n - 1) && OK) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for (int c : groups[x][id[x][y]]) {
                if (c == y) continue;
                if (was[x][c] || was[c][x]) {
                    OK = false;
                    break;
                }
                was[x][c] = was[c][x] = true;
                edges.emplace_back(x, c);
                q.push({c, x});
            }
        }
        if (edges.size() != (n - 1) || !OK) {
            continue;
        }

        for (int j = 1; j <= n; j++) {
            used[j] = false;
            g[j].clear();
        }
        for (auto& it : edges) {
            g[it.first].emplace_back(it.second);
            g[it.second].emplace_back(it.first);
        }
        dfs(1);
        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                OK = false;
                break;
            }
        }
        if (!OK) continue;
        for (int j = 1; j <= n; j++) {
            queue<int> qq;
            qq.push(j);
            for (int t = 1; t <= n; t++) {
                dist[t] = -1;
            }
            dist[j] = 0;
            while (!qq.empty()) {
                int c = qq.front();
                qq.pop();
                for (int x : g[c]) {
                    if (dist[x] == -1) {
                        dist[x] = dist[c] + 1;
                        qq.push(x);
                    }
                }
            }
            for (int x = 1; x <= n; x++) {
                for (int y = x + 1; y <= n; y++) {
                    if (d[x][y][j] != ((dist[x] == dist[y]))) {
                        OK = false;
                        break;
                    }
                }
            }
            if (!OK) break;
        }
        if (OK) {
            cout << "Yes\n";
            for (auto& it : edges) {
                cout << it.first << " " << it.second << '\n';
            }
            return;
        }
    }
    cout << "No\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}