#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 1005;

int fac[Maxn];
int T;
int n;

int main()
{
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = ll(i) * fac[i - 1] % mod;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n % 2) printf("0\n");
        else {
            int res = ll(fac[n / 2]) * fac[n / 2] % mod;
            printf("%d\n", res);
        }
    }
    return 0;
}