#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int simple[Maxn];
bool prime[Maxn];
int phi[Maxn];
int f[Maxn];
int sum[Maxn], sumk[Maxn], sumkk[Maxn];

int main()
{
    for (int i = 1; i < Maxn; i++) {
        simple[i] = (simple[i - 1] + ll(i - 2 + mod) % mod * i) % mod;
        phi[i] = i;
    }
    fill(prime + 2, prime + Maxn, true);
    for (int i = 2; i < Maxn; i++) if (prime[i]) {
        phi[i] -= phi[i] / i;
        for (int j = i + i; j < Maxn; j += i) {
            phi[j] -= phi[j] / i;
            prime[j] = false;
        }
    }
    for (int i = 2; i < Maxn; i++)
        for (int j = i; j < Maxn; j += i)
            f[j] = (f[j] + ll(i - 1) * phi[j / i]) % mod;
    for (int i = 1; i < Maxn; i++) {
        f[i] = ((ll(f[i]) + ll(simple[i - 1])) % mod * 2ll + ll(i) * i) % mod;
        sum[i] = (sum[i - 1] + f[i]) % mod;
        sumk[i] = (sumk[i - 1] + ll(f[i]) * i) % mod;
        sumkk[i] = (sumkk[i - 1] + ll(f[i]) * i % mod * i) % mod;
    }
    int T; scanf("%d", &T);
    while (T--) {
        int n, m; scanf("%d %d", &n, &m);
        int k = min(n, m);
        int res = (ll(n + 1) * (m + 1) % mod * sum[k]) % mod;
        res = (res - ll(n + 1 + m + 1) * sumk[k] % mod + mod) % mod;
        res = (res + sumkk[k]) % mod;
        printf("%d\n", res);
    }
    return 0;
}