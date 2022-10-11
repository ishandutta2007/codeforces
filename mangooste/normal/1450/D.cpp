#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) {
        cin >> x;
        x--;
    }
    if (find(all(p), 0) == p.end()) {
        cout << string(n, '0') << '\n';
        return;
    }

    vector<vector<int>> where(n);
    for (int i = 0; i < n; i++) {
        where[p[i]].emplace_back(i);
    }

    string ans(n, '0');
    int l = 0, r = n - 1;
    int cur = 0;
    while (r >= l) {
        if (where[cur].empty()) break;
        if (len(where[cur]) == 1) {
            int pos = where[cur][0];
            if (pos == l) {
                ans[n - 1 - cur] = '1';
                l++;
            } else if (pos == r) {
                ans[n - 1 - cur] = '1';
                r--;
            } else {
                ans[n - 1 - cur] = '1';
                break;
            }
        } else {
            ans[n - 1 - cur] = '1';
            break;
        }
        cur++;
    }

    bool one = true;
    for (int i = 0; i < n; i++) {
        one &= len(where[i]) == 1;
    }
    ans[0] = '0' + one;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}