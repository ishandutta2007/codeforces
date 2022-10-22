#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int mod = 998244353;

int n, k, l;
int inv[3 * Maxn];
int ex[Maxn][Maxn], prob[Maxn][Maxn];

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

int main()
{
    scanf("%d %d %d", &n, &k, &l);
    for (int i = 1; i < 3 * Maxn; i++)
        inv[i] = Inv(i);
    l = ll(l) * inv[2 * n + 1] % mod;
    prob[0][0] = 1; ex[0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++) if (prob[i][j] || ex[i][j] || i != n || j != n) {
            int lft = 2 * n - i - j;
            int good = ll(lft - (i - j)) * inv[lft] % mod;
            int bad = ll(i - j) * inv[lft] % mod;
            prob[i + 1][j] = (prob[i + 1][j] + ll(good) * prob[i][j]) % mod;
            prob[i][j + 1] = (prob[i][j + 1] + ll(bad) * prob[i][j]) % mod;
            int nw = ll(i - j >= k) * prob[i][j] % mod;
            ex[i + 1][j] = (ex[i + 1][j] + ll(ex[i][j] + nw) * good) % mod;
            ex[i][j + 1] = (ex[i][j + 1] + ll(ex[i][j] + nw) * bad) % mod;
        }
    int res = ll(ex[n][n]) * Inv(prob[n][n]) % mod * l % mod;
    printf("%d\n", res);
    return 0;
}