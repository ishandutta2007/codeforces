#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int n;
int h[Maxn];
int root;
vector <int> neigh[Maxn];
ll dp[Maxn][2];
ll mx[Maxn];

void Traverse(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        dp[v][0] += dp[u][0];
        mx[v] = max(mx[v], mx[u]);
    }
    if (mx[v] < h[v]) {
        dp[v][0] += h[v] - mx[v];
        mx[v] = h[v];
    }
}

void Solve(int v, int p)
{
    ll best = Inf;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Solve(u, v);
        dp[v][1] += dp[u][0];
        best = min(best, dp[u][1] - dp[u][0]);
    }
    if (best < 0) dp[v][1] += best;
}

int main()
{
    scanf("%d", &n);
    root = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        if (h[i] > h[root]) root = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(root, 0);
    Solve(root, 0);
    vector <ll> improve;
    ll res = 2 * h[root];
    for (int i = 0; i < neigh[root].size(); i++) {
        int v = neigh[root][i];
        res += dp[v][0];
        improve.push_back(dp[v][1] - dp[v][0]);
    }
    sort(improve.begin(), improve.end());
    for (int i = 0; i < improve.size() && i < 2; i++)
        res += improve[i];
    cout << res << endl;
    return 0;
}