#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> rows(n, vector<int>(m));
        for (auto &xs : rows) {
            for (auto &x : xs) {
                cin >> x;
                x--;
            }
        }

        vector<vector<int>> cols(m, vector<int>(n));
        for (auto &xs : cols) {
            for (auto &x : xs) {
                cin >> x;
                x--;
            }
        }

        vector<int> whereInRow(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                whereInRow[rows[i][j]] = j;
            }
        }

        vector<int> whereInCol(n * m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                whereInCol[cols[i][j]] = j;
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n * m; i++) {
            ans[whereInCol[i]][whereInRow[i]] = i + 1;
        }

        for (auto &xs : ans) {
            for (auto &x : xs) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}