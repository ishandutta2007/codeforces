#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5100;
int dp[N][N];
int pre[N][N], n, m, T;
array<int, 3> E[N];

int main() {
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        E[i]={u ,v, w};
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = T + 1;
    dp[n][0] = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < m; i++) {
            auto [u, v, w] = E[i];
            if (dp[v][j - 1] + w < dp[u][j]) {
                dp[u][j] = dp[v][j - 1] + w;
                pre[u][j] = v;
            }
        }
    }
    int ans = 1;
    for (int j = 1; j <= n; j++) if (dp[1][j] <= T)
        ans = j;
    printf("%d\n", ans + 1);
    vector<int> path;
    int u = 1;
    while (u != n) {
        path.push_back(u);
        u = pre[u][ans];
        --ans;
    }
    for (auto x : path) printf("%d ", x);
    printf("%d\n", n);
}