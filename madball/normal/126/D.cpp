#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

lint fib[89];
int ar[89];
lint dp[89][2];

void solve()
{
    fib[1] = 1;
    for (int i = 2; i < 89; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
#ifdef LOCAL
    static int kek[1000000];
    For(mask, 1 << 20)
    {
        int cur = 0;
        For(j, 20)
            if ((mask >> j) & 1)
                cur += (int)fib[2 + j];
        ++kek[cur];
    }
#endif
    int n;
    cin >> n;
    For(i, n)
    {
        lint cur;
        cin >> cur;
#ifdef LOCAL
        if (cur < 1000000)
            cout << kek[cur] << ' ';
#endif
        memset(ar, 0, sizeof(ar));
        memset(dp, 0, sizeof(dp));
        for (int i = 88; i >= 2; --i)
            if (cur >= fib[i])
            {
                cur -= fib[i];
                ++ar[i];
            }
        dp[88][0] = 1;
        for (int i = 88; i >= 3; --i)
        {
            dp[i - 1][0] += dp[i][0];
            if (!ar[i - 1])
                dp[i - 2][1] += dp[i][!ar[i]];
            if (!ar[i])
                dp[i - 1][0] += dp[i][1];
            if (ar[i] && !ar[i - 1])
                dp[i - 2][1] += dp[i][1];
        }
        cout << dp[2][0] + (ar[2] ? 0 : dp[2][1]) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}