#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Maxl = 26;
const int Maxk = 300005;
const ll Inf = 1000000000000000000ll;

int n, m, k;
char B[Maxn][Maxn];
int qa[Maxk], qb[Maxk], qc[Maxk], qd[Maxk];
char qe[Maxk];
int cnt[Maxl][Maxn][Maxn];
int my[Maxl];
ll G[Maxn][Maxn];
ll dp[Maxl][Maxn][Maxn];
ll res = Inf;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%s", B[i] + 1);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d %c", &qa[i], &qb[i], &qc[i], &qd[i], &qe[i]);
        int ind = qe[i] - 'a';
        cnt[ind][qa[i]][qb[i]]++;
        cnt[ind][qa[i]][qd[i] + 1]--;
        cnt[ind][qc[i] + 1][qb[i]]--;
        cnt[ind][qc[i] + 1][qd[i] + 1]++;
    }
    for (int ind = 0; ind < Maxl; ind++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cnt[ind][i][j] += cnt[ind][i - 1][j] + cnt[ind][i][j - 1] - cnt[ind][i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int gind = B[i][j] - 'a';
            int lft = k;
            for (int ind = 0; ind < Maxl; ind++)
                lft -= cnt[ind][i][j];
            cnt[gind][i][j] += lft;
            int sum = 0, c = 0;
            fill(my, my + Maxl, 0);
            for (int ind = 0; ind < Maxl; ind++) {
                my[ind] = c * ind - sum;
                c += cnt[ind][i][j];
                sum += cnt[ind][i][j] * ind;
            }
            sum = 0, c = 0;
            for (int ind = Maxl - 1; ind >= 0; ind--) {
                my[ind] += sum - c * ind;
                c += cnt[ind][i][j];
                sum += cnt[ind][i][j] * ind;
                dp[ind][i][j] += my[ind];
            }
            G[i][j] += my[gind];
        }
    for (int ind = 0; ind < Maxl; ind++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[ind][i][j] += dp[ind][i - 1][j] + dp[ind][i][j - 1] - dp[ind][i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            G[i][j] += G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1];
    for (int i = 0; i < k; i++) {
        int ind = qe[i] - 'a';
        ll cand = G[n][m] - (G[qc[i]][qd[i]] - G[qc[i]][qb[i] - 1] - G[qa[i] - 1][qd[i]] + G[qa[i] - 1][qb[i] - 1]);
        cand += dp[ind][qc[i]][qd[i]] - dp[ind][qc[i]][qb[i] - 1] - dp[ind][qa[i] - 1][qd[i]] + dp[ind][qa[i] - 1][qb[i] - 1];
        res = min(res, cand);
    }
    cout << res << endl;
    return 0;
}