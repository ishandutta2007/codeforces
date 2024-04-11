#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 5205;

int inv[Maxn];
int C[Maxn][Maxn];
int p, s, r;

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

int getWays(int objects, int people)
{
    if (people == 0) return objects == 0;
    return C[objects + people - 1][people - 1];
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    for (int i = 1; i < Maxn; i++)
        inv[i] = Inv(i);
    scanf("%d %d %d", &p, &s, &r);
    int A = 0, B = getWays(s - r, p);
    for (int i = r; i <= s; i++)
        for (int j = 1; j <= p && i * j <= s; j++) {
            int np = p - j, ns = s - i * j;
            int res = 0;
            for (int k = 0; k <= np && k * i <= ns; k++) {
                int add = ll(getWays(ns - k * i, np)) * C[np][k] % mod;
                if (k % 2) res = (res - add + mod) % mod;
                else res = (res + add) % mod;
            }
            A = (A + ll(C[p - 1][j - 1]) * res % mod * inv[j]) % mod;
        }
    int res = ll(A) * Inv(B) % mod;
    printf("%d\n", res);
    return 0;
}