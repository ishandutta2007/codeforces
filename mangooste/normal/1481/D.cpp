#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &x : g)
        cin >> x;

    if (m == 1)
        return cout << "YES\n1 2\n", void();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && g[i][j] == g[j][i]) {
                cout << "YES\n";
                for (int k = 0; k < m + 1; k++)
                    cout << (k % 2 ? j : i) + 1 << ' ';
                cout << '\n';
                return;
            }

    if (m % 2) {
        cout << "YES\n";
        for (int i = 0; i < m + 1; i++)
            cout << i % 2 + 1 << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        int posa = int(find(g[i].begin(), g[i].end(), 'a') - g[i].begin());
        int posb = int(find(g[i].begin(), g[i].end(), 'b') - g[i].begin());
        if (posa != int(g[i].size()) && posb != int(g[i].size())) {
            cout << "YES\n";
            if (m % 4 == 0) {
                cout << i + 1 << ' ';
                for (int k = 0; k < m / 2; k++)
                    cout << (k % 2 ? i : posa) + 1 << ' ';
                for (int k = 0; k < m / 2; k++)
                    cout << (k % 2 ? i : posb) + 1 << ' ';
            } else {
                for (int k = 0; k < m / 2 + 1; k++)
                    cout << (k % 2 ? i : posa) + 1 << ' ';
                for (int k = 0; k < m / 2; k++)
                    cout << (k % 2 ? i : posb) + 1 << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}