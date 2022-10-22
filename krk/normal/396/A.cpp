#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxm = 32000;

int fac[Maxm], inv[Maxm];
int n;
map <int, int> pr;
int res = 1;

int Inv(int a, int p = mod - 2)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int C_(int n, int k) { return ll(fac[n + k - 1]) * inv[k] % mod * inv[n - 1] % mod; }

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxm; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        for (int j = 2; j * j <= a; j++)
            if (a % j == 0)
                do {
                    pr[j]++;
                    a /= j;
                } while (a % j == 0);
        if (a > 1) pr[a]++;
    }
    for (map <int, int>::iterator it = pr.begin(); it != pr.end(); it++)
        res = ll(res) * C_(n, it->second) % mod;
    printf("%d\n", res);
    return 0;
}