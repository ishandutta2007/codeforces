#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long double ld;

#define info(x) cerr << #x << " = " << x << endl
#define vec vector
#define ALL(x) (x).begin(), (x).end()

int const inf = 1e9;
ll const inf64 = 1e18;

const int N = 22;

int n, m;
int g[N];
int dp[1 << N];
pii from[1 << N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        u--;
        v--;
        g[u] |= (1 << v);
        g[v] |= (1 << u);
    }

    for(int v = 0;v < n;v++) {
        g[v] |= (1 << v);
    }

    fill(dp, dp + (1 << N), inf);

    for(int mask = 1;mask < (1 << n);mask++) {
        int ok = 1;
        for(int v = 0;v < n;v++) {
            if(!((1 << v) & mask)) continue;
            if((mask & g[v]) ^ mask) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            dp[mask] = 0;
            from[mask] = make_pair(0, -1);
        }
        for(int v = 0;v < n;v++) {
            if(!((1 << v) & mask)) continue;
            int next_mask = mask | g[v];
            if(dp[next_mask] > dp[mask] + 1) {
                dp[next_mask] = dp[mask] + 1;
                from[next_mask] = make_pair(mask, v);
            }
        }
    }

    printf("%d\n", dp[(1 << n) - 1]);

    vec< int > res;

    for(int mask = (1 << n) - 1;mask > 0;) {
        int prev_mask, v;
        tie(prev_mask, v) = from[mask];
        if(v >= 0) {
            res.push_back(v);
        }
        mask = prev_mask;
    }

    reverse(ALL(res));

    for(int x : res) {
        printf("%d ", x + 1);
    }

    printf("\n");

    return 0;
}