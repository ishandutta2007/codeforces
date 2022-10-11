#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<bool> used(2 * n);
    ll ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (used[i]) continue;

        vector<int> cycle;
        for (int j = i;;) {
            cycle.push_back(j);
            used[j] = true;
            bool found = false;
            for (auto pos : g[j]) {
                if (!used[pos]) {
                    j = pos;
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }

        for (int st = 0; st < len(cycle); st++) {
            int l1 = n - 1, r1 = 0;
            int l2 = n - 1, r2 = 0;
            for (int cnt = 1; cnt <= len(cycle) - (st != 0); cnt++) {
                int fn = (st + cnt - 1) % len(cycle);
                if (cycle[fn] < n) {
                    l1 = min(l1, cycle[fn]);
                    r1 = max(r1, cycle[fn]);
                } else {
                    l2 = min(l2, cycle[fn] - n);
                    r2 = max(r2, cycle[fn] - n);
                }

                int new_l1 = 0, new_r1 = n - 1;
                int new_l2 = 0, new_r2 = n - 1;
                if (cnt != len(cycle)) {
                    bool fail = false;
                    for (int v : {cycle[(st + len(cycle) - 1) % len(cycle)], cycle[(fn + 1) % len(cycle)]}) {
                        if (v < n) {
                            if (v < l1) new_l1 = max(new_l1, v + 1);
                            else if (v <= r1) fail = true;
                            else new_r1 = min(new_r1, v - 1);
                        } else {
                            v -= n;
                            if (v < l2) new_l2 = max(new_l2, v + 1);
                            else if (v <= r2) fail = true;
                            else new_r2 = min(new_r2, v - 1);
                        }
                    }
                    if (fail) continue;
                }
                ans += 1ll * (l1 - new_l1 + 1) * (new_r1 - r1 + 1) * (l2 - new_l2 + 1) * (new_r2 - r2 + 1) * (cnt / 2);
            }
        }
    }
    cout << ans << '\n';
}