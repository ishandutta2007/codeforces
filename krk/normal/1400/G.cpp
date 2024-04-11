#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxm = 42;
const int mod = 998244353;

int fac[Maxn];
int ifac[Maxn];
int n, m;
int L[Maxn], R[Maxn];
int A[Maxn], B[Maxn];
int cnt[Maxn];
int spec[Maxn][Maxm];
int res;
int tk[Maxn];

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
    return ll(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

void Gen(int lvl, int myL, int myR, int cnt, int mult)
{
    if (myL > myR) return;
    if (lvl >= m) {
        if (mult == 1) {
            spec[myL][cnt] = (spec[myL][cnt] + 1) % mod;
            spec[myR + 1][cnt] = (spec[myR + 1][cnt] - 1 + mod) % mod;
        } else {
            spec[myL][cnt] = (spec[myL][cnt] - 1 + mod) % mod;
            spec[myR + 1][cnt] = (spec[myR + 1][cnt] + 1) % mod;
        }
    }
    else {
        Gen(lvl + 1, myL, myR, cnt, mult);
        if (tk[A[lvl]]++ == 0) {
            cnt++;
            myL = max(myL, L[A[lvl]]);
            myR = min(myR, R[A[lvl]]);
        }
        if (tk[B[lvl]]++ == 0) {
            cnt++;
            myL = max(myL, L[B[lvl]]);
            myR = min(myR, R[B[lvl]]);
        }
        Gen(lvl + 1, myL, myR, cnt, -mult);
        tk[A[lvl]]--; tk[B[lvl]]--;
    }
}

int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &L[i], &R[i]);
        cnt[L[i]]++; cnt[R[i] + 1]--;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &A[i], &B[i]);
        A[i]--; B[i]--;
    }
    Gen(0, 1, n, 0, 1);
    for (int i = 1; i <= n; i++) {
        cnt[i] = (cnt[i] + cnt[i - 1]) % mod;
        for (int j = 0; j < Maxm; j++) {
            spec[i][j] = (spec[i][j] + spec[i - 1][j]) % mod;
            res = (res + ll(spec[i][j]) * C(cnt[i] - j, i - j)) % mod;
        }
    }
    printf("%d\n", res);
    return 0;
}