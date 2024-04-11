#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxp = 18;
const int Maxb = 36;
const int mod = 998244353;

int n, m;
int mult = 1;
ll my[Maxb];
ll seq[Maxp][1 << Maxp];
ll smallseq[1 << Maxp];
int res[Maxb];

void FWHT(ll P[], int n, bool inverse) {
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                ll u = P[i + j];
                ll v = P[i + len + j];
                P[i + j] = u + v;
                P[i + len + j] = u - v;
            }
        }
    }
    if (inverse) {
        for (int i = 0; i < n; i++)
            P[i] = P[i] / n;
    }
}

void genSmall(int lvl, int lim, ll cur)
{
    if (lvl >= lim) smallseq[cur]++;
    else {
        genSmall(lvl + 1, lim, cur);
        if (my[lvl])
            genSmall(lvl + 1, lim, (cur ^ my[lvl]));
    }
}

void genBig(int lvl, int lim, ll cur)
{
    if (lvl >= lim) {
        ll all = (1ll << ll(Maxp)) - 1ll;
        seq[__builtin_popcountll(cur >> ll(Maxp))][cur & all]++;
    } else {
        genBig(lvl + 1, lim, cur);
        if (my[lvl])
            genBig(lvl + 1, lim, (cur ^ my[lvl]));
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        ll a; scanf("%I64d", &a);
        for (int i = Maxb - 1; i >= 0; i--)
            if (a & 1ll << ll(i))
                if (my[i] == 0) { my[i] = a; break; }
                else a ^= my[i];
        if (a == 0) mult = ll(mult) * 2ll % mod;
    }
    genSmall(0, Maxp, 0);
    genBig(Maxp, Maxb, 0);
    FWHT(smallseq, 1 << Maxp, false);
    for (int i = 0; i < Maxp; i++) {
        FWHT(seq[i], 1 << Maxp, false);
        for (int j = 0; j < 1 << Maxp; j++)
            seq[i][j] *= smallseq[j];
        FWHT(seq[i], 1 << Maxp, true);
        for (int j = 0; j < 1 << Maxp; j++) {
            int b = i + __builtin_popcount(j);
            res[b] = (ll(res[b]) + seq[i][j]) % mod;
        }
    }
    for (int i = 0; i <= m; i++) {
        res[i] = ll(res[i]) * mult % mod;
        printf("%d%c", res[i], i + 1 <= m? ' ': '\n');
    }
    return 0;
}