#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int m, k; cin >> m >> k;

        pair<int, int> a[k];
        for (int i = 0; i < k; ++i) {
            cin >> a[i].first, a[i].second = i + 1;
        } sort(a, a + k, greater<pair<int, int>>());

        int mx = a[0].first;
        for (int n = 1; n <= m; ++n) {
            // mx <= n * ceil(n / 2)
            if (mx > n * (long long)((n + 1) / 2)) continue;
            // m <= n ^ 2 - floor(n / 2) ^ 2
            if (m > n * (long long)n - (n / 2) * (long long)(n / 2)) continue;

            // answer = n
            vector<pair<int, int>> x, y, z;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if ((i + j) % 2 == 1) {
                        if (i % 2 == 0) x.push_back({i, j});
                        else y.push_back({i, j});
                    } else {
                        if (i % 2 == 0) z.push_back({i, j});
                    }
                }
            }

            int ans[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ans[i][j] = 0;
                }
            }

            for (int i = 0; i < k; ++i) {
                vector<pair<int, int>> &cur = (x.empty() ? y : x);
                while (a[i].first && !cur.empty()) {
                    pair<int, int> pos = cur.back();
                    ans[pos.first][pos.second] = a[i].second;
                    cur.pop_back(); --a[i].first;
                }
                while(a[i].first--) {
                    assert((int)z.size() > 0);
                    pair<int, int> pos = z.back();
                    ans[pos.first][pos.second] = a[i].second;
                    z.pop_back();
                }
            }

            // print answer
            cout << n << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << ans[i][j] << ' ';
                } cout << endl;
            }

            break;
        }
    }
}