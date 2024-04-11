#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n;
    cin >> n;
    const int N = 1e5 + 5;
    vector<vector<int>> pos(N);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pos[a].push_back(i);
    }
    vector<int> fenw(N);
    auto add = [&](int pos) {
        for (; pos < N; pos |= pos + 1)
            fenw[pos]++;
    };
    auto get = [&](int pos) {
        int res = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
            res += fenw[pos];
        return res;
    };
    ll ans = n;
    int prev = 0;
    for (int val = 1; val < N; val++) {
        sort(pos[val].begin(), pos[val].end(), [&](int x, int y) {
            int v1 =  x - prev >= 0 ? x - prev : x - prev + n;
            int v2 =  y - prev >= 0 ? y - prev : y - prev + n;
            return v1 < v2;
        });
        for (int i = 0; i < pos[val].size(); i++) {
            if (pos[val][i] >= prev) {
                ans += pos[val][i] - prev;
                ans -= get(pos[val][i]) - get(prev - 1);
            } else {
                ans += pos[val][i] - prev + n;
                ans -= get(pos[val][i]);
                ans -= get(n - 1) - get(prev - 1);
            }
            add(pos[val][i]);
            prev = pos[val][i];
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}