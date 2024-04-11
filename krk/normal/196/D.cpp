#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 400005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod1, mod2;
int pw1[Maxn], pw2[Maxn];
int ipw1[Maxn], ipw2[Maxn];
ii H[Maxn], R[Maxn];
int d;
char str[Maxn];
int slen;
char res[Maxn];

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int toPower(int a, int p, int mod)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x, int mod) { return toPower(x, mod - 2, mod); }

ii getHash(int l, int r)
{
    ii res = H[r];
    if (--l >= 0) {
        res.first = ll(res.first - H[l].first + mod1) * ipw1[l + 1] % mod1;
        res.second = ll(res.second - H[l].second + mod2) * ipw2[l + 1] % mod2;
    }
    return res;
}

ii getReverse(int l, int r)
{
    ii res = R[r];
    if (--l >= 0) {
        res.first = (res.first - ll(pw1[r - l]) * R[l].first % mod1 + mod1) % mod1;
        res.second = (res.second - ll(pw2[r - l]) * R[l].second % mod2 + mod2) % mod2;
    }
    return res;
}

bool Solve(int lvl, bool bigger)
{
    if (lvl >= slen) return bigger;
    char from = bigger? 'a': str[lvl];
    for (res[lvl] = from; res[lvl] <= 'z'; res[lvl]++) {
        int val = res[lvl] - 'a' + 1;
        if (lvl > 0) {
            H[lvl] = H[lvl - 1];
            R[lvl] = ii(ll(R[lvl - 1].first) * pw1[1] % mod1, ll(R[lvl - 1].second) * pw2[1] % mod2);
        } else {
            H[lvl] = ii(0, 0);
            R[lvl] = ii(0, 0);
        }
        H[lvl].first = (H[lvl].first + ll(val) * pw1[lvl]) % mod1;
        H[lvl].second = (H[lvl].second + ll(val) * pw2[lvl]) % mod2;
        R[lvl].first = (R[lvl].first + val) % mod1;
        R[lvl].second = (R[lvl].second + val) % mod2;
        if (lvl + 1 >= d && getHash(lvl - d + 1, lvl) == getReverse(lvl - d + 1, lvl)) continue;
        if (lvl >= d && getHash(lvl - d, lvl) == getReverse(lvl - d, lvl)) continue;
        if (Solve(lvl + 1, bigger || str[lvl] < res[lvl])) return true;
    }
    return false;
}

int main()
{
    mod1 = uniform_int_distribution<int>(500000000, 1000000000)(rng);
    mod2 = uniform_int_distribution<int>(500000000, 1000000000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    pw1[0] = pw2[0] = 1;
    pw1[1] = uniform_int_distribution<int>(1000000, 2000000)(rng);
    pw2[1] = uniform_int_distribution<int>(1000000, 2000000)(rng);
    while (!Prime(pw1[1])) pw1[1]++;
    while (!Prime(pw2[1])) pw2[1]++;
    for (int i = 2; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * pw1[1] % mod1;
        pw2[i] = ll(pw2[i - 1]) * pw2[1] % mod2;
    }
    for (int i = 0; i < Maxn; i++) {
        ipw1[i] = Inv(pw1[i], mod1);
        ipw2[i] = Inv(pw2[i], mod2);
    }
    scanf("%d", &d);
    scanf("%s", str); slen = strlen(str);
    if (Solve(0, false)) {
        res[slen] = '\0';
        printf("%s\n", res);
    } else printf("Impossible\n");
    return 0;
}