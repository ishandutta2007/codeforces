#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int Maxn = 1000004;
const int mod = 998244353;

int fac[Maxn], ifac[Maxn];
char str[Maxn];
int n;
int Q;
int A[Maxn], B[Maxn];
int res;

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
        fac[i] = ll(fac[i - 1]) * i % mod;
        ifac[i] = Inv(fac[i]);
    }
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; i++)
        Q += str[i] == '?';
    for (int i = Q; i >= 0; i--)
        B[i] = (B[i + 1] + C(Q, i)) % mod;
    for (int i = Q - 1; i >= 0; i--)
        A[i] = (A[i + 1] + C(Q - 1, i)) % mod;
    int R = 0;
    for (int i = 0; i < n; i++)
        R += str[i] == ')';
    int L = 0, ql = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == '(') {
            int nd = max(0, L - R + 1 + ql);
            if (nd <= Q) res = (res + B[nd]) % mod;
            L++;
        } else if (str[i] == '?') {
            int nd = max(0, L - R + 1 + ql);
            if (nd <= Q - 1) res = (res + A[nd]) % mod;
            ql++;
        } else R--;
    printf("%d\n", res);
    return 0;
}