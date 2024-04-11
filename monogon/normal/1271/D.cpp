
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// stupid problem

// castle should only be defended from last portal that goes to it
// all castles should be captured

const int N = 5005;
int n, m, k, a[N], b[N], c[N], u, v, dp[2 * N][N], portal[N];
vector<int> defend[N];

vector<pair<int, int>> ve;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    int army = k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if(army < a[i]) {
            cout << "-1\n";
            return 0;
        }
        army += b[i];
        portal[i] = i;
        ve.emplace_back(i, 0);
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        portal[v] = max(portal[v], u);
    }
    for(int i = 1; i <= n; i++) {
        defend[portal[i]].push_back(c[i]);
        ve.emplace_back(portal[i], (int) defend[portal[i]].size());
    }
    sort(ve.begin(), ve.end());
    fill(dp[0], dp[0] + N, INT_MIN);
    dp[0][k] = 0;
    for(int i = 1; i <= 2 * n; i++) {
        auto [idx, num] = ve[i - 1];
        for(int army = 0; army <= 5000; army++) {
            dp[i][army] = INT_MIN;
            if(num == 0) {
                if(army - b[idx] >= a[idx]) {
                    dp[i][army] = dp[i - 1][army - b[idx]];
                }
            }else {
                dp[i][army] = dp[i - 1][army];
                if(army < 5000 && dp[i - 1][army + 1] >= 0) {
                    dp[i][army] = max(dp[i][army], defend[idx][num - 1] + dp[i - 1][army + 1]);
                }
            }
        }
    }
    int ans = 0;
    for(int army = 0; army <= 5000; army++) {
        ans = max(ans, dp[2 * n][army]);
    }
    cout << ans << '\n';
}