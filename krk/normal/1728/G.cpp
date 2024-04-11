#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxk = 16;
const int Maxm = 1 << 16;
const int mod = 998244353;

int dp[Maxk][Maxk];
int dplef[Maxk], dprig[Maxk];
int dpall;
int tmp[Maxm];
int d, n, m;
int L[Maxn];
int P[Maxk];

int Dist(int val, int ind, int a, int b)
{
    int res = d + 1;
    if (a >= 0) res = min(res, val - P[a]);
    if (b < m) res = min(res, P[b] - val);
    return res;
}

void Clear(int val)
{
    fill((int*)dp, (int*)dp + Maxk * Maxk, val);
    fill(dplef, dplef + Maxk, val);
    fill(dprig, dprig + Maxk, val);
    dpall = val;
}

int main()
{
    Clear(1);
    scanf("%d %d %d", &d, &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &L[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &P[i]);
    sort(P, P + m);
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(P, P + m, L[i]) - P;
        for (int a = ind - 1; a >= 0; a--) {
            for (int b = ind; b < m; b++) {
                int dist = Dist(L[i], ind, a, b);
                dp[a][b] = ll(dp[a][b]) * dist % mod;
            }
            int dist = Dist(L[i], ind, a, m);
            dplef[a] = ll(dplef[a]) * dist % mod;
        }
        for (int b = ind; b < m; b++) {
            int dist = Dist(L[i], ind, -1, b);
            dprig[b] = ll(dprig[b]) * dist % mod;
        }
        int dist = Dist(L[i], ind, -1, m);
        dpall = ll(dpall) * dist % mod;
    }
    int res = 0;
    for (int i = 0; i < 1 << m; i++) {
        tmp[i] = 1;
        if (i == 0) {
            tmp[i] = ll(tmp[i]) * dpall % mod;
            continue;
        }
        int lef = 0;
        while (!(i & 1 << lef)) lef++;
        tmp[i] = ll(tmp[i]) * dprig[lef] % mod;
        int rig = m - 1;
        while (!(i & 1 << rig)) rig--;
        tmp[i] = ll(tmp[i]) * dplef[rig] % mod;
        for (int j = lef + 1; j <= rig; j++) if (i & 1 << j) {
            tmp[i] = ll(tmp[i]) * dp[lef][j] % mod;
            lef = j;
        }
    }
    Clear(0);
    for (int i = 0; i < 1 << m; i++) {
        int val = __builtin_popcount(i) % 2? (mod - tmp[i]) % mod: tmp[i];
        if (i == 0) {
            dpall = val;
            continue;
        }
        int lef = 0;
        while (!(i & 1 << lef)) lef++;
        dprig[lef] = (dprig[lef] + val) % mod;
        int rig = m - 1;
        while (!(i & 1 << rig)) rig--;
        dplef[rig] = (dplef[rig] + val) % mod;
        for (int j = lef + 1; j <= rig; j++) if (i & 1 << j) {
            dp[lef][j] = (dp[lef][j] + val) % mod;
            lef = j;
        }
    }
    int q; scanf("%d", &q);
    while (q--) {
        int f; scanf("%d", &f);
        int ans = 0;
        int ind = lower_bound(P, P + m, f) - P;
        for (int a = ind - 1; a >= 0; a--) {
            for (int b = ind; b < m; b++) {
                int dist = Dist(f, ind, a, b);
                ans = (ans + ll(dist) * dp[a][b]) % mod;
            }
            int dist = Dist(f, ind, a, m);
            ans = (ans + ll(dist) * dplef[a]) % mod;
        }
        for (int b = ind; b < m; b++) {
            int dist = Dist(f, ind, -1, b);
            ans = (ans + ll(dist) * dprig[b]) % mod;
        }
        int dist = Dist(f, ind, -1, m);
        ans = (ans + ll(dist) * dpall) % mod;
        printf("%d\n", ans);
    }
    return 0;
}