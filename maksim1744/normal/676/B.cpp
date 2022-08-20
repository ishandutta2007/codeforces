/*
    13.05.2018 13:43:30
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
        int n, t;
        cin >> n >> t;
        int q = 1024;
        vector< vector< int > > v(n);
        for (int i = 0; i < n; ++i)
        {
            v[i].assign(i + 1, 0);
        }
        for (int i = 0; i < t; ++i)
        {
            v[0][0] += 1024;
            bool change = false;
            for (int j = 0; j < n - 1; ++j)
            {
                change = false;
                for (int k = 0; k < j + 1; ++k)
                {
                    if (v[j][k] > 1024) {
                        change = true;
                        v[j + 1][k] += (v[j][k] - 1024) / 2;
                        v[j + 1][k + 1] += (v[j][k] - 1024) / 2;
                        v[j][k] = 1024;
                    }
                }
                if (!change) {
                    break;
                }
            }
            for (int i = 0; i < n; ++i)
            {
                v[n - 1][i] = min(v[n - 1][i], 1024);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i + 1; ++j)
            {
                if (v[i][j] >= 1024) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}