#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 10100;
const ll inf = 1e18;

int n, x, pos[maxn], cnt;
int lt[maxn], rt[maxn], add[maxn];
ll dp[maxn][2];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> x;
    pos[cnt++] = x;
    for (int i=0; i<n; i++) {
        cin >> lt[i] >> rt[i];
        pos[cnt++] = lt[i], pos[cnt++] = rt[i];
    }

    sort(pos, pos+cnt);
    cnt = unique(pos, pos+cnt) - pos;

    x = lower_bound(pos, pos+cnt, x)-pos;
    for (int i=0; i<n; i++) {
        lt[i] = lower_bound(pos, pos+cnt, lt[i])-pos;
        rt[i] = lower_bound(pos, pos+cnt, rt[i])-pos;
    }

    for (int i=0; i<cnt; i++)
        if (i != x)
            dp[i][0] = inf;

    for (int i=0; i<n; i++) {
        int b = i&1;
        ll best = inf;
        for (int j=0; j<cnt; j++) {
            best = min(best, dp[j][b] - pos[j]);
            add[j] = j < lt[i] ? pos[lt[i]]-pos[j] : j >= rt[i] ? pos[j]-pos[rt[i]] : 0;
            dp[j][!b] = best + pos[j] + add[j];
        }

        best = inf;
        for (int j=cnt-1; j>=0; j--) {
            best = min(best, dp[j][b] + pos[j]);
            dp[j][!b] = min(dp[j][!b], best - pos[j] + add[j]);
        }
    }

    ll ans = inf;
    for (int i=0; i<cnt; i++) ans = min(ans, dp[i][n&1]);
    cout << ans << '\n';
}