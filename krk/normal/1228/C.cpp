#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

ll x, n;
int ans = 1;

int toPower(int a, int x)
{
    int res = 1;
    while (x) {
        if (x & 1) res = ll(res) * a % mod;
        x >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Get(ll n, ll p)
{
    int res = 0;
    while (n > 0) {
        res = (ll(res) + n / p) % (mod - 1);
        n /= p;
    }
    return res;
}

int main()
{
    cin >> x >> n;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) {
        ans = ll(ans) * toPower(i, Get(n, i)) % mod;
        while (x % i == 0) x /= i;
    }
    if (x > 1)
        ans = ll(ans) * toPower(x, Get(n, x)) % mod;
    printf("%d\n", ans);
    return 0;
}