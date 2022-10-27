#include<bits/stdc++.h>
using namespace std;
const int M = 5e6 + 10;
int n, m;
bool has[M];
int dp[M];
int cnt[M];


void solve() {
    cin >> n >> m;
    fill(has, has + m + 1, false);
    fill(dp, dp + 1 + m, m + 1);
    fill(cnt, cnt + m + 2, 0);
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        cin >> x;
        if (!has[x]) {
            has[x] = true;
            cnt[m + 1] += 1;
        }
    }
    int r = m + 1;
    int ans = m + 1;
    /**
        For each number in the original set,
        we will keep track dp value for current L
        ,the minimum value it can be represented, while the factor is larger than L(which can be updated by sieve)
        then we just need to use pointer to keep track of valid value.
    */

    for (int l = m ; l >= 1 ; -- l) {
        dp[l] = l;
        if (has[l]) {
            cnt[m + 1] -= 1;
            cnt[l] += 1;
        }
        if (int64_t(l) * l <= m) {
            for (int j = l * l, other = l ; j <= m ; j += l, other += 1) {
                if (dp[other] < dp[j]) {
                    if (has[j]) cnt[dp[j]] -= 1, cnt[dp[other]] += 1;
                    dp[j] = dp[other];
                }
            }
        }
        while (cnt[r] == 0) {
            r -= 1;
        }
        if (r != m + 1) ans = min(ans, r - l);
    }

    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}