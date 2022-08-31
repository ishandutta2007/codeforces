/*
    30.05.2018 14:25:39
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
        int n;
        cin >> n;
        vector< int > s(n);
        vector< int > c(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> c[i];
        }
        vector< int > c2(n, -1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (s[i] > s[j] && (c2[i] == -1 || c2[i] > c[j])) {
                    c2[i] = c[j];
                }
            }
            if (c2[i] != -1) {
                c2[i] += c[i];
            }
        }
        vector< int > c3(n, -1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (s[i] > s[j] && c2[j] != -1 && (c3[i] == -1 || c3[i] > c2[j])) {
                    c3[i] = c2[j];
                }
            }
            if (c3[i] != -1) {
                c3[i] += c[i];
            }
        }
        int mn = -1;
        for (int i = 0; i < n; ++i)
        {
            if (c3[i] != -1 && (mn == -1 || mn > c3[i])) {
                mn = c3[i];
            }
        }
        cout << mn << endl;
    }
    fclose(stdout);
    return 0;
}