#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const ld eps = 1e-13l;
const int Maxn = 1005;
const int Maxm = 2005;

int n, t;
int s1[Maxn], s2[Maxn], t1[Maxn], t2[Maxn];
ld probfail[Maxn];
int seq[Maxn];
ldld dp[Maxn][Maxm];

ldld Better(const ldld &a, const ldld &b)
{
    if (fabs(a.first - b.first) >= eps) return a.first > b.first? a: b;
    return a.second < b.second? a: b;
}

bool Less(const int &a, const int &b)
{
    return ld(t2[a]) * probfail[a] * (1.0l - probfail[b]) < ld(t2[b]) * probfail[b] * (1.0l - probfail[a]);
}

int main()
{
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        cin >> s1[i] >> s2[i] >> t1[i] >> t2[i] >> probfail[i];
        seq[i] = i;
    }
    sort(seq, seq + n, Less);
    fill((ldld*)dp, (ldld*)dp + Maxn * Maxm, ldld(-1e18l, 0.0l));
    dp[0][0] = ldld(0.0l, 0.0l);
    for (int i = 0; i < n; i++) {
        int ind = seq[i];
        for (int j = 0; j <= t; j++) if (dp[i][j].first >= 0.0l) {
            dp[i + 1][j] = Better(dp[i + 1][j], dp[i][j]);
            if (j + t1[ind] <= t)
                dp[i + 1][j + t1[ind]] = Better(dp[i + 1][j + t1[ind]], ldld(dp[i][j].first + s1[ind], dp[i][j].second + t1[ind]));
            if (j + t1[ind] + t2[ind] <= t) {
                ld scor = dp[i][j].first + s1[ind] + ld(s2[ind]) * (1.0l - probfail[ind]);
                ld pen = t1[ind] + probfail[ind] * dp[i][j].second + (1.0l - probfail[ind]) * (j + t2[ind]);
                dp[i + 1][j + t1[ind] + t2[ind]] = Better(dp[i + 1][j + t1[ind] + t2[ind]], ldld(scor, pen));
            }
        }
    }
    ldld res = ldld(0.0l, 0.0l);
    for (int j = 0; j <= t; j++)
        res = Better(res, dp[n][j]);
    cout << fixed << setprecision(11) << res.first << " "
         << fixed << setprecision(11) << res.second << endl;
    return 0;
}