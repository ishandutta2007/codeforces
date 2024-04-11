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
        vector< long long > a0(14);
        for (int i = 0; i < 14; ++i)
        {
            cin >> a0[i];
        }
        long long mx = 0;
        for (int i = 0; i < 14; ++i)
        {
            vector< long long > a = a0;
            long long score = 0;
            long long s = a[i];
            a[i] = 0;
            for (int j = 0; j < 14; ++j)
            {
                a[j] += s / 14;
            }
            for (int j = 0; j < s % 14; ++j)
            {
                a[(i + j + 1) % 14]++;
            }
            for (int j = 0; j < 14; ++j)
            {
                if (a[j] % 2 == 0) {
                    score += a[j];
                }
            }
            mx = max(mx, score);
        }
        cout << mx << '\n';
    }
    fclose(stdout);
    return 0;
}