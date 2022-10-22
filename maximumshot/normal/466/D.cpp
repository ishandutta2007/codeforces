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

    int n, h;

    scanf("%d %d", &n, &h);

    vector< int > a(n);
    for(int &x : a) scanf("%d", &x);

    vector< vector< int > > dp(n, vector< int >(n + 1));

    if(a[0] == h) {
        dp[0][0] = 1;
    }else if(a[0] + 1 == h) {
        dp[0][0] = 1;
        dp[0][1] = 1;
    }else {
        puts("0");
        return 0;
    }

    for(int i = 1;i < n;i++) {
        for(int op = 0;op <= n;op++) {
            if(a[i] + op == h) {
                _add(dp[i][op], dp[i - 1][op]);
                if(op > 0) _add(dp[i][op], dp[i - 1][op - 1]);
            }else if(a[i] + op + 1 == h) {
                _add(dp[i][op], (1ll * dp[i - 1][op + 1] * (op + 1) % mod));
                _add(dp[i][op], (1ll * dp[i - 1][op] * (op + 1)) % mod);
            }
        }
    }

    printf("%d\n", dp[n - 1][0]);

    return 0;
}