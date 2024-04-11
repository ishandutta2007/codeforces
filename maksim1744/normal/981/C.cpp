/*
    27.05.2018 18:08:01
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

vector< vector< int > > g;
vector< bool > u;
vector< int > p;

void dfs(int v) {
    u[v] = true;
    for (int i = 0; i < g[v].size(); ++i)
    {
        if (!u[g[v][i]]) {
            p[g[v][i]] = v;
            dfs(g[v][i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 4;
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
        p.assign(n, -1);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int c = -1;
        bool ok = true;
        vector< int > leafs;
        for (int i = 0; i < n; ++i)
        {
            if (g[i].size() > 2) {
                if (c != -1) {
                    ok =  false;
                }
                c = i;
            }
            if (g[i].size() == 1) {
                leafs.push_back(i);
            }
        }
        if (!ok) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        if (c == -1) {
            dfs(leafs[0]);
            int v = leafs[1];
            cout << 1 << endl;
            cout << leafs[0] + 1 << ' ' << leafs[1] + 1 << endl;
        }
        else {
            dfs(c);
            cout << leafs.size() << endl;
            for (int i = 0; i < leafs.size(); ++i)
            {
                int v = leafs[i];
                cout << v + 1 << ' ';
                while (p[v] != -1) {
                    v = p[v];
                }
                cout << v + 1 << endl;
            }
        }
    }
    fclose(stdout);
    return 0;
}