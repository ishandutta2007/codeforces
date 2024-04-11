/*
    21.05.2018 19:12:51
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
        int n, k, d;
        cin >> n >> k >> d;
        vector< int > a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector< int > rt(n, 0);
        vector< bool > can(n);
        int i1 = 0, i2 = 0;
        while (i1 < n) {
            while (i2 < n && a[i2] - a[i1] <= d) {
                i2++;
            }
            rt[i1] = i2 - 1;
            can[i1] = (i2 - i1 >= k);
            i1++;
        }
        // for (int i = 0; i < n; ++i)
        // {
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
        vector< int > sm(n + k + 5, 0);
        vector< bool > ok(n, false);
        for (int i = n - 1; i > -1; i--) {
            if (i + k <= n && (sm[i + k] - sm[rt[i] + 2] > 0 || rt[i] + 1 == n)) {
                ok[i] = true;
                sm[i] = sm[i + 1] + 1;
            }
            else {
                ok[i] = false;
                sm[i] = sm[i + 1];
            }
        }
        // for (int i = 0; i < n + 5; ++i)
        // {
        //     cout << sm[i] << ' ';
        // }
        // cout << endl;
        if (ok[0]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    fclose(stdout);
    return 0;
}