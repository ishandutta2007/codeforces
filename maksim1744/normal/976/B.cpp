/*
    06.05.2018 19:42:07
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
    int t = 3;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        long long n, m, k;
        cin >> n >> m >> k;
        if (k <= n - 1) {
            cout << 1 + k << ' ' << 1 << endl;
            continue;
        }
        k -= n;
        long long y = n - k / (m - 1);
        k = k % (2 * (m - 1));
        long long x;
        if (k < m - 1) {
            x = 2 + k;
        }
        else {
            x = m - (k - (m - 1));
        }
        cout << y << ' ' << x << endl;
    }
    fclose(stdout);
    return 0;
}