#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 5;

int d, m, dp[33][33];

int get_less(int bit) {
    if ((1ll << bit) > d)
        return 0;
    //cout << bit << ' ' << (1ll << (bit+1)) - 1 <<endl;
    if ((1ll << (bit + 1)) - 1 <= d)
        return (1ll << (bit));
    int ans = 1;
    for (int i = bit - 1; i >= 0; i--)
        if ((d >> i) & 1)
            ans += (1ll << i);
    return ans;//because of zero
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> d >> m;
        for (int i = 0; i <= 32; i++)
            dp[0][i] = 1;
        for (int i = 1; i <= 32; i++)
            for (int bit = 1; bit <= 32; bit++) {
                dp[i][bit] = dp[i][bit - 1];
                dp[i][bit] += dp[i - 1][bit - 1] * get_less(bit - 1) % m;
                dp[i][bit] %= m;
            }
        int ans = 0;
        for (int i = 1; i <= 32; i++)
            ans = (ans + dp[i][32]) % m;
        cout << ans << "\n";

    }
    return 0;
}