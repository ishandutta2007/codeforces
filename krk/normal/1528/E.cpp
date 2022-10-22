#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000006;
const int mod = 998244353;

int inv2, inv6;
int n;
int dp[Maxn], sum[Maxn], spec[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int Take(int arr[], int ind, int cnt)
{
    if (ind < 0) return 0;
    if (cnt == 1) return arr[ind];
    else if (cnt == 2) return ll(arr[ind]) * (arr[ind] + 1) % mod * inv2 % mod;
    else return ll(arr[ind]) * (arr[ind] + 1) % mod * (arr[ind] + 2) % mod * inv6 % mod;
}

int main()
{
    inv2 = Inv(2);
    inv6 = Inv(6);
    scanf("%d", &n);
    dp[0] = sum[0] = spec[0] = 1;
    for (int i = 1; i <= n; i++) {
        spec[i] = (ll(Take(sum, i - 2, 1)) * Take(dp, i - 1, 1) + ll(Take(dp, i - 1, 2))) % mod;
        dp[i] = (spec[i] + ll(Take(dp, i - 1, 1))) % mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    int res = (ll(Take(sum, n - 2, 2)) * Take(dp, n - 1, 1) + ll(Take(sum, n - 2, 1)) * Take(dp, n - 1, 2) + ll(Take(dp, n - 1, 3))) % mod;
    res = (res + spec[n]) % mod;
    res = 2ll * res % mod;
    int cur = 0, pnt = 0;
    for (int i = n; i >= 0; i--) {
        while (i + pnt < n) cur = (cur + spec[pnt++]) % mod;
        res = (res + ll(spec[i]) * cur) % mod;
    }
    printf("%d\n", res);
    return 0;
}