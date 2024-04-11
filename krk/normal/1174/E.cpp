#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1000005;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
ii dp[Maxn];

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

int A(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * inv[n - k] % mod;
}

ii Merge(const ii &a, const ii &b)
{
    if (a.first != b.first) return a.first > b.first? a: b;
    return ii(a.first, (a.second + b.second) % mod);
}

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
    }
    int n; scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        if (2 * i > n) dp[i] = ii(1, 1);
        else dp[i] = ii(0, 1);
        for (int j = i + i; j <= n; j += i) {
            int tk = n / j;
            int lft = n / i - tk;
            dp[i] = Merge(dp[i], ii(dp[j].first + 1,
                                    ll(dp[j].second) * ll(lft) % mod * A(n - tk - 1, lft - 1) % mod));
        }
    }
    printf("%d\n", dp[1].second);
    return 0;
}