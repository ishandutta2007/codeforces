/*
    14.05.2018 17:56:19
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

long long n, x, y;
vector< vector< int > > g;
vector< int > col;
int color;
vector< bool > u;

void dfs(int v, int p = -1)
{
    u[v] = true;
    col[v] = p;
    for (int i = 0; i < g[v].size(); ++i)
    {
        if (!u[g[v][i]]) {
            dfs(g[v][i], v);
        }
    }
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 2;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        cin >> n >> x >> y;
        x--;
        y--;
        g.clear();
        g.resize(n);
        for (int i = 0; i < n - 1; ++i)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        col.assign(n, -1);
        color = 0;
        u.assign(n, false);
        dfs(x);
        int vy = col[y];
        int v = y;
        while (col[v] != x) {
            v = col[v];
        }
        int vx = v;
        u.assign(n, false);
        u[vx] = true;
        dfs(x);
        long long cx = -1;
        for (int i = 0; i < n; ++i)
        {
            if (u[i]) {
                cx++;
            }
        }
        u.assign(n, false);
        u[vy] = true;
        dfs(y);
        long long cy = -1;
        for (int i = 0; i < n; ++i)
        {
            if (u[i]) {
                cy++;
            }
        }
        cout << n * (n - 1) - cx * cy << endl;
    }
    fclose(stdout);
    return 0;
}