#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
int dp[Maxn][3];

void Solve(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Solve(u, v);
    }
    vector <int> R(neigh[v].size() + 1);
    R[neigh[v].size()] = 1;
    for (int i = int(neigh[v].size()) - 1; i >= 0; i--) {
        int u = neigh[v][i];
        if (u == p) R[i] = R[i + 1];
        else R[i] = ll(R[i + 1]) * dp[u][0] % mod;
    }
    // all
    int L = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        dp[v][0] = (dp[v][0] + ll(L) * dp[u][2] % mod * R[i + 1]) % mod;
        L = ll(L) * dp[u][1] % mod;
    }
    dp[v][0] = (dp[v][0] + L) % mod;
    // before parent
    L = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) {
            dp[v][1] = (dp[v][1] + ll(L) * R[i + 1]) % mod;
            break;
        }
        dp[v][1] = (dp[v][1] + ll(L) * dp[u][2] % mod * R[i + 1]) % mod;
        L = ll(L) * dp[u][1] % mod;
    }
    // after parent
    L = 1;
    bool was = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) { was = true; continue; }
        if (was) dp[v][2] = (dp[v][2] + ll(L) * dp[u][2] % mod * R[i + 1]) % mod;
        L = ll(L) * dp[u][1] % mod;
    }
    dp[v][2] = (dp[v][2] + L) % mod;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Solve(1, 0);
    printf("%d\n", dp[1][0]);
    return 0;
}