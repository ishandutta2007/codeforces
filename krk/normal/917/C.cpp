#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll Inf = 4000000000000000000ll;
const int Maxb = 8;
const int Maxm = 72;
const int Maxk = 30;
const int sInf = 1000000007;

int x, k, n, q;
int c[Maxb + 1];
vector <ii> quer;
int ID[1 << Maxb];
int my[Maxm], mlen;
ll best[Maxk][Maxm][Maxm];
int st, en;
ll dp[2][Maxm];
int cur;

void oneStep()
{
    for (int i = 0; i < mlen; i++) {
        ll val = dp[cur][i]; dp[cur][i] = Inf;
        int mask = my[i];
        if (mask & 1) {
            for (int j = 1; j <= k; j++) if (!(mask & 1 << j)) {
                ll add = c[j];
                int ind = lower_bound(quer.begin(), quer.end(), ii(st + j, -sInf)) - quer.begin();
                if (ind < quer.size() && quer[ind].first == st + j) add += quer[ind].second;
                int nmask = ((mask | 1 << j) >> 1);
                dp[!cur][ID[nmask]] = min(dp[!cur][ID[nmask]], val + add);
            }
        } else {
            int nmask = (mask >> 1);
            dp[!cur][ID[nmask]] = min(dp[!cur][ID[nmask]], val);
        }
    }
    cur = !cur;
    st++;
}

void sameSteps(int tims)
{
    for (int k = Maxk - 1; k >= 0; k--) if (1 << k <= tims) {
        for (int i = 0; i < mlen; i++) {
            ll val = dp[cur][i]; dp[cur][i] = Inf;
            for (int j = 0; j < mlen; j++)
                dp[!cur][j] = min(dp[!cur][j], val + best[k][i][j]);
        }
        cur = !cur;
        st += 1 << k;
        tims -= 1 << k;
    }
}

int main()
{
    scanf("%d %d %d %d", &x, &k, &n, &q);
    for (int i = 1; i <= k; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < q; i++) {
        int p, wp; scanf("%d %d", &p, &wp);
        quer.push_back(ii(p, wp));
    }
    sort(quer.begin(), quer.end());
    for (int i = 0; i < 1 << Maxb; i++) if (__builtin_popcount(i) == x) {
        ID[i] = mlen;
        my[mlen] = i;
        mlen++;
    }
    fill((ll*)best[0], (ll*)best[0] + Maxm * Maxm, Inf);
    for (int i = 0; i < mlen; i++) {
        int mask = my[i];
        if (mask & 1) {
            for (int j = 1; j <= k; j++) if (!(mask & 1 << j)) {
                int nmask = ((mask | 1 << j) >> 1);
                best[0][i][ID[nmask]] = min(best[0][i][ID[nmask]], ll(c[j]));
            }
        } else {
            int nmask = (mask >> 1);
            best[0][i][ID[nmask]] = min(best[0][i][ID[nmask]], 0ll);
        }
    }
    for (int k = 1; k < Maxk; k++)
        for (int i = 0; i < mlen; i++)
            for (int j = 0; j < mlen; j++) {
                best[k][i][j] = Inf;
                for (int l = 0; l < mlen; l++)
                    best[k][i][j] = min(best[k][i][j], best[k - 1][i][l] + best[k - 1][l][j]);
            }
    fill((ll*)dp, (ll*)dp + 2 * Maxm, Inf);
    dp[cur][ID[(1 << x) - 1]] = 0;
    st = 1, en = n + 1 - x;
    int pnt = 0;
    while (st < en) {
        while (pnt < quer.size() && quer[pnt].first < st) pnt++;
        if (pnt < quer.size() && quer[pnt].first - 8 <= st) oneStep();
        else {
            int tk = en - st;
            if (pnt < quer.size()) tk = min(tk, quer[pnt].first - 8 - st);
            sameSteps(tk);
        }
    }
    cout << dp[cur][ID[(1 << x) - 1]] << endl;
    return 0;
}