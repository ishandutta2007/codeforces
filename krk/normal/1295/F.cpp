#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 105;

int inv[Maxn];
int n;
int L[Maxn], R[Maxn];
vector <int> un;
int dp[Maxn][Maxn][Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x)
{
    return toPower(x, mod - 2);
}

int C(ll n, ll k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    if (n >= mod || k >= mod) return ll(C(n / mod, k / mod)) * C(n % mod, k % mod) % mod;
    int res = 1;
    for (int i = 1; i <= k; i++)
        res = ll(res) * (n + 1 - i) % mod * inv[i] % mod;
    return res;
}

int main()
{
    for (int i = 1; i < Maxn; i++)
        inv[i] = Inv(i);
    scanf("%d", &n);
    for (int i = n - 1; i >= 0; i--) {
        scanf("%d %d", &L[i], &R[i]);
        un.push_back(L[i]);
        un.push_back(R[i] + 1);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int totinv = Inv(R[i] - L[i] + 1);
        for (int j = 0; j + 1 < un.size(); j++) {
            int siz = un[j + 1] - un[j];
            for (int k = 0; k <= i; k++) if (dp[i][j][k]) {
                // skip
                if (j + 2 < un.size())
                    dp[i][j + 1][0] = (dp[i][j + 1][0] +
                                       ll(dp[i][j][k]) * C(siz - 1 + k, k) % mod *
                                       Inv(toPower(siz, k))) % mod;
                // take
                if (L[i] <= un[j] && un[j] <= R[i])
                    dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] +
                                           ll(dp[i][j][k]) * siz % mod * totinv) % mod;
            }
        }
    }
    int res = 0;
    for (int j = 0; j + 1 < un.size(); j++) {
        int siz = un[j + 1] - un[j];
        for (int k = 0; k <= n; k++) if (dp[n][j][k])
            res = (res + ll(dp[n][j][k]) * C(siz - 1 + k, k) % mod * Inv(toPower(siz, k))) % mod;
    }
    printf("%d\n", res);
    return 0;
}