// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[100005], cnt[20000005];
long long dp[20000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i], ++cnt[a[i]];
    for (int i = 1; i <= 5000000; ++i)
        for (int j = 2; i * j <= 5000000; ++j)
            cnt[i] += cnt[i * j];
    for (int i = 5000000; i; --i)
    {
        dp[i] = 1ll * cnt[i] * i;
        for (int j = 2; i * j <= 5000000; ++j)
            dp[i] = std::max(dp[i], dp[i * j] + 1ll * i * (cnt[i] - cnt[i * j]));
    }
    std::cout << dp[1] << std::endl;
    return 0;
}