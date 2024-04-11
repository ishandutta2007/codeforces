#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n * m, 0);
        for (int i = 0; i < a.size(); ++i) cin >> a[i];
        int ans = 0;

        vector<vector<int>> b(n, vector<int>(m, 0));

        map<int, vector<int>> chunk;
        for (int i = 0; i < a.size(); ++i) chunk[a[i]].push_back(i);
        int r = 0, c = 0;
        for (auto item: chunk) {
            vector<int> v = item.second;
            int lastc = c, i = 0;
            for (auto x: v) {
                b[r][c] = x;
                ++c;
                ++i;

                if (c == m || i == v.size()) {
                    reverse(b[r].begin() + lastc, b[r].begin() + c);
                }
                if (c == m) {
                    ++r;
                    c = 0;
                    lastc = 0;
                }
            }
        }

        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = j + 1; k < m; ++k) if (b[i][j] < b[i][k]) ++ans;
        cout << ans << endl;
    }
    return 0;
}