#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
int n;
vector<int> g[N];
int lvl[N], par[N];

int dfs1(int v, int sz, int &center, int p = -1) {
    int sum = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (lvl[g[v][i]] == -1 && g[v][i] != p)
            sum += dfs1(g[v][i], sz, center, v);
    if (center == -1 && 2 * sum >= sz)
        center = v;
    return sum;
}

void build(int v, int dep, int p = 0) {
    int center = -1, tmp, sz;
    dfs1(v, dfs1(v, sz, tmp), center);
    lvl[center] = dep;
   // cout <<v <<' ' << center << ' ' << lvl[center] << endl;
    par[center] = p;
    for (int i = 0; i < g[center].size(); i++)
        if (lvl[g[center][i]] == -1)
            build(g[center][i], dep + 1, center);

}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        lvl[i] = -1;

    build(1, 1);
    for (int i = 1; i <= n; i++)
        cout << char('A' + lvl[i] - 1) << ' ';
    return 0;
}