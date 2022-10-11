#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, u, v, cnt = 0, num[N];
vector<int> adj[N];
vector<tuple<int, int, int>> ans;

bool DFS(int u, int p = 0) {
    int cur = 0;
    num[u] = ++cnt;
    for (int &v : adj[u]) {
        if (v == p) {
            continue;
        } else if ((num[v] > 0 && num[v] < num[u]) || (num[v] == 0 && DFS(v, u))) {
            if (cur == 0) {
                cur = v;
            } else {
                ans.push_back({cur, u, v});
                cur = 0;
            }
        }
    }
    if (cur == 0) {
        return true;
    } else {
        if (p != 0) {
            ans.push_back({p, u, cur});
        }
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            DFS(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto &[a, b, c] : ans) {
        cout << a << " " << b << " " << c << '\n';
    }
}