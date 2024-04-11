#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;

int fac[Maxn], inv[Maxn];
string A, B;
int c00, c01, c10, c11;

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
    return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int Ways(int elems, int groups)
{
    if (groups < 0) return 0;
    if (groups == 0) return elems == 0;
    return C(elems + groups - 1, elems);
}

int All(int zers, int zgroups, int ones, int ogroups)
{
    return ll(Ways(zers, zgroups)) * Ways(ones, ogroups) % mod;
}

int Solve(const string &s, int c00, int c01, int c10, int c11)
{
    if (s.size() == 0) return 0;
    if (c10 < c01 || c10 - 1 > c01) return 0;
    int ones = c10 + (c10 == c01);
    int zers = c10;
    bool curone = false;
    int mylen = ones + zers + c00 + c11;
    if (mylen > s.length()) return 0;
    if (mylen < s.length()) return All(c00, zers, c11, ones);
    zers++;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0')
            if (curone) { curone = false; ones--; }
            else c00--;
        else {
            if (i > 0)
                if (curone)
                    res = (res + All(c00, zers, c11, ones - 1)) % mod;
                else res = (res + All(c00 - 1, zers, c11, ones)) % mod;
            if (!curone) { curone = true; zers--; }
            else c11--;
        }
    res = (res + All(c00, zers, c11, ones)) % mod;
    return res;
}

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
    }
    cin >> A;
    cin >> B;
    scanf("%d %d %d %d", &c00, &c01, &c10, &c11);
    int res = Solve(B, c00, c01, c10, c11);
    int pnt = int(A.length()) - 1;
    while (A[pnt] == '0') A[pnt--] = '1';
    A[pnt] = '0';
    pnt = 0;
    while (pnt < A.length() && A[pnt] == '0') pnt++;
    A = A.substr(pnt);
    res = (res - Solve(A, c00, c01, c10, c11) + mod) % mod;
    printf("%d\n", res);
    return 0;
}