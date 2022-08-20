/*
    17.05.2018 19:35:56
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
        string s;
        cin >> s;
        bool ok = true;
        if (n == 1) {
            if (s[0] == '0') {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
            continue;
        }
        if (s[0] == '0' && s[1] == '0') {
            ok = false;
        }
        if (s[s.length() - 1] == '0' && s[s.length() - 2] == '0') {
            ok = false;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '1' && s[i - 1] == '1') {
                ok = false;
                break;
            }
        }
        for (int i = 2; i < s.length(); i++) {
            if (s[i] == '0' && s[i - 1] == '0' && s[i - 2] == '0') {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    fclose(stdout);
    return 0;
}