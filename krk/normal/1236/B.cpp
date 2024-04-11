#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int n, m;

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
    scanf("%d %d", &n, &m);
    int p = (toPower(2, m) - 1 + mod) % mod;
    int res = toPower(p, n);
    printf("%d\n", res);
    return 0;
}