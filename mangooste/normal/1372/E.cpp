#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector left(n, vector<int>(m)), right = left;
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            for (int j = l; j <= r; j++) {
                left[i][j] = l;
                right[i][j] = r;
            }
        }
    }

    vector dp(m, vector<int>(m));
    for (int len = 0; len < m; len++) {
        for (int i = 0; i + len < m; i++) {
            int j = i + len;
            for (int k = i; k <= j; k++) {
                int cur = k == i ? 0 : dp[i][k - 1];
                cur += k == j ? 0 : dp[k + 1][j];
                int cnt = 0;
                for (int z = 0; z < n; z++) {
                    cnt += i <= left[z][k] && right[z][k] <= j;
                }
                cur += cnt * cnt;
                dp[i][j] = max(dp[i][j], cur);
            }
        }
    }
    cout << dp[0][m - 1] << '\n';
}