#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> adj(n);
    vector<int> col(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    function<bool(int, int)> DFS = [&](int u, int c) {
        if (col[u] == -1) {
            col[u] = c;
            for (int v : adj[u]) {
                if (!DFS(v, c ^ 1)) {
                    return false;
                }
            }
            return true;
        } else {
            return col[u] == c;
        }
    };
    for (int i = 0; i < n; i++) {
        if (col[i] == -1 && !DFS(i, 0)) {
            return cout << "NO\n", 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << col[i];
    }
}