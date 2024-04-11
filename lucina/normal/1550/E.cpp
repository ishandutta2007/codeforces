#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int K = 17;
int n, k;
char s[nax];
int dp[1 << K];
int max_consecutive[17];
int last_possible[17];
int nxt[nax][K];
bool ok(int x) {
    memset(max_consecutive, 0, sizeof(max_consecutive));
    memset(last_possible, 0x3f, sizeof(last_possible));
    //printf("ALIVE\n");
 
    for (int i = n ; i >= 1 ; -- i) {
        if (s[i] == '?') {
            for (int j = 0 ; j < k ; ++ j)
                max_consecutive[j] += 1;
        } else {
            max_consecutive[s[i] - 'a'] += 1;
            for (int j = 0 ; j < k ; ++ j) {
                if (j + 'a' == s[i]) continue;
                max_consecutive[j] = 0;
            }
        }
        for (int j = 0 ; j < k ; ++ j) {
            if (max_consecutive[j] >= x) last_possible[j] = i + x;
            nxt[i][j] = last_possible[j];
        }
    }
 
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 1;
    for (int msk = 0 ; msk < (1 << k) ; ++ msk) {
        if (dp[msk] > n) continue;
        int cur = dp[msk];
        for (int i = 0 ; i < k ; ++ i) {
            if (msk >> i & 1) continue;
            int nxt_msk = msk | (1 << i);
            dp[nxt_msk] = min(dp[nxt_msk], nxt[cur][i]);
        }
    }
    return dp[(1 << k) - 1] <= n + 1;
}

int main() {
    scanf("%d %d %s", &n, &k, s + 1);
    int ans = 0;
    int l = 1, r = n;
 
    while (l <= r) {
        int mid = l + r >> 1;
        if (ok(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d\n", ans);
}

/**
Let's consider something for a second.
How can we check answer for unique X?
i.e. the maximum contagious block exceed it.
 
For example, we can use some damning dp[i][mask]
Is it possible to make first i characters matched
the character in mask..
Well this is rather slow.
 
Look at it other way around.
dp[mask] = minimum index such that we satisfy constraint in mask.
The only problem now is how to advanced this dp in O(1)?
Possibly, we want to make array next(i, k) the minimum position such that
we can satisfy constraint consecutive k-th letter after i
*/