#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;
const int mod = 998244353;

int fac[Maxn], ifac[Maxn];
int n, k;
vector <ii> seq;

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
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        seq.push_back(ii(l, -1));
        seq.push_back(ii(r, 1));
    }
    sort(seq.begin(), seq.end());
    int res = 0, st = 0;
    for (int i = 0; i < seq.size(); i++)
        if (seq[i].second == -1) {
            st++;
            res = (res + C(st - 1, k - 1)) % mod;
        } else st--;
    printf("%d\n", res);
    return 0;
}