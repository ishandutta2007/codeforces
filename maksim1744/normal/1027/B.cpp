/*
    25.08.2018 14:13:19
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
        long long n, q;
        cin >> n >> q;
        for (int i = 0; i < q; ++i)
        {
            long long x, y;
            cin >> x >> y;
            x--; y--;
            long long ans = 0;
            if ((x + y) % 2 == 0) {
                ans += x * (n / 2ll);
                if (n % 2 == 1) {
                    ans += (x + 1) / 2;
                }
                if (x % 2 == 0) {
                    ans += (y + 1) / 2;
                }
                else {
                    ans += y / 2;
                }
            }
            else {
                ans = (n * n + 1ll) / 2ll;
                ans += x * (n / 2);
                if (n % 2 == 1) {
                    ans += x / 2;
                }
                if (x % 2 == 0) {
                    ans += y / 2;
                }
                else {
                    ans += (y + 1) / 2;
                }
            }
            cout << ans + 1 << endl;
        }
    }
    fclose(stdout);
    return 0;
}