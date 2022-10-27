#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
const int64_t INF = 1e15;
int n, m;
int g;
int64_t a[nax];
int64_t dp[2][2];


pair <int64_t, int64_t> solve_dp(int x) {
    dp[0][0] = 0, dp[0][1] = -INF;
    int c = 1;
    for (int i = x ; i <= n ; i += g, c ^= 1) {
        dp[c][0] = dp[c][1] = -INF;
        for (int j = 0 ; j < 2 ; ++ j) {
            int64_t from = dp[c ^ 1][j];
            if (from == -INF) continue;
            dp[c][j] = max(dp[c][j], from + a[i]);
            dp[c][j ^ 1] = max(dp[c][j ^ 1], from - a[i]);
        }
    }
    return make_pair(dp[c ^ 1][0], dp[c ^ 1][1]);
}

void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    for (g = 0 ; m -- ;) {
        int foo;
        cin >> foo;
        g = gcd(g, foo);
    }
    int64_t ans1 = 0, ans2 = 0;
    for (int i = 1 ; i <= g ; ++ i) {
        auto [x, y] = solve_dp(i);
        ans1 += x, ans2 += y;
    }
    cout << max(ans1, ans2) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    we just need to flip things equal to gcd(all bi) ranges
    all states which are reachable are the ones with equal xor in position modulo gcd
    proof: make everything zero from the end, the xor of each position will remain after each operation
    when we arrive at position gcd, either everything is 1, or 0 since the latter part are now all zeros,
    backward operation brings everything back to zero
*/