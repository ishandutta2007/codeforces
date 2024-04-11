/*
    06.05.2018 17:38:37
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

vector< vector< int > > g;
vector< int > col;
int color;

void dfs(int v)
{
    col[v] = color;
    for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); i++)
    {
        if (col[*i] == -1) {
            dfs(*i);
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
        int n, m;
        cin >> n >> m;
        g.clear();
        g.resize(n);
        col.assign(n, -1);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        color = 0;
        for (int i = 0; i < n; ++i)
        {
            if (col[i] == -1) {
                dfs(i);
                color++;
            }
        }
        int ans = 0;
        vector< vector< int > > cols(color);
        for (int i = 0; i < n; ++i)
        {
            cols[col[i]].push_back(i);
        }
        for (int i = 0; i < color; ++i)
        {
            if (cols[i].size() < 3) {
                continue;
            }
            bool ok = true;
            for (int j = 0; j < cols[i].size(); ++j)
            {
                if (g[cols[i][j]].size() != 2) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}