/*
    25.08.2018 14:09:57
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
    int test_count = 1;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int t;
        cin >> t;
        for (int ttest = 0; ttest < t; ++ttest)
        {
            int n;
            cin >> n;
            string s;
            cin >> s;
            bool pal = true;
            for (int i = 0; i < n; ++i)
            {
                int dist = abs(s[i] - s[n - i - 1]);
                if (dist > 2 || dist == 1) {
                    pal = false;
                    break;
                }
            }
            if (pal) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    fclose(stdout);
    return 0;
}