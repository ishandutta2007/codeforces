#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table; // the usage is the same as the unordered_map

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int mod = 998244353;
const int N = 16;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector< vector< int > > a(n, vector< int >(m));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }

    if(n == 1) {
        int res = inf;
        for(int j = 0;j + 1 < m;j++) {
            res = min(res, abs(a[0][j] - a[0][j + 1]));
        }
        cout << res << "\n";
        return 0;
    }

    vector< vector< int > > diff(n, vector< int >(n));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            int mn = inf;
            for(int q = 0;q < m;q++) {
                mn = min(mn, abs(a[i][q] - a[j][q]));
            }
            diff[i][j] = mn;
        }
    }

    int dp[N][N][1 << N];

    fill((int*)dp, (int*)dp + N * N * (1 << N), 0);

    for(int mask = 1;mask < (1 << n);mask++) {
        if(__builtin_popcount(mask) == 1) {
            for(int i = 0;i < n;i++) {
                if((1 << i) & mask) {
                    dp[i][i][mask] = inf;
                }
            }
            continue;
        }
        for(int st = 0;st < n;st++) {
            if(!((1 << st) & mask)) continue;
            for(int fn = 0;fn < n;fn++) {
                if(!((1 << fn) & mask)) continue;
                if(st == fn) continue;
                if(__builtin_popcount(mask) == 2) {
                    dp[st][fn][mask] = diff[st][fn];
                }
                for(int to = 0;to < n;to++) {
                    if(!((1 << to) & mask)) continue;
                    if(to == st || to == fn) continue;
                    dp[st][fn][mask] = max(dp[st][fn][mask], min(dp[st][to][mask ^ (1 << fn)], diff[to][fn]));
                }
            }
        }
    }

    int res = 0;

    for(int st = 0;st < n;st++) {
        for(int fn = 0;fn < n;fn++) {
            if(st == fn) continue;
            int tmp = dp[st][fn][(1 << n) - 1];
            for(int j = 0;j + 1 < m;j++) {
                tmp = min(tmp, abs(a[fn][j] - a[st][j + 1]));
            }
            res = max(res, tmp);
        }
    }

    cout << res << "\n";

    return 0;
}