/*
    30.05.2018 16:28:07
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
    int test_count = 3;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n, k;
        cin >> n >> k;
        bool f[n][n];
        int sm[n][n];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                sm[i][j] = 0;
                char c;
                cin >> c;
                if (c == '.') {
                    f[i][j] = true;
                }
                else {
                    f[i][j] = false;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                bool ok = true;
                for (int t = 0; t < k; ++t)
                {
                    if (i + t >= n || !f[i + t][j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    for (int t = 0; t < k; ++t)
                    {
                        sm[i + t][j]++;
                    }
                }
                ok = true;
                for (int t = 0; t < k; ++t)
                {
                    if (i + t >= n || !f[j][i + t]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    for (int t = 0; t < k; ++t)
                    {
                        sm[j][i + t]++;
                    }
                }
            }
        }
        int mx = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (sm[i][j] > mx) {
                    mx = sm[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        cout << x + 1 << ' ' << y + 1 << endl;
    }
    fclose(stdout);
    return 0;
}