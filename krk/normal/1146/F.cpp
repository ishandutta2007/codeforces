#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxd = 3;
const int mod = 998244353;

int n;
vector <int> neigh[Maxn];
int dp[Maxn][2];
int my[Maxn][Maxd];

void Solve(int v)
{
    if (neigh[v].size() == 0)
        dp[v][0] = dp[v][1] = 1;
    else {
        my[v][0] = 1;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            Solve(u);
            for (int j = Maxd - 1; j >= 0; j--) if (my[v][j]) {
                int ways = my[v][j]; my[v][j] = 0;
                my[v][j] = (my[v][j] + ll(ways) * dp[u][0]) % mod;
                int to = min(Maxd - 1, j + 1);
                my[v][to] = (my[v][to] + ll(ways) * dp[u][1]) % mod;
            }
        }
        dp[v][0] = (my[v][0] + my[v][2]) % mod;
        dp[v][1] = (my[v][1] + my[v][2]) % mod;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Solve(1);
    printf("%d\n", dp[1][0]);
    return 0;
}