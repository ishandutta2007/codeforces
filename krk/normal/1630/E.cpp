#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 998244353;

int fac[Maxn], ifac[Maxn];
int inv[Maxn];
int T;
int n;
int cnt[Maxn];
int ways[Maxn], val[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        inv[i] = toPower(i, mod - 2);
        ifac[i] = ll(ifac[i - 1]) * inv[i] % mod;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(cnt, cnt + n + 1, 0);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            cnt[a]++;
        }
        int g = 0;
        for (int i = 1; i <= n; i++)
            g = gcd(g, cnt[i]);
        if (g == n) { printf("1\n"); continue; }
        fill(ways, ways + g + 1, 0);
        fill(val, val + g + 1, 0);
        int A = 0, B = 0;
        for (int i = g; i > 0; i--) if (g % i == 0) {
            ways[i] = fac[n / i];
            val[i] = n;
            for (int j = 1; j <= n; j++) if (cnt[j]) {
                ways[i] = ll(ways[i]) * ifac[cnt[j] / i] % mod;
                int sub = ll(cnt[j] / i) * inv[n / i] % mod * (cnt[j] / i - 1) % mod * inv[n / i - 1] % mod * n % mod;
                val[i] = (val[i] - sub + mod) % mod;
            }
            val[i] = ll(val[i]) * ways[i] % mod;
            for (int j = i + i; j <= g; j += i) {
                ways[i] = (ways[i] - ways[j] + mod) % mod;
                val[i] = (val[i] - ll(ways[j]) * val[j] % mod + mod) % mod;
            }
            val[i] = ll(val[i]) * toPower(ways[i], mod - 2) % mod;
            int aways = ll(ways[i]) * inv[n / i] % mod;
            A = (A + ll(aways) * val[i]) % mod;
            B = (B + aways) % mod; 
        }
        A = ll(A) * toPower(B, mod - 2) % mod;
        printf("%d\n", A);
    }
    return 0;
}