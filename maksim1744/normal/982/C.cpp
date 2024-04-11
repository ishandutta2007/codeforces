/*
    17.05.2018 19:50:37
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

const bool debug = false;

vector< vector< int > > g;
vector< bool > u;
vector< int > sm;

void dfs(int v)
{
    u[v] = true;
    sm[v] = 1;
    for (int i = 0; i < g[v].size(); ++i)
    {
        if (!u[g[v][i]]) {
            dfs(g[v][i]);
            sm[v] += sm[g[v][i]];
        }
    }
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 5;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n;
        cin >> n;
        g.clear();
        g.resize(n);
        u.assign(n, false);
        sm.assign(n, 0);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (n % 2 == 1) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        dfs(0);
        for (int i = 0; i < n; ++i)
        {
            // cout << i << ' ' << sm[i] << endl;
            if (sm[i] % 2 == 0 && i != 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}