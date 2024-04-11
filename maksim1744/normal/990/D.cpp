/*
    11.06.2018 17:45:53
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
    int test_count = 5;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n, a, b;
        cin >> n >> a >> b;
        if (a > 1 && b > 1) {
            cout << "NO\n";
            continue;
        }
        char c0 = '0', c1 = '1';
        if (a == 1 & b != 1) {
            c1 = '0';
            c0 = '1';
            a = b;
        }
        char m[n][n];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                m[i][j] = c0;
            }
        }
        if (a == 1) {
            if (n <= 3 && n > 1) {
                cout << "NO\n";
                continue;
            }
            for (int i = 0; i < n - 1; ++i)
            {
                m[i][i + 1] = '1';
                m[i + 1][i] = '1';
            }
        }
        else {
            for (int i = 1; i < n - (a - 1); ++i)
            {
                m[i][0] = c1;
                m[0][i] = c1;
            }
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j) {
                    m[i][j] = '0';
                }
                cout << m[i][j];
            }
            cout << endl;
        }
    }
    fclose(stdout);
    return 0;
}