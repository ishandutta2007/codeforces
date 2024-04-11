
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// dp[i][mod 10]
// make histogram of costs, check all 3 partitions
// (1) (1, 1) (2) (3) (1, 2) or (1, 1, 1)
// complexity: 6 * 10 * N

const int N = 2e5 + 5;
int n, k[N];
ll c, dam;
vector<ll> d[N][4];
ll dp[N][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    fill(dp[0] + 1, dp[0] + 10, LLONG_MIN);
    rep(i, 1, n + 1) {
        cin >> k[i];
        rep(j, 0, k[i]) {
            cin >> c >> dam;
            d[i][c].push_back(dam);
        }
        rep(j, 1, 4) {
            sort(all(d[i][j]), greater<>());
        }
        rep(m, 0, 10) {
            dp[i][m] = dp[i - 1][m];
            // 1 card.
            if(dp[i - 1][(m + 9) % 10] != LLONG_MIN) {
                // (1)
                // (2)
                // (3)
                rep(k, 1, 4) {
                    if(!d[i][k].empty())
                        dp[i][m] = max(dp[i][m], dp[i - 1][(m + 9) % 10] + (m < 1 ? 2 * d[i][k][0] : d[i][k][0]));
                }
            }
            // 2 cards
            if(dp[i - 1][(m + 8) % 10] != LLONG_MIN) {
                // (1 1)
                if(sz(d[i][1]) >= 2) {
                    dp[i][m] = max(dp[i][m], dp[i - 1][(m + 8) % 10] + (m < 2 ? 2 * d[i][1][0] : d[i][1][0]) + d[i][1][1]);
                }
                // (2 1)
                if(!d[i][1].empty() && !d[i][2].empty()) {
                    dp[i][m] = max(dp[i][m], dp[i - 1][(m + 8) % 10] + d[i][1][0] + d[i][2][0] + (m < 2 ? max(d[i][1][0], d[i][2][0]) : 0));
                }
            }
            // 3 cards
            // (1 1 1)
            if(dp[i - 1][(m + 7) % 10] != LLONG_MIN && sz(d[i][1]) >= 3) {
                dp[i][m] = max(dp[i][m], dp[i - 1][(m + 7) % 10] + (m < 3 ? 2 * d[i][1][0] : d[i][1][0]) + d[i][1][1] + d[i][1][2]);
            }
        }
    }
    cout << *max_element(dp[n], dp[n] + 10) << '\n';
}