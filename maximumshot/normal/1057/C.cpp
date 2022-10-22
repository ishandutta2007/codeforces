#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 55;
const int K = 2505;

int n, s, k;

struct box {
    int r, x;
    char c;
    bool operator < (const box & o) const {
        return r < o.r;
    }
} a[N];

int dp[N][K];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &s, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i].r);
        a[i].x = i;
    }

    for(int i = 1;i <= n;i++) {
        scanf(" %c", &a[i].c);
    }


    fill((int*)dp, (int*)dp + N * K, inf);

    a[0].r = 0;
    a[0].c = '?';
    a[0].x = a[s].x;

    sort(a + 1, a + n + 1);

    dp[0][0] = 0;

    for(int i = 1;i <= n;i++) {
        for(int j = a[i].r;j < K;j++) {
            for(int fr = 0;fr < i;fr++) {
                if(a[i].c == a[fr].c || a[fr].r >= a[i].r) continue;
                dp[i][j] = min(dp[i][j], dp[fr][j - a[i].r] + abs(a[i].x - a[fr].x));
            }
        }
    }

    int res = inf;

    for(int i = 0;i <= n;i++) {
        for(int j = k;j < K;j++) {
            res = min(res, dp[i][j]);
        }
    }

    printf("%d\n", res == inf ? -1 : res);

    return 0;
}