#include <bits/stdc++.h>
using namespace std;

int q, t, m, cur = 0;
set<pair<int, int>> se[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> m; ++cur; m = -m;
            se[0].insert({cur, m});
            se[1].insert({m, cur});
        } else {
            auto [u, v] = *se[t - 2].begin();
            cout << max(u, v) << ' ';
            se[t - 2].erase({u, v});
            se[(t - 2) ^ 1].erase({v, u});
        }
    }
}