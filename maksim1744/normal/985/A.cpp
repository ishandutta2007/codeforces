/*
    21.05.2018 17:46:34
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
        int n;
        cin >> n;
        vector< int > p(n / 2);
        vector< int > b(n / 2);
        for (int i = 0; i < n / 2; ++i)
        {
            cin >> p[i];
            b[i] = 2 * i + 1;
        }
        sort(p.begin(), p.end());
        int mn = 10000000;
        for (int iii = 0; iii < 2; ++iii)
        {
            int ans = 0;
            for (int i = 0; i < n / 2; ++i)
            {
                ans += abs(b[i] - p[i]);
                b[i]++;
            }
            mn = min(mn, ans);
        }
        cout << mn << endl;
    }
    fclose(stdout);
    return 0;
}