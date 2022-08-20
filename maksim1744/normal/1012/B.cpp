/*
    01.08.2018 17:21:25
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

vector< int > parent, mrank;

void make_set (int v) {
    parent[v] = v;
    mrank[v] = 0;
}
 
int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (mrank[a] < mrank[b])
            swap (a, b);
        parent[b] = a;
        if (mrank[a] == mrank[b])
            ++mrank[a];
    }
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 6;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n, m, q;
        cin >> n >> m >> q;
        vector< vector< int > > f(n);
        for (int i = 0; i < q; ++i)
        {
            int r, c;
            cin >> r >> c;
            r--; c--;
            f[r].push_back(c);
        }
        parent.resize(m);
        mrank.resize(m);
        for (int i = 0; i < m; ++i)
        {
            make_set(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < (int)f[i].size() - 1; ++j)
            {
                union_sets(f[i][j], f[i][j + 1]);
            }
            if (f[i].size() == 0) {
                ans++;
            }
        }
        vector< bool > u(m, false);
        for (int i = 0; i < m; ++i)
        {
            u[find_set(i)] = true;
        }
        for (int i = 0; i < m; ++i)
        {
            if (u[i]) {
                ans++;
            }
        }
        cout << ans - 1 << endl;
    }
    fclose(stdout);
    return 0;
}