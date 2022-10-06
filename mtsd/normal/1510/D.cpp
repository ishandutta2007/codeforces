#include <bits/stdc++.h>
using ll = long long;
using ld = __float128;
int main()
{
    int N, D;
    std::cin >> N >> D;

    std::vector<std::vector<int>> as(10);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        as[a % 10].push_back(a);
    }
    for (int d = 0; d < 10; d++) { std::sort(as[d].begin(), as[d].end(), std::greater<int>{}); }

    if (D == 0) {
        int p = 1;
        for (int d = 0; d < 10; d++) {
            for (const int a : as[d]) { (p *= a) %= 10; }
        }
        if (p != 0) {
            std::cout << "-1\n";
        } else {
            std::cout << N << "\n";
            for (int d = 0; d < 10; d++) {
                for (const int a : as[d]) { std::cout << a << " "; }
            }
            std::cout << "\n";
        }
        return 0;
    }

    using pdi = std::pair<ld, int>;
    std::vector<std::vector<pdi>> dp(10, std::vector<pdi>(10, {-1000, 0}));
    for (int d = 1; d < 10; d++) {
        ld log   = 0;
        int dig  = 1;
        dp[d][1] = {0, 0};
        for (int i = 0; i < (int)as[d].size(); i++) {
            const int a = as[d][i];
            log += std::log(a), (dig *= d) %= 10;
            dp[d][dig] = {log, i + 1};
        }
    }
    using pdv = std::pair<ld, std::vector<int>>;
    std::vector<pdv> dp2(10, {-1000, {}});
    for (int i = 0; i < 10; i++) { dp2[i] = {dp[1][i].first, {dp[1][i].second}}; }
    for (int d = 2; d < 10; d++) {
        std::vector<pdv> ndp(10, {-1000, {}});
        for (int d1 = 1; d1 < 10; d1++) {
            for (int d2 = 1; d2 < 10; d2++) {
                if (dp2[d1].first < 0 or dp[d][d2].first < 0) { continue; }
                ld nlog      = dp2[d1].first + dp[d][d2].first;
                const int nd = (d1 * d2) % 10;
                if (ndp[nd].first < nlog) {
                    ndp[nd].first  = nlog;
                    ndp[nd].second = dp2[d1].second;
                    ndp[nd].second.push_back(dp[d][d2].second);
                }
            }
        }
        dp2 = ndp;
    }
    if (dp2[D].first < 0) {
        std::cout << "-1\n";
        return 0;
    }
    const std::vector<int> ns = dp2[D].second;
    const int sn              = std::accumulate(ns.begin(), ns.end(), 0);
    if (sn == 0) {
        std::cout << "-1\n";
        return 0;
    }
    std::cout << sn << "\n";
    for (int d = 1; d < 10; d++) {
        const int n = ns[d - 1];
        for (int i = 0; i < n; i++) { std::cout << as[d][i] << " "; }
    }
    std::cout << "\n";
    return 0;
}