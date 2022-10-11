#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 300005;

int n, m, s, u[N], v[N], t[N], tmp[N];
bool vis[N];
vector<pair<int, int>> adj[N];

int DFS_1(int u) {
    vis[u] = true;
    int cnt = 1;
    for (pair<int, int> &v : adj[u]) {
        if (!vis[v.fi]) {
            if (v.se != 0) {
                tmp[abs(v.se)] = v.se / abs(v.se);
            }
            cnt += DFS_1(v.fi);
        }
    }
    return cnt;
}

int DFS_2(int u) {
    vis[u] = true;
    int cnt = 1;
    for (pair<int, int> &v : adj[u]) {
        if (!vis[v.fi]) {
            if (v.se != 0) {
                tmp[abs(v.se)] = -v.se / abs(v.se);
            } else {
                cnt += DFS_2(v.fi);
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> u[i] >> v[i];
        if (t[i] == 1) {
            adj[u[i]].push_back({v[i], 0});
        } else {
            adj[u[i]].push_back({v[i], i});
            adj[v[i]].push_back({u[i], -i});
        }
    }
    cout << DFS_1(s) << '\n';
    for (int i = 1; i <= m; i++) {
        if (t[i] == 2) {
            if (tmp[i] >= 0) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
    }
    cout << '\n';
    fill(vis + 1, vis + n + 1, false);
    cout << DFS_2(s) << '\n';
    for (int i = 1; i <= m; i++) {
        if (t[i] == 2) {
            if (tmp[i] >= 0) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
    }
}