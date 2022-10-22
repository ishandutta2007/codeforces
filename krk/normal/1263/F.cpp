#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int Inf = 1000000000;

int N;
int n1;
vector <int> neigh1[Maxn];
ii has1[Maxn];
int dp1[Maxn][Maxn];
int n2;
vector <int> neigh2[Maxn];
ii has2[Maxn];
int dp2[Maxn][Maxn];
int dp[Maxn][2];

void Read(int &n, vector <int> neigh[], ii has[])
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        int x; scanf("%d", &x);
        has[x] = ii(i, i);
    }
}

void Traverse(int v, vector <int> neigh[], ii has[], int dp[][Maxn])
{
    if (has[v] == ii(0, 0)) has[v] = ii(Inf, -Inf);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        Traverse(u, neigh, has, dp);
        has[v].first = min(has[v].first, has[u].first);
        has[v].second = max(has[v].second, has[u].second);
    }
    if (v != 1) dp[has[v].first][has[v].second]++;
}

void Prepare(int dp[][Maxn])
{
    for (int l = 1; l <= N; l++)
        for (int i = 1, j = i + l; j <= N; i++, j++) {
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1];
            if (i + 1 <= j - 1) dp[i][j] -= dp[i + 1][j - 1];
        }
}

int main()
{
    scanf("%d", &N);
    Read(n1, neigh1, has1);
    Read(n2, neigh2, has2);
    Traverse(1, neigh1, has1, dp1);
    Traverse(1, neigh2, has2, dp2);
    Prepare(dp1);
    Prepare(dp2);
    fill((int*)dp, (int*)dp + Maxn * 2, -Inf);
    dp[1][0] = dp[1][1] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N + 1; j++) {
            dp[j][0] = max(dp[j][0], dp[i][1] + dp2[i][j - 1]);
            dp[j][1] = max(dp[j][1], dp[i][0] + dp1[i][j - 1]);
        }
    printf("%d\n", max(dp[N + 1][0], dp[N + 1][1]));
    return 0;
}