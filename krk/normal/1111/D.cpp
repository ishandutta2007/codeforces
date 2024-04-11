#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100015;
const int mod = 1000000007;
const int Maxm = 2 * 26;

char str[Maxn];
int slen;
int fac[Maxn], inv[Maxn];
int cnt[Maxm];
int tmp[Maxm + 1][Maxn / 2];
int cur[Maxm + 1][Maxn / 2];
int mem[Maxm][Maxm];

int getNum(char let)
{
    if (islower(let)) return let - 'a';
    return 26 + int(let - 'A');
}

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x)
{
    return toPower(x, mod - 2);
}

int A(int n, int k)
{
    return ll(fac[n]) * inv[n - k] % mod;
}

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
    }
    scanf("%s", str + 1); slen = strlen(str + 1);
    for (int i = 1; i <= slen; i++)
        cnt[getNum(str[i])]++;
    int mult = 1;
    for (int i = 0; i < Maxm; i++)
        mult = ll(mult) * inv[cnt[i]] % mod;
    tmp[Maxm][0] = 1;
    int hlf = slen / 2;
    for (int i = Maxm - 1; i >= 0; i--)
        for (int j = 0; j <= hlf; j++) {
            tmp[i][j] = tmp[i + 1][j];
            if (j >= cnt[i] && cnt[i] > 0)
                tmp[i][j] = (tmp[i][j] + ll(A(j, cnt[i])) * tmp[i + 1][j - cnt[i]]) % mod;
        }
    for (int a = 0; a < Maxm; a++) {
        cur[0][0] = 1;
        for (int i = 0; i < Maxm; i++)
            for (int j = 0; j <= hlf; j++) if (cur[i][j]) {
                int ways = cur[i][j]; cur[i][j] = 0;
                if (a == i) {
                    if (cnt[i] <= hlf)
                        mem[a][i] = (mem[a][i] + ll(ways) * tmp[i + 1][hlf - j] % mod *
                                    A(hlf, j) % mod * inv[j]) % mod;
                } else if (a < i) {
                    if (cnt[a] + cnt[i] <= hlf)
                        mem[a][i] = (mem[a][i] + ll(ways) % mod * tmp[i + 1][hlf - j] % mod *
                                    A(hlf, j) % mod * inv[j]) % mod;
                }
                cur[i + 1][j] = (cur[i + 1][j] + ways) % mod;
                if (i != a && j + cnt[i] <= hlf && cnt[i] > 0)
                    cur[i + 1][j + cnt[i]] = (cur[i + 1][j + cnt[i]] +
                                              ll(A(j + cnt[i], cnt[i])) * ways) % mod;
            }
    }
    for (int i = 0; i < Maxm; i++)
        for (int j = i; j < Maxm; j++)
            if (i == j)
                mem[i][j] = ll(mem[i][j]) * mult % mod * 2 % mod *
                            A(hlf, cnt[i]) % mod * fac[hlf - cnt[i]] % mod;
            else mem[i][j] = ll(mem[i][j]) * mult % mod * 2 % mod *
                             A(hlf, cnt[i]) % mod * A(hlf - cnt[i], cnt[j]) % mod *
                             fac[hlf - cnt[i] - cnt[j]] % mod;
    int q; scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        x = getNum(str[x]);
        y = getNum(str[y]);
        if (x > y) swap(x, y);
        printf("%d\n", mem[x][y]);
    }
    return 0;
}