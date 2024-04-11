#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c == 'B' ? 1 : 0;
        }

    int tot = 0;
    vector<vector<bool>> used(n, vector<bool>(m));

    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            int sum = 0;
            if (i + 1 < n && j + 1 < m)
                sum ^= a[i + 1][j + 1];

            if (i + 1 < n)
                sum ^= a[i + 1][j];

            if (j + 1 < m)
                sum ^= a[i][j + 1];

            if (sum ^ a[i][j]) {
                sum ^= 1;
                tot++;
                used[i][j] = true;
            }

            a[i][j] = sum;
        }

    bool any = false;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
            any |= used[i][j] && used[n - 1][j] && used[i][m - 1];

    any &= used[n - 1][m - 1];
    cout << tot - any << '\n';
}