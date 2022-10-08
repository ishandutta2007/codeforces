#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, k;

int d[205];

int e[205][205];

bool visited[205];

const int INF = int(1e9);

int dp[205][205];
int choice[205];
vector<int> sons[205];

void dfs(int x) {
    visited[x] = true;
    for (int i = 1; i <= n; ++i)
        if (e[x][i] == 1 && !visited[i]) {
            sons[x].push_back(i);
            dfs(i);
        }

    dp[x][0] = INF;

    for (int center = 1; center <= n; ++center) {
        dp[x][center] = d[e[x][center]];
        for (vector<int>::iterator it = sons[x].begin(); it != sons[x].end(); ++it)
            dp[x][center] += min(dp[*it][0], dp[*it][center]);
        if (dp[x][center] + k < dp[x][0]) {
            choice[x] = center;
            dp[x][0] = dp[x][center] + k;
        }
    }
}

void retrieve(int x, int center) {
    choice[x] = center;
    for (vector<int>::iterator it = sons[x].begin(); it != sons[x].end(); ++it)
        if (dp[*it][0] < dp[*it][center])
            retrieve(*it, choice[*it]);
        else
            retrieve(*it, center);
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i < n; ++i)
        scanf("%d", &d[i]);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                e[i][j] = INF;
            else
                e[i][j] = 0;

    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);

    dfs(1);

    retrieve(1, choice[1]);

    printf("%d\n", dp[1][0]);

    for (int i = 1; i <= n; ++i) {
        printf("%d", choice[i]);
        if (i < n)
            printf(" ");
        else
            printf("\n");
    }
}