/*
    24.08.2018 14:50:49
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
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        long long n00 = 0, n01 = 0, n10 = 0, n11 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == '1') {
                if (b[i] == '1') {
                    n11++;
                }
                else {
                    n10++;
                }
            }
            else {
                if (b[i] == '1') {
                    n01++;
                }
                else {
                    n00++;
                }
            }
        }
        long long ans = (n11 + n10) * n00 + n01 * n10;
        cout << ans << endl;
    }
    fclose(stdout);
    return 0;
}