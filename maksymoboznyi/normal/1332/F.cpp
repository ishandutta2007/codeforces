#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e5 + 5;
const int M = 998244353;

int n, kol[N][2][2];
vector<int> g[N];

void dfs(int v, int p = -1) {
    for (auto u: g[v])
        if (u != p)
            dfs(u, v);
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] == p) {
            g[v].erase(g[v].begin() + i);
            break;
        }
    kol[v][0][0] = 1;
    kol[v][1][0] = 1;
    kol[v][1][1] = 1;
    for (auto u: g[v]) {
        kol[v][0][0] *= (kol[u][0][0] + (kol[u][1][0] + kol[u][1][1]) * (g[u].size() > 0)) % M;
        kol[v][1][0] *= (kol[u][0][0] + (kol[u][1][0] + kol[u][1][1]) * (g[u].size() > 0) +    kol[u][0][0] + kol[u][0][0] + (kol[u][1][0] + kol[u][1][1]) * (g[u].size() > 0)) % M;
        kol[v][1][1] *= (kol[u][0][0] + (kol[u][1][0] + kol[u][1][1]) * (g[u].size() > 0) +    kol[u][0][0] + kol[u][1][0] * (g[u].size() > 0));

        kol[v][0][0] %= M;
        kol[v][1][0] %= M;
        kol[v][1][1] %= M;
    }
    //cout << kol[v][0][0] << ' ' << kol[v][1][0] << endl;
    if (g[v].size() != 0) {
        kol[v][1][0] -= kol[v][0][0];
        kol[v][1][1] -= kol[v][0][0];
    }

    kol[v][1][0] += M;
    kol[v][1][1] += M;

    kol[v][1][0] %= M;
    kol[v][1][1] %= M;

 //   cout << v << ' ' << kol[v][0][0] << ' ' << kol[v][1][1] << ' ' << kol[v][1][0] <<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    cout << (kol[1][0][0] + kol[1][1][1] + kol[1][1][0] - 1) % M;
    return 0;
}