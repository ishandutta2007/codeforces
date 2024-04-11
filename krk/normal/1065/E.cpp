#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

int n, m, a;
int res = 1;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &m, &a);
    int lst = 0;
    for (int i = 1; i <= m; i++) {
        int b; scanf("%d", &b);
        int len = b - lst; lst = b;
        int cur = toPower(a, len);
        res = ll(cur) * (cur + 1) % mod * inv2 % mod * res % mod;
    }
    int len = n - 2 * lst;
    int cur = toPower(a, len);
    res = ll(res) * cur % mod;
    printf("%d\n", res);
    return 0;
}