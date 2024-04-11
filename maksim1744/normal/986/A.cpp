/*
    29.05.2018 18:38:10
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

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
        int n, m, k, s;
        cin >> n >> m >> k >> s;
        vector< int > a(n);
        vector< vector< int > > wh(k);
        vector< vector< int > > g(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a[i]--;
            wh[a[i]].push_back(i);
        }
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector< vector< int > > nr(n);
        for (int i = 0; i < n; ++i)
        {
            nr[i].assign(k, n);
        }
        for (int i = 0; i < k; ++i)
        {
            vector< int > now;
            vector< bool > u(n, false);
            for (int j = 0; j < wh[i].size(); ++j)
            {
                now.push_back(wh[i][j]);
                u[wh[i][j]] = true;
                nr[wh[i][j]][i] = 0;
            }
            vector< int > next;
            int d = 1;
            while (now.size() > 0) {
                next.clear();
                for (int k = 0; k < now.size(); ++k)
                {
                    for (int p = 0; p < g[now[k]].size(); ++p)
                    {
                        int v = g[now[k]][p];
                        if (!u[v]) {
                            u[v] = true;
                            next.push_back(v);
                            nr[v][i] = d;
                        }
                    }
                }
                d++;
                now.clear();
                for (int k = 0; k < next.size(); ++k)
                {
                    now.push_back(next[k]);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            sort(nr[i].begin(), nr[i].end());
            int sm = 0;
            for (int j = 0; j < s; ++j)
            {
                sm += nr[i][j];
            }
            cout << sm << ' ';
        }
        cout << endl;
    }
    fclose(stdout);
    return 0;
}