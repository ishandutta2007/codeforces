#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 1000000007;

int fac[Maxn], ans[Maxn];

int main()
{
    fac[0] = fac[1] = 1;
    ans[1] = 1;
    int n; scanf("%d", &n);
    for (int i = 2; i < Maxn; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        ans[i] = 2ll * ans[i - 1] % mod;
    }
    printf("%d\n", (fac[n] - ans[n] + mod) % mod);
    return 0;
}