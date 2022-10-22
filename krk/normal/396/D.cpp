#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int fac[Maxn];
int F[Maxn];
int n;
int p[Maxn];
int BIT[Maxn];

int goTo(int n, int i)
{
    return (ll(i - 1) * F[n - 1] % mod + ll(i - 2) * (i - 1) / 2 % mod * fac[n - 1] % mod) % mod;
}

void Insert(int x)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i]++;
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    fac[0] = 1; F[0] = 0;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        F[i] = goTo(i, i + 1);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    int inv = 0, tot = 1;
    for (int i = n - 1; i >= 0; i--) {
        int curn = n - i;
        int ind = Get(p[i]) + 1;
        inv = ((goTo(curn, ind) + ll(ind - 1) * tot % mod) % mod + inv) % mod;
        tot = (ll(fac[curn - 1]) * (ind - 1) % mod + tot) % mod;
        Insert(p[i]);
    }
    printf("%d\n", inv);
    return 0;
}