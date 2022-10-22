#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
using namespace std;
const int N = 150 + 10, ninf = 0xc0c0c0c0;
int n;
int dp[N][N][N], a[N], f[N];
char s[N];
int DP(int l, int r, int c) {
    if(l > r) return a[c];
    if(dp[l][r][c] > ninf) return dp[l][r][c];
    int &res = dp[l][r][c];
    res++;
    if(s[l] == s[r]) res = max(res, DP(l + 1, r - 1, c + 1 + (l != r)));
    for(int i = l; i < r; i++) res = max(res, DP(l, i, 0) + DP(i + 1, r, c));
    for(int i = r; i > l; i--) res = max(res, DP(l, i - 1, c) + DP(i, r, 0));
    if(c > 0) res = max(res, DP(l, r, 0) + a[c]);
    return res;
}

int main() {
    memset(dp, 0xc0, sizeof(dp));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(a[i] == -1) a[i] = ninf;
    }
    scanf("%s", s + 1);
    memset(f, 0xc0, sizeof(f));
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        for(int j = 1; j <= i; j++) {
            f[i] = max(f[i], f[j - 1] + DP(j, i, 0));
        }
    }
    printf("%d\n", f[n]);
    return 0;
}