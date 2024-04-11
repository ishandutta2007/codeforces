/*
    01.08.2018 17:42:40
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
        int z[] = {1, -1};
        int res = 0;
        for (int i = 0; i < 2 * n; ++i)
        {
            int x;
            cin >> x;
            res += z[i / n] * x;
        }
        if (res >= 0) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    fclose(stdout);
    return 0;
}