#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 50;

struct PrimePower {
    int p, cnt, tot;
    PrimePower(int p = 0, int cnt = 0, int tot = 0): p(p), cnt(cnt), tot(tot) {}
};

int n, P, L, R;
ii fac[Maxm][Maxn], ifac[Maxm][Maxn];
vector <PrimePower> pr;

void gcd(int a, int &x, int b, int &y)
{
    if (a == 0) { x = 0; y = 1; }
    else {
        int xx, yy; gcd(b % a, xx, a, yy);
        x = yy - b / a * xx;
        y = xx;
    }
}

int getInv(int a, int mod)
{
    int x, y; gcd(a, x, mod, y);
    x %= mod;
    if (x < mod) x += mod;
    return x;
}

void Prec(const PrimePower &x, ii fac[], ii ifac[])
{
    fac[0] = ifac[0] = ii(1, 0);
    for (int i = 1; i < Maxn; i++) {
        fac[i] = fac[i - 1];
        int num = i;
        while (num % x.p == 0) {
            fac[i].second++;
            num /= x.p;
        }
        fac[i].first = ll(fac[i].first) * num % x.tot;
        ifac[i].first = getInv(fac[i].first, x.tot);
        ifac[i].second = fac[i].second; 
    }
}

int getC(const PrimePower &x, int n, int k, ii fac[], ii ifac[])
{
    if (n < 0 || k < 0 || k > n) return 0;
    int res = ll(fac[n].first) * ifac[k].first % x.tot * ifac[n - k].first % x.tot;
    int rem = fac[n].second - ifac[k].second - ifac[n - k].second;
    if (rem >= x.cnt) return 0;
    while (rem--)
        res = ll(res) * x.p % x.tot;
    return res;
}

int Solve(const PrimePower &x, ii fac[], ii ifac[])
{
    Prec(x, fac, ifac);
    int res = 0;
    for (int d = L; d <= n; d++) {
        int lef = d - R >= 0? (d - R + 1) / 2: 0;
        int rig = (d - L) / 2;
        if (lef > rig) continue;
        int add = (getC(x, d, rig, fac, ifac) - getC(x, d, lef - 1, fac, ifac) + x.tot) % x.tot;
        res = (res + ll(add) * getC(x, n, d, fac, ifac)) % x.tot;
    }
    return res;
}

int main()
{
    scanf("%d %d %d %d", &n, &P, &L, &R);
    for (ll i = 2; i * i <= P; i++) if (P % i == 0) {
        int cnt = 0;
        int tot = 1;
        while (P % i == 0) {
            P /= i;
            tot *= i;
            cnt++;
        }
        pr.push_back(PrimePower(i, cnt, tot));
    }
    if (P > 1) pr.push_back(PrimePower(P, 1, P));
    int val1 = 0, mod1 = 1;
    for (int i = 0; i < pr.size(); i++) {
        auto x = pr[i];
        int val2 = Solve(x, fac[i], ifac[i]);
        int mod2 = x.tot;
        int mod3 = mod1 * mod2;
        int imod2 = getInv(mod2, mod1);
        int imod1 = getInv(mod1, mod2);
        int val3 = (ll(val1) * mod2 % mod3 * imod2 % mod3 + ll(val2) * mod1 % mod3 * imod1 % mod3) % mod3;
        val1 = val3;
        mod1 = mod3;
    }
    printf("%d\n", val1);
    return 0;
}