#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m;
ll l;
ll res;

ll Solve(ll k)
{
    ll res = 0;
    ll i = m + 1;
    ll mult = 2 * (i + k);
    ll val = 2 * i * k + 2 * k * l - i * l - 4 * k * k;
    ll j = min(ll(n - m), val / mult);
    for (i = m + 1; j > m && i <= n - m; i++) {
        if (mult * j >= val) j = (val - 1) / mult;
        if (j < m) j = m;
        res += j - m;
        mult += 2; val += 2 * k - l;
    }
    return res * (n % 2 == 1 && n / 2 + 1 == k? 3: 6);
}

int main()
{
    scanf("%d %d", &n, &m);
    l = 2 * n + 2;
    int lim = (n + 1) / 2;
    for (int k = m + 1; k <= lim; k++)
        res += Solve(k);
    printf("%I64d\n", res);
    return 0;
}