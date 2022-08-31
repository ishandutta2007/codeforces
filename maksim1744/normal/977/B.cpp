/*
    06.05.2018 17:13:26
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
    int t = 2;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector< int > cnt(26 * 26, 0);
        for (int i = 0; i < n - 1; ++i)
        {
            int k = (s[i] - 'A') * 26 + s[i + 1] - 'A';
            cnt[k]++;
        }
        int mx = 0;
        for (int i = 0; i < 26 * 26; ++i)
        {
            mx = max(mx, cnt[i]);
        }
        for (int i = 0; i < 26 * 26; ++i)
        {
            if (mx == cnt[i]) {
                cout << (char)('A' + i / 26) << (char)('A' + i % 26) << endl;
                break;
            }
        }
    }
    fclose(stdout);
    return 0;
}