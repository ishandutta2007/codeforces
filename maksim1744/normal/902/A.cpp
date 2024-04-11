/*
    07.05.2018 22:23:31
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
        vector< int > a(n), b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i] >> b[i];
        }
        int x = 0;
        int ind = 0;
        while (ind < n && a[ind] <= x) {
            x = max(x, b[ind]);
            ind++;
        }
        if (x >= m) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    fclose(stdout);
    return 0;
}