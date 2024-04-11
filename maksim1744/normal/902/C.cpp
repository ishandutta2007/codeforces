/*
    07.05.2018 22:37:57
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
        int h;
        cin >> h;
        vector< int > a(h + 1);
        for (int i = 0; i <= h; ++i)
        {
            cin >> a[i];
        }
        bool ok = true;
        for (int i = 0; i < h; ++i)
        {
            if (a[i] != 1 && a[i + 1] != 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "perfect" << endl;
            continue;
        }
        cout << "ambiguous" << endl;
        int lst = 0;
        for (int i = 0; i < h + 1; ++i)
        {
            for (int j = 0; j < a[i]; ++j)
            {
                cout << lst << ' ';
            }
            lst += a[i];
        }
        cout << endl;
        lst = 0;
        int t = 0;
        for (int i = 0; i < h + 1; ++i)
        {
            if (i > 0 && a[i] != 1 && a[i - 1] != 1) {
                cout << lst - 1 << ' ';
                t = 1;
            }
            for (int j = 0; j < a[i] - t; ++j)
            {
                cout << lst << ' ';
            }
            t = 0;
            lst += a[i];
        }
        cout << endl;
    }
    fclose(stdout);
    return 0;
}