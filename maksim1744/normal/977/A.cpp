/*
    06.05.2018 17:06:03
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
        int n, k;
        cin >> n >> k;
        while (k > 0) {
            if (n % 10 > k) {
                n -= k;
                break;
            }
            else if (n % 10 == 0) {
                k--;
                n /= 10;
            }
            else {
                k -= n % 10;
                n -= n % 10;
            }
        }
        cout << n << endl;
    }
    fclose(stdout);
    return 0;
}