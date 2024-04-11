/*
    08.05.2018 18:05:58
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
    int t = 4;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        string s;
        cin >> s;
        int nb = 0, nv = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'o') {
                nb++;
            }
            else {
                nv++;
            }
        }
        if (nb == 0 || nv % nb == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    fclose(stdout);
    return 0;
}