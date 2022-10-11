#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const long long INF = 1E18;

int q, n, a[N], b[N];
long long dp[N][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    a[0] = -10;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = INF;
                for (int k = 0; k < 3; k++) {
                    if (a[i - 1] + k != a[i] + j) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                    }
                }
                dp[i][j] += j * b[i];
            }
        }
        cout << *min_element(dp[n], dp[n] + 3) << '\n';
    }
}