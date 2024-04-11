/*
    11.06.2018 17:01:20
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
        long long n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << min(a * (m - n % m), b * (n % m)) << endl;
    }
    fclose(stdout);
    return 0;
}