#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 105;
const int Maxm = 60006;

int n, r;
vector <ii> pos, neg;
int dp[Maxn][Maxm];

int main()
{
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (b >= 0) pos.push_back(ii(a, b));
        else neg.push_back(ii(a + b, -b));
    }
    sort(pos.begin(), pos.end());
    int add = 0;
    for (int i = 0; i < pos.size(); i++)
        if (r < pos[i].first) break;
        else { add++; r += pos[i].second; }
    fill((int*)dp, (int*)dp + Maxn * Maxm, -Inf);
    sort(neg.begin(), neg.end());
    dp[0][0] = 0;
    for (int i = 0; i < neg.size(); i++)
        for (int j = 0; j < Maxm; j++) if (dp[i][j] >= 0) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            int cand = j;
            if (cand < neg[i].first) cand = neg[i].first;
            cand += neg[i].second;
            dp[i + 1][cand] = max(dp[i + 1][cand], dp[i][j] + 1);
        }
    int res = 0;
    for (int j = r; j >= 0; j--)
        res = max(res, dp[neg.size()][j]);
    res += add;
    printf("%d\n", res);
    return 0;
}