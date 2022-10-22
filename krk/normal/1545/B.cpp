#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int fac[Maxn], ifac[Maxn];
int T;
int n;
char str[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * ifac[n - k] % mod * ifac[k] % mod;
}

int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        ifac[i] = Inv(fac[i]);
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int zeroes = 0, ones = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && str[i] == str[j])
                j++;
            if (str[i] == '0') zeroes += j - i;
            else ones += (j - i) / 2;
        }
        printf("%d\n", C(ones + zeroes, ones));
    }
    return 0;
}