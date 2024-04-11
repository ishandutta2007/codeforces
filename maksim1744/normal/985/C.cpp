/*
    21.05.2018 17:59:11
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
    int test_count = 4;
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
        int m = n * k;
        vector< long long > a(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int last = 0;
        while (last < m && a[last] <= a[0] + d) {
            last++;
        }
        last--;
        if (last + 1 < n) {
            cout << 0 << endl;
            continue;
        }
        vector< bool > u(m, false);
        int cnt = 0;
        long long v = 0;
        for (int i = 0; i < last + 1; i += k)
        {
            u[i] = true;
            v += a[i];
            cnt++;
        }
        int ind = last;
        while (cnt < n) {
            if (u[ind]) {
                ind--;
            }
            else {
                u[ind] = true;
                v += a[ind];
                cnt++;
            }
        }
        cout << v << endl;
    }
    fclose(stdout);
    return 0;
}