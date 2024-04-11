#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 5005;

int n;
int a[N];
bitset< N > used;
int dp[N];
int L[N];
int R[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        if(!L[a[i]]) L[a[i]] = i;
        R[a[i]] = i;
    }

    for(int r = 1;r <= n;r++) {
        dp[r] = dp[r - 1];
        int mnl = +inf;
        int mxr = -inf;
        int xr = 0;
        used.reset();
        for(int l = r;l >= 1;l--) {
            mnl = min(mnl, L[a[l]]);
            mxr = max(mxr, R[a[l]]);
            if(!used[a[l]]) {
                used[a[l]] = 1;
                xr ^= a[l];
            }
            if(mnl >= l && mxr <= r) {
                dp[r] = max(dp[r], dp[l - 1] + xr);
            }
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}