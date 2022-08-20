/*
    24.08.2018 15:01:32
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
    int test_count = 10;
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
        int s = sqrt(n);
        if (s * s < n) {
            s++;
        }
        for (int i = 0; i < s; ++i)
        {
            for (int j = 0; j < s; ++j)
            {
                int t = (i + 1) * s - j;
                if (t <= n) {
                    cout << (i + 1) * s - j << ' ';
                }
            }
        }
        cout << endl;
        if (debug) {
            int ans = 2 * s;
            cout << "ans = " << ans << endl;
        }
    }
    fclose(stdout);
    return 0;
}