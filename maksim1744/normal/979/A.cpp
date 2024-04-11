/*
    14.05.2018 17:36:00
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
        long long n;
        cin >> n;
        n++;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        if (n % 2 == 0) {
            cout << n / 2 << endl;
        }
        else {
            cout << n << endl;
        }
    }
    fclose(stdout);
    return 0;
}