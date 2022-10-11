#include <bits/stdc++.h>
using namespace std;

const int N = 35, DX[4] = {0, 1, 0, -1}, DY[4] = {1, 0, -1, 0};

int n, u, v;
long long ax[N], ay[N];
vector<int> adj[N];

void DFS(int u, long long x, long long y, int p = 0, int h = 31, int pre = -1) {
    ax[u] = x; ay[u] = y;
    int cnt = 0;
    for (int &v : adj[u]) {
        if (v != p) {
            if (pre != -1 && (cnt ^ pre) == 2) {
                ++cnt;
            }
            DFS(v, x + DX[cnt] * (1LL << h), y + DY[cnt] * (1LL << h), u, h - 1, cnt);
            ++cnt;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 4) {
            return cout << "NO\n", 0;
        }
    }
    cout << "YES\n";
    DFS(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        cout << ax[i] << " " << ay[i] << '\n';
    }
}