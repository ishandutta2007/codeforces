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
    vector<int> a(n * m);
    for (auto &x : a)
        cin >> x;

    vector<int> order(n * m);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) {
        return a[i] < a[j];
    });

    vector<vector<int>> b(n, vector<int>(m));
    int x = 0;
    int y = 0;

    for (int i = 0; i < n * m;) {
        int j = i;
        while (j < n * m && a[order[i]] == a[order[j]])
            j++;

        sort(order.begin() + i, order.begin() + j);
        while (i < j) {
            int left = min(m - y, j - i);
            reverse(order.begin() + i, order.begin() + i + left);

            while (left--) {
                b[x][y] = order[i];
                i++, y++;
                if (y == m) {
                    y = 0;
                    x++;
                }
            }
        }
    }

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cout << b[i][j] << " \n"[j == m - 1];

    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = j + 1; k < m; k++)
                answer += b[i][j] < b[i][k];

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}