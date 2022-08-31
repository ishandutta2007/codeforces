/*
    07.05.2018 22:30:45
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

vector< vector< int > > g;
int ans;
vector< bool > u;
vector< int > c;

void dfs(int v, int col)
{
    u[v] = true;
    if (c[v] != col) {
        col = c[v];
        ans++;
    }
    for (int i = 0; i < g[v].size(); ++i)
    {
        if (!u[g[v][i]]) {
            dfs(g[v][i], col);
        }
    }
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t = 2;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n;
        cin >> n;
        g.clear();
        g.resize(n);
        for (int i = 0; i < n - 1; ++i)
        {
            int u;
            cin >> u;
            u--;
            g[i + 1].push_back(u);
            g[u].push_back(i + 1);
        }
        c.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> c[i];
        }
        ans = 0;
        u.assign(n, false);
        dfs(0, 0);
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}