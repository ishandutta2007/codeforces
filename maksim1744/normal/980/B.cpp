/*
    08.05.2018 18:10:44
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
    int t = 9;
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
        char f[4][n];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                f[j][i] = '.';
            }
        }
        bool ok = true;
        for (int i = 0; i < k / 2; ++i)
        {
            f[1][i + 1] = '#';
            f[2][i + 1] = '#';
        }
        if (k % 2 != 0) {
            if (k % 4 == 1) {
                if (k == 2 * (n - 2) - 1) {
                    if (n >= 5) {
                        for (int i = 0; i < n - 2; ++i)
                        {
                            f[1][i + 1] = '#';
                            f[2][i + 1] = '#';
                        }
                        f[1][2] = '.';
                    }
                    else {
                        for (int i = 0; i < 4; ++i)
                        {
                            for (int j = 0; j < n; ++j)
                            {
                                f[i][j] = '.';
                            }
                        }
                        f[1][1] = '#';
                    }
                }
                else {
                    if (k == 1) {
                        for (int i = 0; i < 4; ++i)
                        {
                            for (int j = 0; j < n; ++j)
                            {
                                f[i][j] = '.';
                            }
                        }
                        f[1][n / 2] = '#';
                    }
                    else {
                        f[1][1] = '.';
                        f[2][1] = '.';
                        f[1][k / 2 + 1] = '#';
                        f[2][k / 2 + 1] = '#';
                        f[1][(k / 2 + 2 + n - 1) / 2] = '#';
                    }
                }
            }
            else {
                f[1][(n - 1 + (k + 1) / 2) / 2] = '#';
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES" << endl;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << f[i][j];
            }
            cout << endl;
        }
    }
    fclose(stdout);
    return 0;
}