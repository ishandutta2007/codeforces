#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a)
        cin >> s;

    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + a[i][j] - '0';

    auto ones = [&](int x1, int y1, int x2, int y2) {
        x2++, y2++;
        return pref[x2][y2] - pref[x2][y1] - pref[x1][y2] + pref[x1][y1];
    };

    auto zeroes = [&](int x1, int y1, int x2, int y2) {
        return (x2 - x1 + 1) * (y2 - y1 + 1) - ones(x1, y1, x2, y2);
    };

    int answer = n * m;
    for (int c1 = 0; c1 < m; c1++)
        for (int c2 = c1 + 3; c2 < m; c2++) {
            int mx = -n * m;
            for (int r = 4; r < n; r++) {
                mx = max(mx,
                    zeroes(0, c1, r - 4, c1)
                    + zeroes(0, c2, r - 4, c2)
                    + ones(0, c1 + 1, r - 4, c2 - 1)
                    - zeroes(r - 4, c1 + 1, r - 4, c2 - 1));

                answer = min(answer,
                    zeroes(0, c1, r - 1, c1)
                    + zeroes(0, c2, r - 1, c2)
                    + ones(0, c1 + 1, r - 1, c2 - 1)
                    + zeroes(r, c1 + 1, r, c2 - 1)
                    - mx);
            }
        }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}