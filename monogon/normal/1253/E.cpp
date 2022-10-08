#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
 
const int N = 85, M = 1e5 + 5;
int n, m, x, s, l, r;
vector<pair<int, int>> v;
int dp[N][M];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x >> s;
        v.emplace_back(x - s, x + s);
    }
    v.emplace_back(3 * M, 3 * M);
    sort(v.begin(), v.end());
    for(int k = 1; k <= m; k++) {
        dp[0][k] = k;
        for(int i = 1; i <= n + 1; i++) {
            tie(l, r) = v[i - 1];
            if(l <= k && k <= r) {
                dp[i][k] = dp[i][k - 1];
                continue;
            }else if(k < l) {
                dp[i][k] = dp[i - 1][k];
                continue;
            }
            int cost = max(0, k - r);
            int j = max(0, l - cost - 1);
            dp[i][k] = min(1 + dp[i][k - 1], min(dp[i - 1][k], cost + dp[i - 1][j]));
        }
    }
    cout << dp[n + 1][m] << endl;
}