#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n, n);
    queue<int> bfs;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            bfs.push(i);
            d[i] = 0;
        }
        if (g[i].size() == 2) {
            cout << "No\n";
            return;
        }
    }
    int empty = 0;
    while (!bfs.empty()) {
        int x = bfs.front();
        bfs.pop();
        int cnt = 0;
        for (int y: g[x]) {
            if (d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                bfs.push(y);
            }
            if (d[y] == d[x] + 1) cnt++;
            if (d[y] == d[x]) {
                cout << "No\n";
                return;
            }
        }
        if (cnt > 1) {
            cout << "No\n";
            return;
        }
        empty += !cnt;
    }
    if (empty != 1 || *max_element(d.begin(), d.end()) != k) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 3 && d[i] != k) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}