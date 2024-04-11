#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table; // the usage is the same as the unordered_map

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = inf + 7;

inline void _add(int &x, int y) {
    if((x += y) >= mod) x -= mod;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m, x;

    scanf("%d %d %d", &n, &m, &x);

    if(n > m) {
        puts("0");
        return 0;
    }

    vector< vector< vector< int > > > dp(m + 1, vector< vector< int > >(n + 1, vector< int >(n + 1)));

    dp[0][0][0] = 1;

    for(int i = 1;i <= m;i++) {
        for(int op = 0;op <= n && op <= i;op++) {
            for(int all = 0;all + op <= n && all + op <= i;all++) {
                if(i != x) _add(dp[i][all][op], dp[i - 1][all][op]);
                if(op > 0 && i != x) _add(dp[i][all + 1][op - 1], dp[i - 1][all][op]);
                if(all + 1 <= n) _add(dp[i][all + 1][op], dp[i - 1][all][op]);
                if(op + 1 <= n) _add(dp[i][all][op + 1], dp[i - 1][all][op]);
            }
        }
    }

//    cout << dp[1][0][0] << " " << dp[1][1][0] << " " << dp[1][0][1] << " ?\n";
//    cout << dp[2][1][0] << " ?\n";

    int fc = 1;
    for(int i = 1;i <= n;i++) {
        fc = (1ll * fc * i) % mod;
    }

    printf("%d\n", (1ll * dp[m][n][0] * fc) % mod);

    return 0;
}