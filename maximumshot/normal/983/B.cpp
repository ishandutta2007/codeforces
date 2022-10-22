#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

const int N = 5005;

int n;
int a[N];
int dp[N][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int l = n;l >= 1;l--) {
        for(int r = l;r <= n;r++) {
            if(l == r) {
                dp[l][r] = a[l];
            }else {
                dp[l][r] = dp[l][r - 1] ^ dp[l + 1][r];
            }
        }
    }

    for(int l = n;l >= 1;l--) {
        for(int r = l + 1;r <= n;r++) {
            dp[l][r] = max(dp[l][r], dp[l][r - 1]);
            dp[l][r] = max(dp[l][r], dp[l + 1][r]);
        }
    }

    int q;

    scanf("%d", &q);

    for(int l, r, i = 1;i <= q;i++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", dp[l][r]);
    }

    return 0;
}