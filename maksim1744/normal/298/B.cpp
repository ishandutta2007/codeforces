/*
    13.05.2018 14:26:48
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
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        string s;
        cin >> s;
        char c1 = '-', c2 = '-';
        int n1 = 0, n2 = 0;
        if (x2 > x1) {
            c1 = 'E';
            n1 = x2 - x1;
        }
        if (x2 < x1) {
            c1 = 'W';
            n1 = x1 - x2;
        }
        if (y2 > y1) {
            c2 = 'N';
            n2 = y2 - y1;
        }
        if (y2 < y1) {
            c2 = 'S';
            n2 = y1 - y2;
        }
        int cnt1 = 0, cnt2 = 0, i1 = -1, i2 = -1;
        for (int i = 0; i < t; ++i)
        {
            if (s[i] == c1) {
                cnt1++;
                if (cnt1 == n1) {
                    i1 = i;
                }
            }
            if (s[i] == c2) {
                cnt2++;
                if (cnt2 == n2) {
                    i2 = i;
                }
            }
        }
        if (cnt1 < n1 || cnt2 < n2) {
            cout << -1 << endl;
        }
        else {
            cout << max(i1, i2) + 1 << endl;
        }
    }
    fclose(stdout);
    return 0;
}