#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    sort(s.begin() + 1, s.end());

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {
            if (l == r) {
                dp[l][r] = 0;
            } else {
                int cnt = n - (r - l);
                dp[l][r] = min(
                    dp[l + 1][r] + 1ll * cnt * (s[l + 1] - s[l]),
                    dp[l][r - 1] + 1ll * cnt * (s[r] - s[r - 1])
                );
            }
        }
    }

    cout << dp[1][n] << "\n";

    return 0;
}