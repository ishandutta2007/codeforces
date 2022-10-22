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

    int n, k;

    scanf("%d %d", &n, &k);

    vector< int > a(n);
    for(int &x : a) scanf("%d", &x);
    sort(a.begin(), a.end());

    vector< vector< vector< int > > > dp(2, vector< vector< int > >(n + 1, vector< int >(k + 1)));

    dp[0][0][0] = 1;
    dp[0][1][0] = 1;

    for(int i = 1;i < n;i++) {
        dp[i & 1].assign(n + 1, vector< int >(k + 1, 0));
        for(int op = 0;op <= n;op++) {
            for(int dis = 0;dis <= k;dis++) {
                int cur = dp[(i - 1) & 1][op][dis];
                int ndis = dis + op * (a[i] - a[i - 1]);
                if(ndis > k) continue;
                if(op < n) _add(dp[i & 1][op + 1][ndis], cur);
                if(op > 0) _add(dp[i & 1][op][ndis], (1ll * cur * op) % mod);
                if(op > 0) _add(dp[i & 1][op - 1][ndis], (1ll * cur * op) % mod);
                _add(dp[i & 1][op][ndis], cur);
            }
        }
    }

    int result = 0;

    for(int dis = 0;dis <= k;dis++) {
        _add(result, dp[(n - 1) & 1][0][dis]);
    }

    printf("%d\n", result);

    return 0;
}