#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000009;
const int Maxn = 1000005;

int pw2[Maxn];
int f[Maxn];

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    f[0] = 1;
    for (int i = 1; i < Maxn; i++)
        f[i] = (f[i - 1] + pw2[(i + 1) / 2]) % mod;
    int n; scanf("%d", &n);
    int sid = 1;
    int res = 2;
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 1 && i >= 5)
            sid = ll(sid) * f[i - 3] % mod;
        res = (res + 2ll * ll(sid)) % mod;
    }
    res = (ll(res) * res + 1) % mod;
    res = 2ll * res % mod;
    printf("%d\n", res);
    return 0;
}