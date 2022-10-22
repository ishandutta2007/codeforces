#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n, m;
int fac[Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &m);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = ll(fac[i - 1]) * i % m;
    for (int l = 1; l <= n; l++) {
        int add = ll(n - l + 1) * (n - l + 1) % m * fac[l] % m * fac[n - l] % m;
        res = (res + add) % m;
    }
    printf("%d\n", res);
    return 0;
}