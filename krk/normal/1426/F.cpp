#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int n;
char str[Maxn];
int dp[3];

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    int pw = 1;
    for (int i = 0; i < n; i++) {
        if (str[i] == '?') {
            dp[2] = (3ll * ll(dp[2]) + ll(dp[1])) % mod;
            dp[1] = (3ll * ll(dp[1]) + ll(dp[0])) % mod;
            dp[0] = (3ll * ll(dp[0]) + ll(pw)) % mod;
            pw = 3ll * pw % mod;
        } else if (str[i] == 'c')
            dp[2] = (dp[2] + dp[1]) % mod;
          else if (str[i] == 'b')
            dp[1] = (dp[1] + dp[0]) % mod;
          else if (str[i] == 'a')
            dp[0] = (dp[0] + pw) % mod;
    }
    printf("%d\n", dp[2]);
    return 0;
}