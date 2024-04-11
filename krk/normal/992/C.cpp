#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

ll x, k;

int toPower(int a, ll p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1ll; a = ll(a) * a % mod;
    }
    return res;
}

int main()
{
    scanf("%I64d %I64d", &x, &k);
    if (x == 0) { printf("0\n"); return 0; }
    int a = toPower(2, k + 1), b = (toPower(2, k) - 1 + mod) % mod;
    int res = x % mod * ll(a) % mod;
    res = (res - b + mod) % mod;
    printf("%d\n", res);
    return 0;
}