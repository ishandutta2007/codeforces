#include <bits/stdc++.h>
#pragma GCC targe("avx2")
#define pb push_back
using namespace std;

const int N = 18;
const int Q = (1 << N);
const int M = 998244353;

vector<int> g[N];
int is[N], n, m, can[Q];
unsigned long long dp[Q];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        can[mask] = 1;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                for (auto j: g[i])
                    if ((mask >> j) & 1) {
                        can[mask] = 0;
                        break;
                    }
    }
    dp[0] = 1;
    unsigned long long MX = 9e18;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (auto m1 = mask; m1 > 0; m1 = ((m1 - 1) & mask))
            if (can[m1]) {
                if (__builtin_popcount(m1) % 2 == 1)
                    dp[mask] = (dp[mask] + dp[mask ^ m1]);
                else
                    dp[mask] = (dp[mask] - dp[mask ^ m1] + M);
                if (dp[mask] > MX)
                    dp[mask] %= M;
            }
        dp[mask] %= M;
    }
    cout << dp[(1 << n) - 1] * 1ll * m % M * (M + 1) / 2 % M;
    return 0;
}