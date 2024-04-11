#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <complex>
#include <unordered_map>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

bool solve() {
    
    int n, m, k;    

    scanf("%d %d %d", &n, &m, &k);

    vec< vec< int > > g(n, vec< int >(n, 0));
    vec< int > a(n);

    for(int i = 0;i < n;i++) scanf("%d", &a[i]); 

    for(int x, y, c, i = 0;i < k;i++) {
        scanf("%d %d %d", &x, &y, &c);
        x--, y--;
        g[x][y] = c;
    }

    vec< vec< int > > cur(n + 1);

    for(int mask = 1;mask < (1 << n);mask++) {
        int cnt_bit = 0;
        for(int i = 0;i < n;i++) if((1 << i) & mask) cnt_bit++;
        cur[cnt_bit].push_back(mask);
    }

    vec< vec< ll > > dp(1 << n, vec< ll >(n, 0));
    // dp[mask][last]

    for(int i = 0;i < n;i++) {
        dp[1 << i][i] = a[i];
    }

    for(int i = 1;i < m;i++) {
        for(int j = 0;j < (int)cur[i].size();j++) {
            int mask = cur[i][j];
            for(int last = 0;last < n;last++) {
                if(!((1 << last) & mask)) continue;
                for(int u = 0;u < n;u++) {
                    if((1 << u) & mask) continue;
                    int to_mask = mask ^ (1 << u);
                    dp[to_mask][u] = max(dp[to_mask][u], dp[mask][last] + a[u] + g[last][u]);
                }
            }
        }
    }

    ll ans = 0;

    for(int i = 0;i < (int)cur[m].size();i++) {
        int mask = cur[m][i];
        for(int last = 0;last < n;last++) {
            if(!((1 << last) & mask)) continue;
            ans = max(ans, dp[mask][last]);
        }
    }

    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}