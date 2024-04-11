#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxk = 101;
const int Inf = 1000000007;

int T;
int n, m;
int a[Maxn];
int qe[Maxn], qt[Maxn], qp[Maxn];
vector <int> byjob[Maxn];
int dp[Maxn][Maxk];
ii par[Maxn][Maxk];
vector <int> ans;

int Get(const vector <int> &V)
{
    for (int i = 0; i <= V.size(); i++)
        fill(dp[i], dp[i] + Maxk, Inf);
    dp[0][0] = 0;
    for (int i = 0; i < V.size(); i++) {
        int ind = V[i];
        for (int j = Maxk - 1; j >= 0; j--) if (dp[i][j] < Inf) {
            if (dp[i][j] < dp[i + 1][j]) {
                dp[i + 1][j] = dp[i][j];
                par[i + 1][j] = ii(j, -1);
            }
            int nj = min(Maxk - 1, j + qp[ind]);
            if (dp[i][j] + qt[ind] < dp[i + 1][nj]) {
                dp[i + 1][nj] = dp[i][j] + qt[ind];
                par[i + 1][nj] = ii(j, ind);
            }
        }
    }
    if (dp[V.size()][Maxk - 1] >= Inf) return Inf;
    int res = dp[V.size()][Maxk - 1];
    int v = Maxk - 1;
    for (int i = V.size(); i > 0 && v; i--) {
        if (par[i][v].second != -1)
            ans.push_back(par[i][v].second);
        v = par[i][v].first;
    }
    return res;
}

bool Solve()
{
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += Get(byjob[i]);
        if (cur > a[i]) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            byjob[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d", &qe[i], &qt[i], &qp[i]);
            byjob[qe[i]].push_back(i);
        }
        ans.clear();
        if (Solve()) {
            printf("%d\n", int(ans.size()));
            for (int i = 0; i < ans.size(); i++)
                printf("%d%c", ans[i], i + 1 < ans.size()? ' ': '\n');
        } else printf("-1\n");
    }
    return 0;
}