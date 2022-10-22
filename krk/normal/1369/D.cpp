#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxn = 2000005;

ii dp[Maxn];
int T;
int n;

int main()
{
    dp[3] = ii(4, 1);
    for (int i = 4; i < Maxn; i++) {
        dp[i].first = (2ll * dp[i - 2].first + dp[i - 1].first) % mod;
        if (dp[i - 2].second == 0 && dp[i - 1].second == 0) {
            dp[i].first = (dp[i].first + 4) % mod;
            dp[i].second = 1;
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", dp[n].first);
    }
    return 0;
}