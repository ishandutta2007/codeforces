#include <bits/stdc++.h>
using namespace std;

const int Inf = 2000000000;
const int Maxn = 200005;
const int Maxk = 8;
const int Maxm = 1 << 8;

bool oddbits[Maxm];
int cur, dp[2][Maxn];
int n, m, k;
int L[Maxn], R[Maxn];
vector <int> un;
int seq[Maxk], slen;
vector <int> op[Maxn], cl[Maxn];

void Add(int ind)
{
    seq[slen] = ind;
    for (int i = 0; i < 1 << slen; i++) {
        int best = dp[cur][i]; dp[cur][i] = -Inf;
        dp[!cur][i] = max(dp[!cur][i], best);
        int ni = (i | 1 << slen);
        dp[!cur][ni] = max(dp[!cur][ni], best);
    }
    cur = !cur;
    slen++;
}

void Rem(int ind)
{
    int pnt = 0;
    while (seq[pnt] != ind) pnt++;
    for (int i = 0; i < 1 << slen; i++) {
        int best = dp[cur][i]; dp[cur][i] = -Inf;
        int ni = ((i & ((1 << pnt) - 1)) | ((i >> (pnt + 1)) << pnt));
        dp[!cur][ni] = max(dp[!cur][ni], best);
    }
    cur = !cur;
    for (int i = pnt; i + 1 < slen; i++)
        seq[i] = seq[i + 1];
    slen--;
}

int main()
{
    for (int i = 0; i < Maxm; i++)
        oddbits[i] = __builtin_popcount(i) % 2;
    fill((int*)dp, (int*)dp + 2 * Maxn, -Inf);
    dp[cur][0] = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &L[i], &R[i]);
        un.push_back(L[i]);
        un.push_back(R[i] + 1);
    }
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n; i++) {
        L[i] = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
        op[L[i]].push_back(i);
        R[i] = upper_bound(un.begin(), un.end(), R[i]) - un.begin() - 1;
        cl[R[i]].push_back(i);
    }
    for (int i = 0; i + 1 < un.size(); i++) {
        for (int j = 0; j < op[i].size(); j++)
            Add(op[i][j]);
        for (int j = 0; j < 1 << slen; j++)
            if (oddbits[j]) dp[cur][j] += un[i + 1] - un[i];
        for (int j = 0; j < cl[i].size(); j++)
            Rem(cl[i][j]);
    }
    cout << dp[cur][0] << endl;
    return 0;
}