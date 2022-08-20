/*
    27.05.2018 17:52:16
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
        string s;
        cin >> s;
        int mx = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = i; j < s.length(); ++j)
            {
                bool pal = true;
                for (int k = 0; k <= j - i; k++) {
                    if (s[i + k] != s[j - k]) {
                        pal = false;
                        break;
                    }
                }
                if (!pal) {
                    mx = max(mx, j - i + 1);
                }
            }
        }
        cout << mx << endl;
    }
    fclose(stdout);
    return 0;
}