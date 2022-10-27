#include<bits/stdc++.h>
using namespace std;

int const nax = 1e6 + 10;
int n, k ,l, a[nax];
char s[nax];

pair <long long, int> dp[nax];

/**
    you can do many operations as you want, but with some costs
*/

pair <long long, int> solve_dp (int cost) {

    for (int i = 1 ; i <= n ; ++ i) {
        dp[i] = make_pair(1LL << 42, 1 << 30);
    }

    dp[0] = make_pair(0, 0);

    for (int i = 0 ; i <= n ; ++ i) {
        if (i > 0)
        dp[i] = min(dp[i], make_pair(dp[i - 1].first + a[i], dp[i - 1].second));
        int to = min(n, i + l);
        dp[to] = min(dp[to], make_pair(dp[i].first + cost, dp[i].second + 1));
    }

    return dp[n];

}

long long solve () {
    int l = 0, r = nax, opt_cost = 0;

    while (l <= r) {
        int mid = l + r >> 1;
        auto x = solve_dp(mid);
        if (x.second > k) {
            opt_cost = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    if (solve_dp(opt_cost).second <= k) return 0;
    ++ opt_cost;

    return solve_dp(opt_cost).first - 1LL * k * opt_cost;
}

int main(){
    scanf("%d %d %d", &n, &k ,&l);
    scanf("%s", s + 1);

    for (int i = 1 ; i <= n ; ++ i) {
        a[i] = (s[i] >= 'A' && s[i] <= 'Z') ? 1 : 0;
    }

    long long ans = 1 << 30;

    for (int iter = 0 ; iter < 2 ; ++ iter) {
        ans = min(ans, solve());
        for (int i = 1 ; i <= n ; ++ i)
            a[i] ^= 1;
    }

    printf("%lld\n", ans);

}
/**
    Good Luck
        -Lucina
*/