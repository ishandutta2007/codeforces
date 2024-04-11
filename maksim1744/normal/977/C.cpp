/*
    06.05.2018 17:17:13
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
        int n, k;
        cin >> n >> k;
        vector< int > v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        if (k == 0) {
            if (v[0] == 1) {
                cout << -1 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else if (k == n) {
            cout << 1000000000 << endl;
        }
        else {
            k--;
            if (v[k] == v[k + 1]) {
                cout << -1 << endl;
            }
            else {
                cout << v[k] << endl;
            }
        }
    }
    fclose(stdout);
    return 0;
}