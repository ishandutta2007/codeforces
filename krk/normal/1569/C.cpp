#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;

int fac[Maxn], ifac[Maxn];
int T;
int n;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <int> seq;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            seq.push_back(a);
        }
        sort(seq.rbegin(), seq.rend());
        if (seq[0] == seq[1]) printf("%d\n", fac[n]);
        else if (seq[0] > seq[1] + 1) printf("0\n");
        else {
            int p = 2;
            while (p < seq.size() && seq[1] == seq[p]) p++;
            int res = ll(fac[p - 1]) * ll(p - 1) % mod * fac[int(seq.size()) - p] % mod * C(seq.size(), p) % mod;
            printf("%d\n", res);
        }
    }
    return 0;
}