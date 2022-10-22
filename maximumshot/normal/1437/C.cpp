#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        vector<int> t(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> t[i];
        sort(t.begin(), t.end());

        int T = 2 * n;
        vector<vector<int>> dp(T + 1, vector<int>(n + 1, inf));
        for (int t0 = 0; t0 <= T; t0++)
            dp[t0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int t0 = 1; t0 <= T; t0++) {
                dp[t0][i] = min(dp[t0 - 1][i], dp[t0 - 1][i - 1] + abs(t0 - t[i]));
            }
        }

        cout << dp[T][n] << "\n";
    }

    return 0;
}