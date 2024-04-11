/*
    06.05.2018 19:37:51
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1 && s[0] == '0') {
            cout << "0\n";
        }
        else {
            int c = 0;
            cout << '1';
            for (int i = 0; i < n; ++i)
            {
                if (s[i] == '0') {
                    cout << '0';
                }
            }
            cout << '\n';
        }
    }
    fclose(stdout);
    return 0;
}