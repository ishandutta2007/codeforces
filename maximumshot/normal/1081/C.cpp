#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m, k;

    cin >> n >> m >> k;

    vector< vector< int > > dp(n + 1, vector< int >(k + 2));

    dp[1][1] = m;

    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= k + 1;j++) {
            dp[i][j] = (dp[i - 1][j] + 1ll * (m - 1) * dp[i - 1][j - 1] % mod) % mod;
        }
    }

    cout << dp[n][k + 1] << "\n";

    return 0;
}