/*
    30.05.2018 16:35:31
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
        long long n, k, m, d;
        cin >> n >> k >> m >> d;
        long long mx = 0;
        for (long long t = 1; t < d + 1; ++t)
        {
            if ((long double)t * (long double)k > (long double)1e18 * (long double)4) {
                continue;
            }
            if (m >= n / (t * k)) {
                long long nx = min(m, n / (t * k - k + 1));
                mx = max(mx, nx * t);
            }
        }
        cout << mx << endl;
    }
    fclose(stdout);
    return 0;
}