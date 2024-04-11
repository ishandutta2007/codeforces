/*
    25.08.2018 15:15:33
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = false;
const long long mod = 998244353;

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
        long long d[n + 1][n + 1];
        for (int i = 0; i < n + 1; ++i)
        {
            for (int j = 0; j < n + 1; ++j)
            {
                d[i][j] = 0;
            }
        }
        d[0][0] = 1;
        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 0; j < i + 1; ++j)
            {
                for (int k = 1; k < j; ++k)
                {
                    d[i][j] += d[i - k][j];
                }
                for (int k = 0; k <= j; ++k)
                {
                    d[i][j] += d[i - j][k];
                }
                d[i][j] %= mod;
            }
        }
        // for (int i = 0; i < n + 1; i++) {
        //     for (int j = 0; j < n + 1; j++) {

        //         cout << d[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        long long ans = 0;
        for (int i = 0; i < n + 1; ++i)
        {
            for (int j = 0; (i * j < k) && (j < n + 1); j++) {
                ans = (ans + d[n][i] * d[n][j]) % mod;
            }
        }
        ans = (ans * 2) % mod;
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}