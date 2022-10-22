#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 998244353;

int n;
int fac[Maxn];

int main()
{
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = ll(i) * fac[i - 1] % mod;
    scanf("%d", &n);
    int res = fac[n];
    int mult = 1;
    for (int i = n; i >= 3; i--) {
        mult = ll(mult) * i % mod;
        res = (res + ll(fac[i - 1] - 1 + mod) % mod * mult) % mod;
    }
    printf("%d\n", res);
    return 0;
}