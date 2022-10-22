#include <bits/stdc++.h>
using namespace std;
 
typedef long double ld;
typedef long long ll;
 
const int mod = 1000000007;
const int Maxn = 105;
const int Maxm = Maxn * Maxn;
const int Maxs = 5000;
 
int n;
int c[Maxn];
int b[Maxn];
int dp[Maxn][Maxm];
ll nd[Maxn];
int neg[Maxs];
int pos[Maxn];

void calcNd(int x)
{
    ll sum = 0;
    ll cur = x;
    for (int i = 0; i < n; i++) {
        if (i > 0) cur += b[i - 1];
        sum += cur;
        nd[i] = sum;
    }
}

bool Possible(int x)
{
    calcNd(x);
    ll my = 0;
    for (int i = 0; i < n; i++) {
        my += c[i];
        if (my < nd[i]) return false;
    }
    return true;
}

bool canAll(int x)
{
    calcNd(x);
    for (int i = 0; i < n; i++)
        if (0 < nd[i]) return false;
    return true;
}

int Solve(int x)
{
    calcNd(x);
    dp[0][0] = 1; dp[0][1] = mod - 1;
    for (int i = 0; i < n; i++) {
        int to = i * Maxn;
        int ways = 0;
        for (int j = 0; j <= to; j++) {
            ways = (ways + dp[i][j]) % mod;
            dp[i][j] = 0;
            if (ways == 0) continue;
            ll k = max(0ll, nd[i] - j);
            if (k > c[i]) continue;
            dp[i + 1][j + k] = (dp[i + 1][j + k] + ways) % mod;
            dp[i + 1][j + c[i] + 1] = (dp[i + 1][j + c[i] + 1] - ways + mod) % mod;
        }
    }
    int res = 0;
    int ways = 0;
    int to = n * Maxn;
    for (int j = 0; j <= to; j++) {
        ways = (ways + dp[n][j]) % mod;
        dp[n][j] = 0;
        res = (res + ways) % mod;
    }
    return res;
}
 
int main()
{
    scanf("%d", &n);
    int all = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        all = ll(all) * (c[i] + 1) % mod;
    }
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &b[i]);
    int pnt = 0;
    while (pnt < Maxs && !Possible(-pnt)) pnt++;
    while (!canAll(-pnt)) {
        neg[pnt] = Solve(-pnt);
        pnt++;
    }
    for (int i = 0; i < Maxn; i++)
        pos[i] = Solve(i);
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        if (x <= -pnt) printf("%d\n", all);
        else if (x < 0) printf("%d\n", neg[-x]);
        else if (x < Maxn) printf("%d\n", pos[x]);
        else printf("0\n");
    }
    return 0;
}