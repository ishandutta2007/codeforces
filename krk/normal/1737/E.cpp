#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int pw[Maxn], ipw[Maxn];
int T;
int n;
int f[Maxn];
int sum[Maxn];

int main()
{
    pw[0] = ipw[0] = 1;
    int inv = (mod + 1) / 2;
    for (int i = 1; i < Maxn; i++) {
        pw[i] = 2ll * pw[i - 1] % mod;
        ipw[i] = ll(inv) * ipw[i - 1] % mod;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        f[n] = 1;
        sum[n] = ll(f[n]) * ipw[n] % mod;
        for (int i = n - 1; i > 0; i--) {
            if (i > n - i) f[i] = 1;
            else {
                int j = 2 * i - 1;
                int val = (sum[i + 1] - sum[j + 1] + mod) % mod;
                f[i] = ll(val) * pw[i] % mod;
            }
            sum[i] = (sum[i + 1] + ll(f[i]) * ipw[i]) % mod;
        }
        for (int i = 1; i <= n; i++) {
            int res;
            if (i == n) res = ll(ipw[(i + 1) / 2 - 1]) * f[n] % mod;
            else if (i == 1) res = 0;
            else res = ll(ipw[(i + 1) / 2]) * f[i] % mod;
            printf("%d\n", res);
        }
    }
    return 0;
}