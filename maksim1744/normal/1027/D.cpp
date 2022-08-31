/*
    25.08.2018 14:46:48
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

vector< int > u, a, c;
int circ;
int mn;

void dfs(int v, int col) {
    // cout << "v = " << v + 1 << endl;
    if (col == 1) {
        if (u[v] == 1) {
            circ = v;
            return;
        }
        else if (u[v] != 0) {
            circ = -1;
            return;
        }
    }
    if (col == 2) {
        if (u[v] == 2) {
            return;
        }
        mn = min(mn, c[v]);
    }
    if (col == 3) {
        if (u[v] == 3) {
            return;
        }
    }
    u[v] = col;
    dfs(a[v], col);
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int test_count = 3;
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
        a.resize(n);
        c.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> c[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a[i]--;
        }
        u.assign(n, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (u[i] != 0) {
                continue;
            }
            circ = -1;
            // cout << "col = " << 1 << endl;
            dfs(i, 1);
            mn = 1000000000;
            if (circ != -1) {
                // cout << "col = " << 2 << endl;
                dfs(circ, 2);
                sum += mn;
            }
            // cout << "col = " << 3 << endl;
            dfs(i, 3);
            // cout << sum << endl;
        }
        cout << sum << endl;
    }
    fclose(stdout);
    return 0;
}