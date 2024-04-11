#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxP = 7;
int bits[(1 << maxP) + 2];
const int maxN = (int)1e5 + 10;
ll dp[maxN][(1 << 7) + 2];
int n, p, k;
int a[maxN];
int pos[maxN];
int s[maxN][maxP];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    bits[0] = 0;
    for (int i = 1; i < (1 << maxP); i++) bits[i] = bits[i / 2] + (i & 1);
    cin >> n >> p >> k;
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        all.emplace_back(x, i);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int i = 0; i < n; i++) {
        pos[all[i].second] = i + 1;
        a[i + 1] = all[i].first;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> s[pos[i]][j];
        }
    }
    const ll INF = 1e18;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < (1 << p); j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << p); mask++) {
            if (dp[i][mask] < 0) continue;
            //can not take
            if (i - bits[mask] < k) {
                dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask] + a[i + 1]);
            }
            else {
                dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask]);
            }
            for (int bit = 0; bit < p; bit++) {
                if (mask & (1 << bit)) continue;
                dp[i + 1][mask | (1 << bit)] = max(dp[i + 1][mask | (1 << bit)], dp[i][mask] + s[i + 1][bit]);
            }
        }
    }
    cout << dp[n][(1 << p) - 1];
    return 0;
}