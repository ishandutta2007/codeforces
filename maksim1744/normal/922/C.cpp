/*
    13.05.2018 14:08:50
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
        long long n, k;
        cin >> n >> k;
        bool ok = true;
        for (long long i = k; i > 0; i--) {
            if (n % i != i - 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    fclose(stdout);
    return 0;
}