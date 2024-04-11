#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> chosen(n + 1);
    int k1;
    cin >> k1;
    while (k1--) {
        int v;
        cin >> v;
        chosen[v] = 1;
    }
    vector<int> chen(n + 1);
    int k2;
    cin >> k2;
    int chenV;
    while (k2--) {
        cin >> chenV;
        chen[chenV] = 1;
    }
    cout << "B " << chenV << endl;
    int ourV;
    cin >> ourV;
    queue<int> q;
    vector<int> used(n + 1);
    used[ourV] = 1;
    q.push(ourV);
    int first = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (chosen[v]) {
            first = v;
            break;
        }
        for (int u : g[v])
            if (!used[u]) {
                used[u] = 1;
                q.push(u);
            }
    }
    cout << "A " << first << endl;
    int v;
    cin >> v;
    if (chen[v]) {
        cout << "C " << first << endl;
    } else {
        cout << "C " <<  -1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}