#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 250005;
const int Maxm = 10000007;
const ll Inf = 4000000000000000000ll;

int n, m;
vector <int> BH[Maxn], BC[Maxn];
int H[Maxm];
ll C[Maxm];
int par[Maxm];
int seq[Maxm], slen;
int L[Maxm], R[Maxm];
ll dp[Maxm];
int tmp[Maxm], tlen;

int getPar(int x)
{
    if (x < 0) x = 0;
    else if (x > m + 1) x = m + 1;
    tlen = 0;
    while (par[x] != x) {
        tmp[tlen++] = x;
        x = par[x];
    }
    for (int i = 0; i < tlen; i++)
        par[tmp[i]] = x;
    return x;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int k; scanf("%d", &k);
        BH[i].resize(k);
        BC[i].resize(k);
        for (int j = 0; j < k; j++)
            scanf("%d", &BH[i][j]);
        for (int j = 0; j < k; j++)
            scanf("%d", &BC[i][j]);
    }
    int pnt = 1;
    int q; scanf("%d", &q);
    while (q--) {
        int id, mult; scanf("%d %d", &id, &mult);
        for (int i = 0; i < BH[id].size(); i++) {
            H[pnt] = BH[id][i];
            C[pnt] = ll(BC[id][i]) * mult;
            pnt++;
        }
    }
    slen = 0;
    par[m + 1] = m + 1;
    R[m + 1] = m + 1;
    seq[slen++] = m + 1;
    for (int i = m; i >= 1; i--) {
        par[i] = i;
        R[i] = i + 1;
        R[i] = R[getPar(i + H[i] - 1)];
        while (slen > 0 && R[seq[slen - 1]] <= R[i]) {
            par[seq[slen - 1]] = i;
            slen--;
        }
        seq[slen++] = i;
    }
    slen = 0;
    par[0] = 0;
    L[0] = 0;
    seq[slen++] = 0;
    for (int i = 1; i <= m; i++) {
        par[i] = i;
        L[i] = i - 1;
        L[i] = L[getPar(i - H[i] + 1)];
        while (slen > 0 && L[seq[slen - 1]] >= L[i]) {
            par[seq[slen - 1]] = i;
            slen--;
        }
        seq[slen++] = i;
    }
    fill(dp, dp + m + 2, Inf);
    slen = 0;
    par[m + 1] = m + 1;
    dp[m + 1] = 0;
    seq[slen++] = m + 1;
    for (int i = m; i > 0; i--) {
        par[i] = i;
        dp[L[i] + 1] = min(dp[L[i] + 1], dp[i + 1] + C[i]);
        dp[i] = min(dp[i], C[i] + dp[getPar(R[i])]);
        while (slen > 0 && dp[seq[slen - 1]] >= dp[i]) {
            par[seq[slen - 1]] = i;
            slen--;
        }
        seq[slen++] = i;
    }
    dp[0] = min(dp[0], dp[1]);
    cout << dp[0] << endl;
    return 0;
}