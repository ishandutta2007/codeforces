#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, h, u, v, cnt = 0, cur = 0, num[N], low[N], col[N], a[N];
bool chk[N];
vector<int> ve, adj[N], ele[N];

void DFS(int u) {
    num[u] = low[u] = ++cnt;
    ve.push_back(u);
    for (int &v : adj[u]) {
        if (col[v] != 0) {
            continue;
        }
        if (num[v] == 0) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u]) {
        ++cur;
        while (col[u] == 0) {
            col[ve.back()] = cur;
            ele[cur].push_back(ve.back());
            ve.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        cin >> u >> v;
        if ((a[u] + 1) % h == a[v]) {
            adj[u].push_back(v);
        }
        if ((a[v] + 1) % h == a[u]) {
            adj[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            DFS(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int &v : adj[i]) {
            if (col[v] != col[i]) {
                chk[col[i]] = true;
            }
        }
    }
    int mi = -1;
    for (int i = 1; i <= cur; i++) {
        if (!chk[i] && (mi == -1 || ele[i].size() < ele[mi].size())) {
            mi = i;
        }
    }
    cout << ele[mi].size() << '\n';
    sort(ele[mi].begin(), ele[mi].end());
    for (int &v : ele[mi]) {
        cout << v << " ";
    }
}