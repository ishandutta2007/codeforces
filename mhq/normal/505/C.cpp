#include <bits/stdc++.h>
using namespace std;
const int maxN = 3 * (int)1e4 + 10;
const int limstep = 2 * sqrt(maxN);
const int inf = -(int)1e9;
int n, d;
int cnt[maxN];
int ans = 0;
int dp[maxN][2 * limstep];
int vis = 0;
int shift = 0;
int go(int cell, int jump) {
    vis++;
    if (cell > 3 * (int)1e4) return 0;
    if (dp[cell][jump - shift] != -1) return dp[cell][jump - shift];
    int cur = 0;
    for (int i = -1; i <= 1; i++) {
        if (jump + i > 0) cur = max(cur, go(cell + jump + i, jump + i));
    }
    cur += cnt[cell];
    dp[cell][jump - shift] = cur;
    ans = max(ans, cur);
    return cur;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    shift = max(1, d - limstep - 10);
    memset(dp, -1, sizeof dp);
    go(d, d);
    cout << ans << endl;
    return 0;
}