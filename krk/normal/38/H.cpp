#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 52;
const int Inf = 1000000000;

int n, m;
int dist[Maxn][Maxn];
int g1, g2, s1, s2;
vector <ii> my[Maxn];
ll res;
int cur;
ll dp[2][Maxn][Maxn];

ll Solve(const ii &lef, const ii &rig)
{
    fill((int*)dp, (int*)dp + 2 * Maxn * Maxn, 0);
    dp[cur][0][0] = 1;
    for (int i = 0; i < n; i++) {
        bool fir = false, sec = false, thir = false;
        if (lef.second == i) fir = true;
        else if (rig.second == i) thir = true;
        else {
            fir = my[i][0] < lef;
            thir = my[i].back() > rig;
            int ind = upper_bound(my[i].begin(), my[i].end(), lef) - my[i].begin();
            sec = ind < my[i].size() && my[i][ind] < rig;
        }
        for (int a = 0; a <= i; a++)
            for (int b = 0; a + b <= i; b++) if (dp[cur][a][b] > 0) {
                ll ways = dp[cur][a][b]; dp[cur][a][b] = 0;
                if (fir) dp[!cur][a + 1][b] += ways;
                if (sec) dp[!cur][a][b + 1] += ways;
                if (thir) dp[!cur][a][b] += ways;
            }
        cur = !cur;
    }
    ll res = 0;
    for (int a = 0; a <= n; a++)
        for (int b = 0; b <= n; b++) if (dp[cur][a][b] > 0) {
            ll ways = dp[cur][a][b]; dp[cur][a][b] = 0;
            if (g1 <= a && a <= g2 && s1 <= b && b <= s2)
                res += ways;
        }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = (i != j) * Inf;
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }
    scanf("%d %d %d %d", &g1, &g2, &s1, &s2);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j)
            my[i].push_back(ii(dist[i][j], i));
        sort(my[i].begin(), my[i].end());
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (i != j && my[i][0] < my[j].back())
            res += Solve(my[i][0], my[j].back());
    cout << res << endl;
    return 0;
}