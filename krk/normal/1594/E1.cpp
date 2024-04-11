#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 62;

int k;
int dp[Maxn];

int main()
{
    scanf("%d", &k);
    dp[1] = 1;
    for (int i = 2; i <= k; i++)
        for (int a = 0; a < 6; a++) if (a / 2 != 0)
            for (int b = 0; b < 6; b++) if (b / 2 != 0)
                dp[i] = (dp[i] + ll(dp[i - 1]) * dp[i - 1]) % mod;
    cout << 6ll * ll(dp[k]) % mod << endl;
    return 0;
}