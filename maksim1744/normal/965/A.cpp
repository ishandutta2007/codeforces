/*
    30.05.2018 16:23:02
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
    int test_count = 2;
    if (!debug) {
        test_count = 1;
    }
    for (int test = 0; test < test_count; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        long long k, n, s, p;
        cin >> k >> n >> s >> p;
        long long pap = ((n + s - 1) / s) * k;
        cout << (pap + p - 1) / p << endl;
    }
    fclose(stdout);
    return 0;
}