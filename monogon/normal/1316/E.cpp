
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5, P = 7;
int n, p, k;
ll dp[N][1 << P], dp2[N][1 << P], a[N], s[N][P], pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> k;
    vector<pair<ll, int>> v;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        v.emplace_back(a[i], i);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < p; j++) {
            cin >> s[i][j];
        }
    }
    sort(v.rbegin(), v.rend());
    for(int mask = 1; mask < (1 << p); mask++) {
        dp[0][mask] = dp2[0][mask] = LLONG_MIN;
    }
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + v[i - 1].first;
        dp2[i][0] = 0;
        if(i < k) dp[i][0] = LLONG_MIN;
        else dp[i][0] = pref[k];
        for(int mask = 1; mask < (1 << p); mask++) {
            int sz = __builtin_popcount(mask);
            dp2[i][mask] = dp2[i - 1][mask];
            dp[i][mask] = dp[i - 1][mask];
            for(int j = 0; j < p; j++) {
                if(((mask >> j) & 1) && dp2[i - 1][mask - (1 << j)] != LLONG_MIN) {
                    dp2[i][mask] = max(dp2[i][mask], s[v[i - 1].second][j] - v[i - 1].first + dp2[i - 1][mask - (1 << j)]);
                }
                if(((mask >> j) & 1) && dp[i - 1][mask - (1 << j)] != LLONG_MIN) {
                    dp[i][mask] = max(dp[i][mask], s[v[i - 1].second][j] + dp[i - 1][mask - (1 << j)]);
                }
            }
            if(sz + k == i) {
                dp[i][mask] = max(dp[i][mask], pref[i] + dp2[i][mask]);
            }
        }
    }
    cout << dp[n][(1 << p) - 1] << endl;
}