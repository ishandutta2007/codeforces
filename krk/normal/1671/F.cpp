#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxk = 12;
const int Maxm = 30;

int inv[Maxk];
int ways[Maxm][Maxm][Maxk][Maxk];
bool tk[Maxm];
int seq[Maxm], slen;
int T;

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
    int res = 1;
    for (int i = 1; i <= k; i++)
        res = ll(res) * (n + 1 - i) % mod * inv[i] % mod;
    return res;
}

void Gen(int lvl, int invs, int inds, int mx)
{
    if (invs >= Maxk || inds >= Maxk) return;
    if (lvl == mx) {
        ways[1][lvl][invs][inds]++;
        if (lvl) return;
    }
    for (int i = 1; i < Maxm; i++) if (!tk[i]) {
        seq[slen++] = i; tk[i] = true;
        int ninds = inds + int(slen > 1 && seq[slen - 1] < seq[slen - 2]);
        Gen(lvl + 1, invs, ninds, max(mx, i));
        slen--; tk[i] = false;
        invs++;
    }
}

int main()
{
    for (int i = 1; i < Maxk; i++)
        inv[i] = Inv(i);
    Gen(0, 0, 0, 0);
    for (int i = 2; i < Maxm; i++)
        for (int a = 1; a < Maxm; a++)
            for (int b = 1; b < Maxk; b++)
                for (int c = 1; c < Maxk; c++)
                    for (int a2 = 1; a + a2 < Maxm; a2++)
                        for (int b2 = 1; b + b2 < Maxk; b2++)
                            for (int c2 = 1; c + c2 < Maxk; c2++)
                                ways[i][a + a2][b + b2][c + c2] = (ways[i][a + a2][b + b2][c + c2] + ll(ways[i - 1][a][b][c]) * ways[1][a2][b2][c2]) % mod;
    scanf("%d", &T);
    while (T--) {
        int n, k, x; scanf("%d %d %d", &n, &k, &x);
        int res = 0;
        for (int i = 1; i < Maxm; i++)
            for (int j = 1; j < Maxm; j++) if (ways[i][j][k][x]) {
                res = (res + ll(ways[i][j][k][x]) * C(n + i - j, i)) % mod;
            }
        printf("%d\n", res);
    }
    return 0;
}