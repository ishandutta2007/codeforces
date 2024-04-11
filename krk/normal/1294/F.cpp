#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, vector <int> > iv;

const int Maxn = 200005;
const int Maxd = 4;

int n;
vector <int> neigh[Maxn];
iv dp[Maxn][Maxd];

void Traverse(int v, int p)
{
    for (int i = 0; i < Maxd; i++)
        dp[v][i] = iv(-Maxn, vector <int>());
    dp[v][0].first = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        for (int j = Maxd - 1; j >= 0; j--)
            for (int k = 1; j + k < Maxd; k++)
                if (dp[v][j].first + dp[u][k].first + (k + 1 < Maxd) > dp[v][j + k].first) {
                    dp[v][j + k].first = dp[v][j].first + dp[u][k].first + (k + 1 < Maxd);
                    dp[v][j + k].second = dp[v][j].second;
                    for (auto it: dp[u][k].second)
                        dp[v][j + k].second.push_back(it);
                }
    }
    for (int j = Maxd - 2; j >= 0; j--)
        if (dp[v][j].first > dp[v][j + 1].first) {
            dp[v][j + 1].first = dp[v][j].first;
            dp[v][j + 1].second = dp[v][j].second;
            dp[v][j + 1].second.push_back(v);
        }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    printf("%d\n", dp[1][Maxd - 1].first);
    for (int i = 0; i < dp[1][Maxd - 1].second.size(); i++)
        printf("%d%c", dp[1][Maxd - 1].second[i], i + 1 < dp[1][Maxd - 1].second.size()? ' ': '\n');
    return 0;
}