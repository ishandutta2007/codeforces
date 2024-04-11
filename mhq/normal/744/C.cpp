#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 16;
int dp[(1 << maxN) + 10][maxN * maxN + 2];
int r[maxN], b[maxN];
char c[maxN];
int valR[(1 << maxN) + 10], valC[(1 << maxN) + 10];
int n;
const int INF = (int)1e9 + 100;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int sr = 0;
    int sc = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> r[i] >> b[i];
        if (c[i] == 'R') valR[(1 << i)] = 1;
        else valC[(1 << i)] = 1;
        sr += r[i];
        sc += b[i];
    }
    for (int bit = 0; bit < n; bit++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << bit)) {
                valR[mask] += valR[mask ^ (1 << bit)];
                valC[mask] += valC[mask ^ (1 << bit)];
            }
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int saved = 0; saved <= n * n; saved++) {
            dp[mask][saved] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int saved = 0; saved <= n * n; saved++) {
            if (dp[mask][saved] < 0) continue;
            for (int bit = 0; bit < n; bit++) {
                if (mask & (1 << bit)) continue;
                int saveR = min(r[bit], valR[mask]);
                int saveC = min(b[bit], valC[mask]);
                dp[mask | (1 << bit)][saved + saveR] = max(dp[mask | (1 << bit)][saved + saveR], dp[mask][saved] + saveC);
            }
        }
    }
    int f = INF;
    int all = (1 << n) - 1;
    for (int saved = 0; saved <= n * n; saved++) {
        if (dp[all][saved] < 0) continue;
        f = min(f, max(sr - saved, sc - dp[all][saved]));
    }
    cout << f + n;
    return 0;
}