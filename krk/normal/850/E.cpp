#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1 << 20;
const int mod = 1000000007;

int n;
char str[Maxn + 5];
int A[Maxn], B[Maxn];

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

void FFT(int P[], bool inv)
{
    for (int len = 1; 2 * len <= (1 << n); len <<= 1)
        for (int i = 0; i < 1 << n; i += 2 * len)
            for (int j = 0; j < len; j++) {
                int u = P[i + j];
                int v = P[i + len + j];
                P[i + j] = (u + v) % mod;
                P[i + len + j] = (u - v + mod) % mod;
            }
    if (inv) {
        int mult = Inv(1 << n);
        for (int i = 0; i < 1 << n; i++)
            P[i] = ll(P[i]) * mult % mod;
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < 1 << n; i++)
        if (str[i] == '1') A[i] = 1;
        else B[i] = 1;
    FFT(A, false);
    FFT(B, false);
    for (int i = 0; i < 1 << n; i++)
        A[i] = ll(A[i]) * B[i] % mod;
    FFT(A, true);
    int res = 0;
    for (int i = 0; i < 1 << n; i++)
        res = (res + ll(A[i]) * (1 << __builtin_popcount(i))) % mod;
    res = 3ll * ll(res) % mod;
    printf("%d\n", res);
    return 0;
}